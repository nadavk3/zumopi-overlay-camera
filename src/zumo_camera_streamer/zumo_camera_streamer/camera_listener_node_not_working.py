import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image, CompressedImage
from geometry_msgs.msg import Point32, Polygon
import cv2
import numpy as np
from pyzbar.pyzbar import decode
from cv_bridge import CvBridge

from zumo_interfaces.msg import Rawdata

class CameraListener(Node):

  def __init__(self):
    super().__init__('camera_listener')

    self.subscription = self.create_subscription(
      CompressedImage,
      'video_frames',
      self.listener_callback,
      2)
    self.br = CvBridge()

    self.publisher = self.create_publisher(Rawdata, 'location_rawdata', 10)
    self.debug_publisher = self.create_publisher(CompressedImage, 'debug_frames', 10)

  # def decode_frame_qr(self, frame):
  #   qrcode_polygon = None
  #
  #   code = decode(frame)
  #   for barcode in code:
  #     myData = barcode.data.decode('utf-8')
  #     pts = np.array([barcode.polygon], np.int32)
  #     qrcode_polygon = Polygon(np.squeeze(pts))
  #     pts = pts.reshape((-1, 1, 2))
  #     ptr_str = np.array2string(pts)
  #     cv2.polylines(frame, [pts], True, (255, 0, 225), 5)
  #     pts2 = barcode.rect
  #     cv2.putText(frame, myData, (pts2[0], pts2[1]), cv2.FONT_HERSHEY_SIMPLEX, 0.9, (255, 0, 255), 2)
  #
  #   gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
  #   edged = cv2.Canny(gray,30,200)
  #   contours, hierarchy = cv2.findContours(edged, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_NONE)
  #   for cnt in contours:
  #     epsilon = 0.02 * cv2.arcLength(cnt,True)
  #     approx = cv2.approxPolyDP(cnt, epsilon, True)
  #     x,y = approx[0][0]
  #
  #     # cv2.drawContours(frame, [approx], 0, (0, 255, 0), 3)
  #     if len(approx) == 4 and cv2.contourArea(cnt) > 20 and qrcode_polygon != None:
  #       cnt_polygon = Polygon(np.squeeze(cnt))
  #       if cnt_polygon.contains(qrcode_polygon):
  #         cv2.drawContours(frame, [cnt], 0, (0, 255, 0), 3)
  #         cv2.putText(frame,"Rectangle", (x,y), cv2.FONT_HERSHEY_COMPLEX, 1 , 0 , 2)
  #         self.get_logger().info("type: %s | QR encode: %s | BB Coordinates:%s" % (barcode.type, myData, list(cnt_polygon.centroid.coords)))
  #
  #   return frame

  def decode_frame_color(self, frame, color_low, color_high, eps, area):
    color_mask = cv2.inRange(frame, color_low, color_high)
    color = cv2.bitwise_and(frame, frame, mask=color_mask)

    gray = cv2.cvtColor(cv2.bitwise_not(color), cv2.COLOR_BGR2GRAY)
    edged = cv2.Canny(gray, 30, 200)
    contours, hierarchy = cv2.findContours(edged, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_NONE)
    rect_list = []

    self.get_logger().info(str(len(contours)))

    for cnt in contours:
      epsilon = eps * cv2.arcLength(cnt, True)
      approx = cv2.approxPolyDP(cnt, epsilon, True)

      if len(approx) > 4 and cv2.contourArea(cnt) > area:
        x, y, w, h = cv2.boundingRect(cnt)
        area = cv2.contourArea(cnt)
        bounding_rect_area = w * h
        if bounding_rect_area > 0:
          aspect_ratio = area / bounding_rect_area
          if aspect_ratio > 0.5 and aspect_ratio < 2:
            rect_list.append((cnt, x, y, w, h))

    return rect_list

  def decode_frame_black(self, frame):
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    _, thresh = cv2.threshold(gray, 0, 255, cv2.THRESH_BINARY_INV)
    contours, _ = cv2.findContours(thresh, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    return contours

  def decode_frame_blue(self, frame):
    low_blue = np.array([120, 80, 50])
    high_blue = np.array([255, 120, 100])

    return self.decode_frame_color(frame, low_blue, high_blue, 0.08, 40)

  def decode_frame_red(self, frame):
    low_red = np.array([60, 60, 120])
    high_red = np.array([90, 90, 255])

    return self.decode_frame_color(frame, low_red, high_red, 0.08, 40)

  def decode_frame_yellow(self, frame):
    low_yellow = np.array([40, 130, 160])
    high_yellow = np.array([120, 170, 220])

    return self.decode_frame_color(frame, low_yellow, high_yellow, 0.08, 40)

  # def decode_frame_black(self, frame):
  #   low_black = np.array([200, 200, 200])
  #   high_black = np.array([255, 255, 255])
  #
  #   return self.decode_frame_color(frame, low_black, high_black, 0.1, 0)

  def create_contours(self, contours_list):
    contour_msg = []
    for contour in contours_list:
      # convert each OpenCV contour to a `sensor_msgs/Contour` message
      polygon_msg = Polygon()
      polygon_msg.points = []  # set the list of points in the contour
      for point in contour:
        # convert each point in the OpenCV contour to a `geometry_msgs/Point32` message
        point_msg = Point32()
        point_msg.x = float(point[0][0])
        point_msg.y = float(point[0][1])
        polygon_msg.points.append(point_msg)
      contour_msg.append(polygon_msg)

    return contour_msg

  def listener_callback(self, data):

    self.get_logger().info('Receiving video frame')
    current_frame = self.br.compressed_imgmsg_to_cv2(data)
    black_list = self.decode_frame_black(current_frame)
    debug_frame = current_frame.copy()
    self.get_logger().info(str(len(black_list)))

    for elem in black_list:

      cnt, x, y, w, h = elem
      # cv2.drawContours(current_frame, [cnt], 0, (0, 255, 0), 3)

      cropped_frame = current_frame[y:y+h, x:x+w]
      red_list = [a[0] for a in self.decode_frame_red(cropped_frame)]
      blue_list = [a[0] for a in self.decode_frame_blue(cropped_frame)]
      yellow_list = [a[0] for a in self.decode_frame_yellow(cropped_frame)]

      black_element = Rawdata()
      black_element.cnt = self.create_contours([cnt])
      black_element.red_list = self.create_contours(red_list)
      black_element.blue_list = self.create_contours(blue_list)
      black_element.yellow_list = self.create_contours(yellow_list)

      self.publisher.publish(black_element)

      debug_frame = cv2.drawContours(debug_frame, [cnt], 0, (0, 255, 0), 3)

    np_frame = np.stack(debug_frame, axis=0)
    img = self.br.cv2_to_compressed_imgmsg(np_frame)
    self.debug_publisher.publish(img)

      # if len(red_list) > 0:
      #   cv2.drawContours(current_frame, red_list, 0, (0, 0, 255), 3)
      # if len(blue_list) > 0:
      #   cv2.drawContours(current_frame, blue_list, 0, (255, 0, 0), 3)
      # if len(yellow_list) > 0:
      #   cv2.drawContours(current_frame, yellow_list, 0, (50, 150, 150), 3)
      #
      # string = str(len(red_list))+str(len(blue_list))+str(len(yellow_list))
      #
      # cv2.putText(current_frame, string, (x, y), cv2.FONT_HERSHEY_COMPLEX, 1, 0, 2)
    #
    # cv2.imshow("camera", current_frame)
    # cv2.waitKey(1)
  
def main(args=None):
  
  rclpy.init(args=args)
  camera_listener = CameraListener()
  rclpy.spin(camera_listener)
  camera_listener.destroy_node()
  
  # Shutdown the ROS client library for Python
  rclpy.shutdown()
  
if __name__ == '__main__':
  main()

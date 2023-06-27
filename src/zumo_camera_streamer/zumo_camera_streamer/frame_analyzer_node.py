import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image, CompressedImage
from geometry_msgs.msg import Point32, Polygon
import cv2
import numpy as np
from pyzbar.pyzbar import decode
from cv_bridge import CvBridge

from zumo_interfaces.msg import Rawdata

class FrameAnalyzer(Node):

  def __init__(self):
    super().__init__('frame_analyzer')

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

  def closest_color(self, center_pixel, colors):
    min_dist = float('inf')
    closest_color = None
    for color_name, color_value in colors.items():
      dist = np.linalg.norm(center_pixel - color_value)
      if dist < min_dist:
        min_dist = dist
        closest_color = color_name

    # Return the name of the closest color
    return closest_color

  def decode_frame_colors(self, frame, new_size):
    orig_h, orig_w, _ = frame.shape
    img = cv2.resize(frame, (new_size, new_size), interpolation=cv2.INTER_AREA)
    colors = {'red': np.array([0, 0, 255]), 'blue': np.array([255, 0, 0]), 'green': np.array([0, 255, 0]),
              'yellow': np.array([0, 255, 255])}
    upper_left = img[int(new_size * 2 / 7), int(new_size * 2 / 7), :]
    upper_right = img[int(new_size * 2 / 7), int(new_size * 5 / 7), :]
    bottom_left = img[int(new_size * 5 / 7), int(new_size * 2 / 7), :]
    bottom_right = img[int(new_size * 5 / 7), int(new_size * 5 / 7), :]

    colors_res = {'red': [], 'blue': [], 'green': [], 'yellow': []}
    upper_left_point = Point32()
    upper_left_point.x = float(orig_w * 2 / 7)
    upper_left_point.y = float(orig_h * 2 / 7)
    upper_right_point = Point32()
    upper_right_point.x = float(orig_w * 5 / 7)
    upper_right_point.y = float(orig_h * 2 / 7)
    bottom_left_point = Point32()
    bottom_left_point.x = float(orig_w * 2 / 7)
    bottom_left_point.y = float(orig_h * 5 / 7)
    bottom_right_point = Point32()
    bottom_right_point.x = float(orig_w * 5 / 7)
    bottom_right_point.y = float(orig_h * 5 / 7)

    colors_res[self.closest_color(upper_left, colors)].append(upper_left_point)
    colors_res[self.closest_color(upper_right, colors)].append(upper_right_point)
    colors_res[self.closest_color(bottom_left, colors)].append(bottom_left_point)
    colors_res[self.closest_color(bottom_right, colors)].append(bottom_right_point)

    return colors_res

  def decode_frame_color(self, frame, color_low, color_high, high_canny, area):
    color_mask = cv2.inRange(frame, color_low, color_high)
    color = cv2.bitwise_and(frame, frame, mask=color_mask)

    gray = cv2.cvtColor(color, cv2.COLOR_BGR2GRAY)
    edged = cv2.Canny(gray, 0, high_canny)
    contours, hierarchy = cv2.findContours(edged, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_NONE)
    rect_list = []

    # self.get_logger().info(str(len(contours)))

    for cnt in contours:
      # epsilon = eps * cv2.arcLength(cnt, True)
      # approx = cv2.approxPolyDP(cnt, epsilon, True)
      x, y, w, h = cv2.boundingRect(cnt)
      bounding_rect_area = w * h
      cnt_area = cv2.contourArea(cnt)
      aspect_ratio = w / h
      if bounding_rect_area > area and (cnt_area/bounding_rect_area) > 0.25:
        self.get_logger().info(str(bounding_rect_area) + " | " + str(cnt_area) + " | " + str(aspect_ratio))
        # aspect_ratio = cnt_area / bounding_rect_area

        # self.get_logger().info(str(len(approx)) + " | " + str(bounding_rect_area) + " | " + str(aspect_ratio))
        # if len(approx) == 4 and w*h > area:


        if 0.75 < aspect_ratio < 1.25:

          # if bounding_rect_area > 0:
          # self.get_logger().info("append")

          # if aspect_ratio > 0.5 and aspect_ratio < 2:
          rect_list.append((cnt, x, y, w, h))

    return rect_list

  def decode_frame_blue(self, frame):
    low_blue = np.array([100, 10, 10])
    high_blue = np.array([255, 100, 70])
    return self.decode_frame_color(frame, low_blue, high_blue, 50, 1500)

  def decode_frame_red(self, frame):
    low_red = np.array([0, 0, 90])
    high_red = np.array([100, 100, 255])
    return self.decode_frame_color(frame, low_red, high_red, 50, 1500)

  def decode_frame_green(self, frame):
    low_green = np.array([0, 0, 90])
    high_green = np.array([100, 100, 255])
    return self.decode_frame_color(frame, low_green, high_green, 50, 1500)

  def decode_frame_yellow(self, frame):
    low_yellow = np.array([70, 170, 170])
    high_yellow = np.array([120, 210, 210])

    return self.decode_frame_color(frame, low_yellow, high_yellow, 50, 1500)

  def decode_frame_black(self, frame):
    low_black = np.array([0, 0, 0])
    high_black = np.array([60, 60, 60])

    return self.decode_frame_color(frame, low_black, high_black, 175, 1000)

  def crop_black_element(self, frame, cnt):
    rect = cv2.minAreaRect(cnt)
    box = np.int0(cv2.boxPoints(rect))

    width = int(rect[1][0])
    height = int(rect[1][1])

    src_pts = box.astype("float32")

    dst_pts = np.array([[0, height - 1],
                        [0, 0],
                        [width - 1, 0],
                        [width - 1, height - 1]], dtype="float32")

    M = cv2.getPerspectiveTransform(src_pts, dst_pts)

    # directly warp the rotated rectangle to get the straightened rectangle
    warped = cv2.warpPerspective(frame, M, (width, height))
    return warped

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

      # cropped_frame = current_frame[y:y+h, x:x+w]
      cropped_frame = self.crop_black_element(current_frame, cnt)
      # red_list = [a[0] for a in self.decode_frame_red(cropped_frame)]
      # blue_list = [a[0] for a in self.decode_frame_blue(cropped_frame)]
      # green_list = [a[0] for a in self.decode_frame_green(cropped_frame)]
      # yellow_list = [a[0] for a in self.decode_frame_yellow(cropped_frame)]

      colors_locations = self.decode_frame_colors(cropped_frame, 49)

      black_element = Rawdata()
      black_element.cnt = self.create_contours([cnt])
      black_element.red_list = colors_locations['red']
      black_element.blue_list = colors_locations['blue']
      black_element.green_list = colors_locations['green']
      black_element.yellow_list = colors_locations['yellow']

      # black_element.red_list = self.create_contours(red_list)
      # black_element.blue_list = self.create_contours(blue_list)
      # black_element.green_list = self.create_contours(green_list)
      # black_element.yellow_list = self.create_contours(yellow_list)

      self.publisher.publish(black_element)

      # if len(red_list) > 0:
      #   cv2.drawContours(debug_frame, red_list, 0, (0, 0, 255), 3)
      # if len(blue_list) > 0:
      #   cv2.drawContours(debug_frame, blue_list, 0, (255, 0, 0), 3)
      # if len(yellow_list) > 0:
      #   cv2.drawContours(debug_frame, yellow_list, 0, (50, 150, 150), 3)

      debug_frame = cv2.drawContours(debug_frame, [cnt], -1, (0, 255, 0), 3)
      # gray = cv2.drawContours(gray, [cnt], -1, (0, 255, 0), 3)

    np_frame = np.stack(debug_frame, axis=0)
    img = self.br.cv2_to_compressed_imgmsg(np_frame)
    self.debug_publisher.publish(img)


      # string = str(len(red_list))+str(len(blue_list))+str(len(yellow_list))
      #
      # cv2.putText(current_frame, string, (x, y), cv2.FONT_HERSHEY_COMPLEX, 1, 0, 2)
    #
    # cv2.imshow("camera", debug_frame)
    # cv2.waitKey(1)
  
def main(args=None):
  
  rclpy.init(args=args)
  frame_analyzer = FrameAnalyzer()
  rclpy.spin(frame_analyzer)
  frame_analyzer.destroy_node()
  
  # Shutdown the ROS client library for Python
  rclpy.shutdown()
  
if __name__ == '__main__':
  main()

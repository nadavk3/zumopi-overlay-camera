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

    for cnt in contours:
      x, y, w, h = cv2.boundingRect(cnt)
      bounding_rect_area = w * h
      cnt_area = cv2.contourArea(cnt)
      aspect_ratio = w / h
      if bounding_rect_area > area and (cnt_area/bounding_rect_area) > 0.25:
        self.get_logger().info(str(bounding_rect_area) + " | " + str(cnt_area) + " | " + str(aspect_ratio))
        if 0.75 < aspect_ratio < 1.25:
          rect_list.append((cnt, x, y, w, h))

    return rect_list

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

      cropped_frame = self.crop_black_element(current_frame, cnt)
      colors_locations = self.decode_frame_colors(cropped_frame, 49)

      black_element = Rawdata()
      black_element.cnt = self.create_contours([cnt])
      black_element.red_list = colors_locations['red']
      black_element.blue_list = colors_locations['blue']
      black_element.green_list = colors_locations['green']
      black_element.yellow_list = colors_locations['yellow']

      self.publisher.publish(black_element)
      debug_frame = cv2.drawContours(debug_frame, [cnt], -1, (0, 255, 0), 3)

    np_frame = np.stack(debug_frame, axis=0)
    img = self.br.cv2_to_compressed_imgmsg(np_frame)
    self.debug_publisher.publish(img)
  
def main(args=None):
  
  rclpy.init(args=args)
  camera_listener = CameraListener()
  rclpy.spin(camera_listener)
  camera_listener.destroy_node()
  
  # Shutdown the ROS client
  rclpy.shutdown()
  
if __name__ == '__main__':
  main()

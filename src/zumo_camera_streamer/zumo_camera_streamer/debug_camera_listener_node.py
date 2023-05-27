import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image, CompressedImage
from geometry_msgs.msg import Point32, Polygon
import cv2
import numpy as np
from pyzbar.pyzbar import decode
from cv_bridge import CvBridge

from zumo_interfaces.msg import Robotlocation

class DebugCameraListener(Node):

  def __init__(self):
    super().__init__('debug_camera_listener')

    self.subscription = self.create_subscription(
      CompressedImage,
      'debug_frames',
      self.listener_callback,
      2)

    self.location_subscription = self.create_subscription(
      Robotlocation,
      'robot_location',
      self.location_listener_callback,
      2)

    self.robots_locations = {}

    self.br = CvBridge()

  def listener_callback(self, data):

    self.get_logger().info('Receiving debug frame')
    current_frame = self.br.compressed_imgmsg_to_cv2(data)

    for robot, location in self.robots_locations.items():
      cv2.putText(current_frame, robot, location, cv2.FONT_HERSHEY_COMPLEX, 1, 0, 2)


    cv2.imshow("camera", current_frame)
    cv2.waitKey(1)

  def location_listener_callback(self, data):

    self.get_logger().info('Receiving debug location data')
    self.robots_locations[data.id] = (data.x, data.y)

def main(args=None):
  
  rclpy.init(args=args)
  debug_camera_listener = DebugCameraListener()
  rclpy.spin(debug_camera_listener)
  debug_camera_listener.destroy_node()
  
  # Shutdown the ROS client
  rclpy.shutdown()
  
if __name__ == '__main__':
  main()

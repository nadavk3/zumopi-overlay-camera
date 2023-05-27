import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image, CompressedImage
import cv2
from cv_bridge import CvBridge
import numpy as np
 
class CameraTalker(Node):

  def __init__(self):
    super().__init__('camera_talker')
    
    self.publisher_ = self.create_publisher(CompressedImage, 'video_frames', 2)
    timer_period = 0.05
    self.timer = self.create_timer(timer_period, self.timer_callback)
    self.cap = cv2.VideoCapture(0)
    self.br = CvBridge()

    if not self.cap.isOpened():
      print('Unable to locate camera at /dev/video0')
      exit(-1)

  def timer_callback(self):
    
    ret, frame = self.cap.read()
          
    if ret:
      np_frame = np.stack(frame, axis=0)
      img = self.br.cv2_to_compressed_imgmsg(np_frame)
      self.publisher_.publish(img)

    self.get_logger().info('video frame pubished')
  
def main(args=None):
  
  rclpy.init(args=args)
  camera_talker = CameraTalker()
  rclpy.spin(camera_talker)
  camera_talker.destroy_node()
  
  rclpy.shutdown()
  
if __name__ == '__main__':
  main()

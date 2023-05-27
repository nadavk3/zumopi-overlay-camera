import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
import cv2
from cv_bridge import CvBridge
 
class CameraTalker(Node):

  def __init__(self):
    super().__init__('camera_talker')
    
    self.publisher_ = self.create_publisher(Image, 'video_frames', 10)
    timer_period = 0.1
    self.timer = self.create_timer(timer_period, self.timer_callback)
    self.cap = cv2.VideoCapture(0)
    self.br = CvBridge()
   
  def timer_callback(self):
    
    ret, frame = self.cap.read()
          
    if ret == True:
      self.publisher_.publish(self.br.cv2_to_imgmsg(frame))

    self.get_logger().info('video frame pubished')
  
def main(args=None):
  
  rclpy.init(args=args)
  camera_talker = CameraTalker()
  rclpy.spin(camera_talker)
  camera_talker.destroy_node()
  
  rclpy.shutdown()
  
if __name__ == '__main__':
  main()

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
import cv2
import numpy as np
from pyzbar.pyzbar import decode
from cv_bridge import CvBridge
from shapely.geometry import Polygon
 
class CameraListener(Node):

  def __init__(self):
    super().__init__('camera_listener')

    self.subscription = self.create_subscription(
      Image,
      'video_frames',
      self.listener_callback,
      100)
    self.subscription

    self.br = CvBridge()

  def process_frame(self, frame, face_cascade):



    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    faces = face_cascade.detectMultiScale(gray, scaleFactor=1.5, minNeighbors=5)
    for (x, y, w, h) in faces:
      color = (255, 0, 0)  # BGR 0-255
      stroke = 2
      end_cord_x = x + w
      end_cord_y = y + h
      cv2.rectangle(frame, (x, y), (end_cord_x, end_cord_y), color, stroke)


    return frame

  def decode_frame(self, frame):
    """low_blue = np.array([29, 86, 6])
    high_blue = np.array([64, 255, 255])
    blue_mask = cv2.inRange(frame, low_blue, high_blue)
    blue = cv2.bitwise_and(frame, frame, mask=blue_mask)
    return blue"""

    qrcode_polygon = None

    code = decode(frame)
    for barcode in code:
      myData = barcode.data.decode('utf-8')
      pts = np.array([barcode.polygon], np.int32)
      qrcode_polygon = Polygon(np.squeeze(pts))
      pts = pts.reshape((-1, 1, 2))
      ptr_str = np.array2string(pts)
      cv2.polylines(frame, [pts], True, (255, 0, 225), 5)
      pts2 = barcode.rect
      cv2.putText(frame, myData, (pts2[0], pts2[1]), cv2.FONT_HERSHEY_SIMPLEX, 0.9, (255, 0, 255), 2)
      self.get_logger().info("type:%s | BB Coordinates:%s | BB encode:%s" % (barcode.type, ptr_str, myData))

    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    edged = cv2.Canny(gray,30,200)
    contours, hierarchy = cv2.findContours(edged, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_NONE)
    for cnt in contours:
      epsilon = 0.02 * cv2.arcLength(cnt,True)
      approx = cv2.approxPolyDP(cnt, epsilon, True)
      x,y = approx[0][0]

      # cv2.drawContours(frame, [approx], 0, (0, 255, 0), 3)
      if len(approx) == 4 and cv2.contourArea(cnt) > 20 and qrcode_polygon != None:
        cnt_polygon = Polygon(np.squeeze(cnt))
        if cnt_polygon.contains(qrcode_polygon):
          cv2.drawContours(frame, [cnt], 0, (0, 255, 0), 3)
          cv2.putText(frame,"Rectangle", (x,y), cv2.FONT_HERSHEY_COMPLEX, 1 , 0 , 2)



    ###

    return frame

  def listener_callback(self, data):

    self.get_logger().info('Receiving video frame')
    current_frame = self.br.imgmsg_to_cv2(data)
    #face_cascade = cv2.CascadeClassifier(cv2.samples.findFile(cv2.data.haarcascades + 'haarcascade_frontalface_default.xml'))
    #current_frame = self.process_frame(current_frame, face_cascade)
    current_frame = self.decode_frame(current_frame)
    cv2.imshow("camera", current_frame)
    cv2.waitKey(1)
  
def main(args=None):
  
  rclpy.init(args=args)
  camera_listener = CameraListener()
  rclpy.spin(camera_listener)
  camera_listener.destroy_node()
  
  # Shutdown the ROS client library for Python
  rclpy.shutdown()
  
if __name__ == '__main__':
  main()

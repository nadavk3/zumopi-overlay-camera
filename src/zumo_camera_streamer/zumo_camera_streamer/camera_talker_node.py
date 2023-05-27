import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image, CompressedImage
from cv_bridge import CvBridge
import numpy as np
from typing import Optional
from vimba import *
import threading
import cv2

global_frame = None

class CameraTalker(Node):

    def __init__(self):
        super().__init__('camera_talker')

        self.publisher_ = self.create_publisher(CompressedImage, 'video_frames', 1)
        timer_period = 0.05
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.br = CvBridge()

    def empty_timer_callback(self):
        pass

    def timer_callback(self):
        # Share frame as global
        global global_frame

        if global_frame is not None:
            f_h, f_w, _ = global_frame.shape
            roi_frame = global_frame[42:1060, 411:1935]
            cmpimg = self.br.cv2_to_compressed_imgmsg(roi_frame)
            self.publisher_.publish(cmpimg)
            self.get_logger().info('video frame pubished')

def get_camera(camera_id: Optional[str]) -> Camera:
    with Vimba.get_instance() as vimba:
        if camera_id:
            try:
                return vimba.get_camera_by_id(camera_id)

            except VimbaCameraError:
                abort('Failed to access Camera \'{}\'. Abort.'.format(camera_id))

        else:
            cams = vimba.get_all_cameras()
            if not cams:
                abort('No Cameras accessible. Abort.')

            return cams[0]

def setup_camera(cam: Camera):
    with cam:
        try:
            cam.AcquisitionFrameRate.set('20')

        except (AttributeError, VimbaFeatureError):
            pass

        # Enable auto exposure time setting if camera supports it
        try:
            cam.ExposureAuto.set('Continuous')

        except (AttributeError, VimbaFeatureError):
            pass

        # Enable white balancing if camera supports it
        try:
            cam.BalanceWhiteAuto.set('Continuous')

        except (AttributeError, VimbaFeatureError):
            pass


        # Try to adjust GeV packet size. This Feature is only available for GigE - Cameras.
        try:
            cam.GVSPAdjustPacketSize.run()

            while not cam.GVSPAdjustPacketSize.is_done():
                pass

        except (AttributeError, VimbaFeatureError):
            pass

        cv_fmts = intersect_pixel_formats(cam.get_pixel_formats(), OPENCV_PIXEL_FORMATS)
        color_fmts = intersect_pixel_formats(cv_fmts, COLOR_PIXEL_FORMATS)

        if color_fmts:
            cam.set_pixel_format(color_fmts[0])

        else:
            mono_fmts = intersect_pixel_formats(cv_fmts, MONO_PIXEL_FORMATS)

            if mono_fmts:
                cam.set_pixel_format(mono_fmts[0])

            else:
                abort('Camera does not support a OpenCV compatible format natively. Abort.')


class Handler:
    def __init__(self):
        self.shutdown_event = threading.Event()

    def __call__(self, cam: Camera, frame: Frame):
        global global_frame

        ENTER_KEY_CODE = 17

        key = cv2.waitKey(1)
        if key == ENTER_KEY_CODE:
            self.shutdown_event.set()
            return

        if frame.get_status() == FrameStatus.Complete:
            global_frame = np.stack(frame.as_opencv_image(), axis=0)
        cam.queue_frame(frame)


def start_acquisition():
    global global_frame

    with Vimba.get_instance():
        with get_camera(None) as cam:

            setup_camera(cam)
            handler = Handler()

            try:
                # Start Streaming with a custom a buffer of 10 Frames (defaults to 5)
                cam.start_streaming(handler=handler, buffer_count=10)
                handler.shutdown_event.wait()

            finally:
                cam.stop_streaming()



def main(args=None):
    rclpy.init(args=args)
    global global_frame
    camera_talker = CameraTalker()
    t1 = threading.Thread(target=rclpy.spin, args=(camera_talker,))
    t1.start()
    start_acquisition()
    t1.join()
    rclpy.shutdown()

if __name__ == '__main__':
    main()

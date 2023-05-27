import rclpy
from rclpy.node import Node
import cv2
import numpy as np
from zumo_interfaces.msg import Rawdata, Robotlocation


class LocationFinder(Node):

    def __init__(self):
        super().__init__('location_finder')

        self.subscription = self.create_subscription(
            Rawdata,
            'location_rawdata',
            self.listener_callback,
            10)

        self.robots_locations = {}

        self.publisher = self.create_publisher(Robotlocation, 'robot_location', 10)

    def decode_contour(self, contour_data):
        points = [(int(point.x), int(point.y)) for point in contour_data.points]
        return cv2.convexHull(np.array(points))

    def decode_rawdata(self, data):
        cnt = self.decode_contour(data.cnt[0])
        return cnt, data.red_list, data.blue_list, data.green_list, data.yellow_list

    def decode_id(self, red_list, blue_list, green_list):
        return str(len(red_list)) + str(len(blue_list)) + str(len(green_list))

    def listener_callback(self, data):

        self.get_logger().info('Receiving rawdata')
        cnt = self.decode_contour(data.cnt[0])
        # cnt, red_list, blue_list, green_list, yellow_list = self.decode_rawdata(data)
        id = self.decode_id(data.red_list, data.blue_list, data.green_list)
        self.get_logger().info(id)

        sum_id = int(id[2]) + int(id[1]) + int(id[0])
        
        if sum_id == 3:
            M = cv2.moments(cnt)
            if M['m00'] != 0:
                cx = int(M['m10']/M['m00'])
                cy = int(M['m01']/M['m00'])
                self.robots_locations[id] = (cx, cy)

            robot_location_msg = Robotlocation()
            robot_location_msg.id = id
            robot_location_msg.x = self.robots_locations[id][0]
            robot_location_msg.y = self.robots_locations[id][1]

            self.publisher.publish(robot_location_msg)
            self.get_logger().info('ID="' + id + '"; Center=' + str(self.robots_locations[id]))


def main(args=None):
    rclpy.init(args=args)
    location_finder = LocationFinder()
    rclpy.spin(location_finder)
    location_finder.destroy_node()

    # Shutdown the ROS client
    rclpy.shutdown()


if __name__ == '__main__':
    main()

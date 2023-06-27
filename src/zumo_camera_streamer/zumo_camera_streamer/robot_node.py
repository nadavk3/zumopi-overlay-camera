import rclpy
from rclpy.node import Node
from zumo_interfaces.msg import Robotlocation


class RobotNode(Node):

    def __init__(self):
        super().__init__('robot_locator')

        self.subscription = self.create_subscription(
            Robotlocation,
            'robot_location',
            self.listener_callback,
            10)

        self.robot_id = 111

    def listener_callback(self, data):

        if int(data.id) == self.robot_id:
            self.get_logger().info('Receiving robot location')
            self.get_logger().info('Center=(' + str(data.x) + ',' + str(data.y) + ')')

def main(args=None):
    rclpy.init(args=args)
    robot_node = RobotNode()
    rclpy.spin(robot_node)
    robot_node.destroy_node()

    # Shutdown the ROS client library for Python
    rclpy.shutdown()

if __name__ == '__main__':
    main()

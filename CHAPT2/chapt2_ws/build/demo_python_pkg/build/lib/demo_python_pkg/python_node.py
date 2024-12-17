import rclpy
from rclpy.node import Node

def main():
    rclpy.init() #
    node = Node('python_node')
    node.get_logger().info('python 节点建立完成')
    rclpy.spin(node)
    rclpy.shutdowm()
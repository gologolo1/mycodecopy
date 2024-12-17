import rclpy
from rclpy.node import Node
from chapt4_interfaces.srv import FaceDetector
import cv2
from ament_index_python.packages import get_package_share_directory
import os
from cv_bridge import CvBridge
import time

class FaceDetectClientNode(Node):
    def __init__(self):
        super().__init__('face_detect_client')
        self.bridge = CvBridge()
        self.client = self.create_client(FaceDetector, '/face_detect')
        
        # 获取默认图像路径
        self.default_image_path = os.path.join(get_package_share_directory('demo_python_service'), 'resource', 'test1.jpg')
        self.image = cv2.imread(self.default_image_path)
        
        # 检查图像是否成功加载
        if self.image is None:
            self.get_logger().error(f"Failed to load image at {self.default_image_path}")
            return

    def send_request(self):
        # 等待服务上线
        while not self.client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info(f'等待服务端上线')

        self.get_logger().info(f'服务端已经上线')
        request = FaceDetector.Request()
        request.image = self.bridge.cv2_to_imgmsg(self.image, encoding="bgr8")

        future = self.client.call_async(request)
        
        def result_callback(result_future):
            response = result_future.result()
            self.get_logger().info(f'接收到响应，共检测到有{response.number}张人脸，耗时{response.use_time}s')
            self.show_response(response)

        future.add_done_callback(result_callback)

        # rclpy.spin_until_future_complete(self, future)
        
        
        # # 获取响应
        # try:
        #     response = future.result()
        #     self.get_logger().info(f'接收到响应 ： 图像中共有：{response.number}张脸, 耗时：{response.use_time}s')
        #     self.show_face_location(response)
        # except Exception as e:
        #     self.get_logger().error(f"Service call failed: {e}")

    def show_face_location(self, response):
        for i in range(response.number):
            top = response.top[i]
            right = response.right[i]
            left = response.left[i]
            bottom = response.bottom[i]
            cv2.rectangle(self.image, (left, top), (right, bottom), (255, 0, 0), 2)
        
        cv2.imshow('Face Detection Result', self.image)
        cv2.waitKey(0)  # 等待按键按下
        cv2.destroyAllWindows()  # 关闭所有OpenCV窗口

def main(args=None):
    rclpy.init(args=args)
    node = FaceDetectClientNode()
    node.send_request()
    rclpy.spin(node)  # 保持节点运行
    rclpy.shutdown()  # 关闭节点

if __name__ == '__main__':
    main()

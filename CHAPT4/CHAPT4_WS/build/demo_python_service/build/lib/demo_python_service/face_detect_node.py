import rclpy
from rclpy.node import Node
from chapt4_interfaces.srv import FaceDetector
import face_recognition
import cv2
from ament_index_python.packages import get_package_share_directory
import os
from cv_bridge import CvBridge
import time
from rcl_interfaces.msg import SetParametersResult

class FaceDetectNode(Node):
    def __init__(self):
        super().__init__('face_detect_node')
        # 创建服务
        self.services_ = self.create_service(FaceDetector, 'face_detect', self.detect_face_callback)
        self.bridge = CvBridge()
        self.declare_parameter('number_of_times_to_upsample',1)
        self.declare_parameter('model','hog')
        self.number_of_times_to_upsample = self.get_parameter('number_of_times_to_upsample').value      
        self.model = self.get_parameter('model').value
        self.add_on_set_parameters_callback(self.parameter_callback)
        # 获取默认图像路径
        self.default_image_path = os.path.join(get_package_share_directory('demo_python_service'), 'resource', 'default.jpg')
        if not os.path.exists(self.default_image_path):
            self.get_logger().error(f"默认图像文件不存在：{self.default_image_path}")
        else:
            self.get_logger().info(f"默认图像路径：{self.default_image_path}")

    def parameter_callback(self,paramters):
        for paramter in paramters:
            self.get_logger().info(f"{paramter.name}->{paramter.value}")
            if paramter.name == 'number_of_times_to_upsample':
                self.number_of_times_to_upsample = paramter.value
            if paramter.name == 'model':
                self.model = paramter.value 
        return SetParametersResult(successful=True) 

    def detect_face_callback(self, request, response):
        # 检查是否传入图像数据
        if request.image.data:
            try:
                # 将ROS消息转为OpenCV图像
                cv_image = self.bridge.imgmsg_to_cv2(request.image, desired_encoding='bgr8')
                self.get_logger().info(f"成功接收图像")
            except Exception as e:
                self.get_logger().error(f"图像转换失败: {str(e)}")
                response.number = 0
                return response
        else:
            # 使用默认图像
            self.get_logger().info("请求中没有图像数据，使用默认图像")
            cv_image = cv2.imread(self.default_image_path)
            if cv_image is None:
                self.get_logger().error("无法加载默认图像")
                response.number = 0
                return response

        # 处理图像，检测人脸
        start_time = time.time()
        self.get_logger().info(f"加载图像完成，开始人脸检测")
        face_locations = face_recognition.face_locations(cv_image, number_of_times_to_upsample=self.number_of_times_to_upsample, model=self.model)

        # 填充响应
        response.use_time = time.time() - start_time
        response.number = len(face_locations)
        self.get_logger().info(f"识别完成，耗时{response.use_time}!")
        for top, right, bottom, left in face_locations:
            response.top.append(top)
            response.right.append(right)
            response.bottom.append(bottom)
            response.left.append(left)
            cv2.rectangle(cv_image,(left,top),(right,bottom),(255,0,0),4)
        cv2.imshow('Face Detecte Result',cv_image)
        cv2.waitKey(0)

        # 返回响应
        return response

def main():
    rclpy.init()
    node = FaceDetectNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()

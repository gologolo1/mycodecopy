import rclpy 
from rclpy.node import Node

class PersonNode(Node):
    def __init__(self,node_name: str,name_vlaue: str,age_value: int) -> None:
        super().__init__(node_name)
        self.name = name_vlaue
        self.age = age_value

    def eat(self,food_name: str):
        # print(f"{self.name},{self.age}岁,爱吃{food_name}")
        self.get_logger().info(f"{self.name},{self.age}岁,爱吃{food_name}")

def main():
    rclpy.init()
    node =  PersonNode('adasd','唧唧复唧唧',18 )   
    node.eat('鱼香肉丝')
    rclpy.spin(node)
    rclpy.shutdowm()
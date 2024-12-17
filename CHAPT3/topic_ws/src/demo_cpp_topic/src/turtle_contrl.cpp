#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "turtlesim/msg/pose.hpp"

using namespace std::chrono_literals;

class TurtleContrlNode: public rclcpp::Node
{
    private:

        rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
        rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr subscriber_;
        double target_x_{0.0};
        double target_y_{0.0};
        double k_{1.0};
        double max_speed_{3.0};

    public:
        explicit TurtleContrlNode(const std::string& node_name):Node(node_name)
        {
            publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("/turtle1/cmd_vel",10);
            subscriber_ = this->create_subscription<turtlesim::msg::Pose>("/turtle1/pose",10,std::bind(&
            TurtleContrlNode::on_pose_recevived_,this,std::placeholders::_1));
        };

    void on_pose_recevived_(const turtlesim::msg::Pose::SharedPtr pose)
    {
        //1.获取当前的位置
        auto current_x = pose->x;
        auto current_y = pose->y;
        RCLCPP_INFO(get_logger(),"当前x=%f,y=%f",current_x,current_y);

        //2.计算当前海龟位置跟目标位置之间的距离差和角度差
        auto distancs = std::sqrt(
            (target_x_ - current_x)*(target_x_ - current_x)+
            (target_y_ - current_y)*(target_y_ - current_y)
        );
        auto angle = std::atan2((target_y_ - current_y),(target_x_ - current_x))-pose->theta;

        //3.控制策略
        auto msg = geometry_msgs::msg::Twist();
        if(distancs>0.1){
            if(fabs(angle)>0.2)
            {
                msg.angular.z = fabs(angle);
            }
            else
            {
                msg.linear.x = k_ * distancs;
            }
            RCLCPP_INFO(get_logger(),"当前x=%f,y=%f,angle=%f,msg.angular.z=%f,pose->theta=%f",current_x,current_y,fabs(angle),msg.angular.z,pose->theta);
        }

        //4.限制线速度最大值
        if(msg.linear.x > max_speed_){
            msg.linear.x = max_speed_;
        }

        publisher_->publish(msg);
    }
};

int main (int argc, char* argv[])
{
    rclcpp::init(argc,argv);
    auto node = std::make_shared<TurtleContrlNode>("turtle_contrl");
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
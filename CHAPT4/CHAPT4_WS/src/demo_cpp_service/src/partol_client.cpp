#include "rclcpp/rclcpp.hpp"
#include "chapt4_interfaces/srv/partol.hpp"
#include <chrono>
using Partol = chapt4_interfaces::srv::Partol;
using namespace std::chrono_literals;

class PartolClient: public rclcpp::Node
{
public:
    PartolClient() : Node("partol_ctrl")
    {
        
        partol_client_ = this->create_client<Partol>("partol");
        timer_ = this->create_wall_timer(10s,std::bind(&PartolClient::timer_callback,this));
        srand(time(NULL));
    }
void timer_callback()
{
    while (!partol_client_->wait_for_service(std::chrono::seconds(1)))
            {
                if(!rclcpp::ok())
                {
                    RCLCPP_ERROR(this->get_logger(),"等待服务上线中rclcpp失效");
                    return;
                }
                RCLCPP_INFO(this->get_logger(),"等待服务上线中......");
                
            }
            auto request = std::make_shared<Partol::Request>();
            request->target_x = rand() % 15;
            request->target_y = rand() % 15;
            RCLCPP_INFO(this->get_logger(),"准备好目标点%d,%d,",request->target_x,request->target_y);

            partol_client_->async_send_request(
                request,
                [&](rclcpp::Client<Partol>::SharedFuture result_future)->void{
                auto response = result_future.get();
                if(response->result == Partol::Response::SUCCESS)
                {
                    RCLCPP_INFO(this->get_logger(),"请求目标点成功");
                }
                if(response->result == Partol::Response::FAIL)
                {
                    RCLCPP_INFO(this->get_logger(),"请求目标点失败");
                }
            });
}
private:
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Client<Partol>::SharedPtr partol_client_;

};

int main (int argc, char* argv[])
{
    rclcpp::init(argc,argv);
    auto node = std::make_shared<PartolClient>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
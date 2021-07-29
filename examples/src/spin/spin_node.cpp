/**
 * @file spin_node.cpp
 * @author  Jared J Beard <jbeard6@mix.wvu.edu>
 * @version 1.0
 *
 * @section DESCRIPTION
 *
 * This is an example script for ROS2 spin
 */

#include <chrono>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;
using std::placeholders::_1;

// TODO: make code publish more randomly, let spin queue up and empty itself based on queue size

class SpinNode : public rclcpp::Node
{
public:
    SpinNode() : Node("spin_node")
    {
        timer_ = this->create_wall_timer(500ms, std::bind(&SpinNode::timer_callback, this));
        pub_ = this->create_publisher<std_msgs::msg::String>("chatter", 1);

        sub_ = this->create_subscription<std_msgs::msg::String>(
            "chatter", 1, std::bind(&SpinNode::chatter_callback, this, _1));
    }

private:
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr pub_;

    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr sub_;

    void timer_callback()
    {
        RCLCPP_INFO(this->get_logger(), "I print regularly");
        std_msgs::msg::String my_str;
        my_str.data = "I get received as I am published";
        pub_->publish(my_str);
    }

    void chatter_callback(const std_msgs::msg::String::SharedPtr msg) const
    {
        RCLCPP_INFO_STREAM(this->get_logger(), msg->data.c_str());
    }
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<SpinNode>());
    rclcpp::shutdown();
    return 0;
}
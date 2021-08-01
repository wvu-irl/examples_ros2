/**
 * @file log_in_class_node.cpp
 * @author  Jared J Beard <jbeard6@mix.wvu.edu>
 * @version 1.0
 *
 * @section DESCRIPTION
 *
 * This is an example script for using ROS2 logging in a Node class
 */

#include <chrono>

#include "rclcpp/rclcpp.hpp"

using namespace std::chrono_literals;

class LogNode : public rclcpp::Node
{
public:
    LogNode() : Node("log_in_class_node")
    {
        timer_ = this->create_wall_timer(500ms, std::bind(&LogNode::timer_callback, this));
    }

private:
    rclcpp::TimerBase::SharedPtr timer_;

    void timer_callback()
    {
        RCLCPP_INFO(this->get_logger(), "This is an example of a logger in a class");
    }
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<LogNode>());
    rclcpp::shutdown();
    return 0;
}
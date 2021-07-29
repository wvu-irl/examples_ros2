/**
 * @file log_throttle_node.cpp
 * @author  Jared J Beard <jbeard6@mix.wvu.edu>
 * @version 1.0
 *
 * @section DESCRIPTION
 *
 * This is an example script for using ROS2 throttle logging
 */
#include <chrono>

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"

using namespace std::chrono_literals;

class LogNode : public rclcpp::Node
{
public:
    LogNode() : Node("log_throttle_node")
    {
        timer_ = this->create_wall_timer(500ms, std::bind(&LogNode::timer_callback, this));
        clock_ = rclcpp::Clock();
    }

private:
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Clock clock_;

    void timer_callback()
    {
        RCLCPP_INFO(this->get_logger(), "I publish every time");
        RCLCPP_INFO_THROTTLE(this->get_logger(), clock_, 1000, "This is a 500 ms wall timer, but the message only publishes at 1 Hz");
    }
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);

    rclcpp::executors::SingleThreadedExecutor executor;
    std::shared_ptr<rclcpp::Node> log_node = std::make_shared<LogNode>();
    executor.add_node(log_node);
    executor.spin();

    RCLCPP_INFO(log_node->get_logger(), "Throttle also has a SKIPFIRST_THROTTLE option");

    rclcpp::shutdown();
    return 0;
}
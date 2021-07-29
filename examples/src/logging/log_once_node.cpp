/**
 * @file log_in_class_node.cpp
 * @author  Jared J Beard <jbeard6@mix.wvu.edu>
 * @version 1.0
 *
 * @section DESCRIPTION
 *
 * This is an example script for using ROS2 logging for log once
 */

#include "rclcpp/rclcpp.hpp"

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);

    rclcpp::Node log_node("log_once_node");

    int i = 1;
    while (i <= 3)
    {
        RCLCPP_INFO_ONCE(log_node.get_logger(), "I only get published once, count: %i", i);
        ++i;
    }

    RCLCPP_INFO_ONCE(log_node.get_logger(), "But I don't (or do I?)");
    RCLCPP_INFO_ONCE(log_node.get_logger(), "But I don't (or do I?)");

    rclcpp::shutdown();
    return 0;
}
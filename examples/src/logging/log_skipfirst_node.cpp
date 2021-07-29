/**
 * @file log_skipfirst_node.cpp
 * @author  Jared J Beard <jbeard6@mix.wvu.edu>
 * @version 1.0
 *
 * @section DESCRIPTION
 *
 * This is an example script for using ROS2 logging for log skip first
 */

#include "rclcpp/rclcpp.hpp"

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);

    rclcpp::Node log_node("log_skipfirst_node");

    int i = 1;
    while (i <= 3)
    {
        RCLCPP_INFO_SKIPFIRST(log_node.get_logger(), "I don't get published the first time; count: %i", i);
        ++i;
    }

    RCLCPP_INFO_SKIPFIRST(log_node.get_logger(), "Neither do we");
    RCLCPP_INFO_SKIPFIRST(log_node.get_logger(), "Neither do we");

    rclcpp::shutdown();
    return 0;
}
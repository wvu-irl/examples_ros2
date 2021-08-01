/**
 * @file log_in_main_node.cpp
 * @author  Jared J Beard <jbeard6@mix.wvu.edu>
 * @version 1.0
 *
 * @section DESCRIPTION
 *
 * This is an example script for using ROS2 logging in main
 */

#include "rclcpp/rclcpp.hpp"

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);

    rclcpp::Node log_node("log_in_main_node");

    RCLCPP_INFO(log_node.get_logger(), "This is an example of a logger in main");

    rclcpp::shutdown();
    return 0;
}
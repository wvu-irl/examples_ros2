/**
 * @file log_in_class_node.cpp
 * @author  Jared J Beard <jbeard6@mix.wvu.edu>
 * @version 1.0
 *
 * @section DESCRIPTION
 *
 * This is an example script for using ROS2 logging using expressions
 */

#include "rclcpp/rclcpp.hpp"

bool a_true_function()
{
    return true;
}

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);

    rclcpp::Node log_node("log_in_class_node");

    RCLCPP_INFO_EXPRESSION(log_node.get_logger(), 2 + 2 == 4, "This is expression is true");

    RCLCPP_INFO_EXPRESSION(log_node.get_logger(), a_true_function(), "This is function returns true");

    RCLCPP_INFO_EXPRESSION(log_node.get_logger(), false, "This is bool is false and won't get published");

    bool a_bool = true;
    RCLCPP_INFO_EXPRESSION(log_node.get_logger(), a_bool, "This is bool is true");


    rclcpp::shutdown();
    return 0;
}
/**
 * @file log_in_class_node.cpp
 * @author  Jared J Beard <jbeard6@mix.wvu.edu>
 * @version 1.0
 *
 * @section DESCRIPTION
 *
 * This is an example script for using ROS2 logging, here we demonstrate severity, as well as flags
 */

#include <string>

#include "rclcpp/rclcpp.hpp"

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);

    rclcpp::Node log_node("log_sev_flags_node");

    RCLCPP_DEBUG(log_node.get_logger(), "This is an example of a log message at severity DEBUG");

    RCLCPP_INFO(log_node.get_logger(), "This is an example of a log message at severity INFO");

    RCLCPP_WARN(log_node.get_logger(), "This is an example of a log message at severity WARN");

    RCLCPP_ERROR(log_node.get_logger(), "This is an example of a log message at severity ERROR");

    RCLCPP_FATAL(log_node.get_logger(), "This is an example of a log message at severity FATAL");


    RCLCPP_WARN(log_node.get_logger(), "ROS2 uses loggers use printf flags");


    bool a_bool = true;
    RCLCPP_INFO(log_node.get_logger(), "This is an example of a log message with a bool flag: %i", a_bool);

    int an_int = 5;
    RCLCPP_INFO(log_node.get_logger(), "This is an example of a log message with an int flag: %i", an_int);

    double an_double = 10.0;
    RCLCPP_INFO(log_node.get_logger(), "This is an example of a log message with an float or double flag: %f", an_double);

    char a_char = 'h';
    RCLCPP_INFO(log_node.get_logger(), "This is an example of a log message with a char flag: %c", a_char);

    std::string a_string = "the string";
    RCLCPP_INFO(log_node.get_logger(), "This is an example of a log message with a string flag: %s", a_string.c_str());

    RCLCPP_INFO(log_node.get_logger(), "This is an example of a log message with an int flag: %d and a string flag: %s", an_int, a_string.c_str());

    

    rclcpp::shutdown();
    return 0;
}
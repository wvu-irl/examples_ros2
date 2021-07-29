/**
 * @file log_stream_node.cpp
 * @author  Jared J Beard <jbeard6@mix.wvu.edu>
 * @version 1.0
 *
 * @section DESCRIPTION
 *
 * This is an example script for using ROS2 stream logging
 */

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);

    rclcpp::Node log_node("log_stream_node");


    RCLCPP_INFO_STREAM(log_node.get_logger(), "I function like cout, as you can see I have more than " << 1 << "input type using the << operator");

    // Apparently ROS2 doesn't support message logging...?
    // geometry_msgs::msg::Twist temp;
    // temp.linear.x = 1;
    // RCLCPP_INFO_STREAM(log_node.get_logger(), "I can output messages such as this geometry_msgs twist"); 
    // RCLCPP_INFO_STREAM(log_node.get_logger(), temp);

    RCLCPP_INFO_STREAM(log_node.get_logger(), "I also have STREAM_ONCE, STREAM_EXPRESSION, STREAM_FUNCTION, STREAM_SKIPFIRST, STREAM_THROTTLE, AND STREAM_SKIPFIRST_THROTTLE options");

    rclcpp::shutdown();
    return 0;
}
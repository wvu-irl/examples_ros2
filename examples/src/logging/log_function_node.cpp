/**
 * @file log_in_class_node.cpp
 * @author  Jared J Beard <jbeard6@mix.wvu.edu>
 * @version 1.0
 *
 * @section DESCRIPTION
 *
 * This is an example script for using ROS2 logging in main
 */

#include "rclcpp/rclcpp.hpp"


// TODO: Try to make work for non-static member functions of struct/class

int a_true_function()
{
    return 1;
}

bool a_false_function()
{
    return false;
}

bool a_variable_function(bool _bool)
{
    return _bool;
}

class MyClass
{
public:
    rclcpp::Node *node_ptr_;
    bool struct_bool = true;

    MyClass(rclcpp::Node *_node_ptr) : node_ptr_(_node_ptr){};

    static bool static_class_function()
    {
        return true;
    }

    void static_log()
    {
        RCLCPP_INFO_FUNCTION(node_ptr_->get_logger(), static_class_function, "This function depends on a static member of a class");
    }
};

bool global_bool = false;

bool global_function()
{
    return global_bool;
}

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);

    rclcpp::Node log_node("log_function_node");

    RCLCPP_INFO_FUNCTION(log_node.get_logger(), a_true_function, "This function was true");

    RCLCPP_INFO_FUNCTION(log_node.get_logger(), a_false_function, "This function was false");

    MyClass my_class(&log_node);

    my_class.static_log();

    int (*a_function)();
    a_function = &a_true_function;
    RCLCPP_INFO_FUNCTION(log_node.get_logger(), *a_function, "This function pointer was true");

    RCLCPP_INFO_FUNCTION(log_node.get_logger(), global_function, "This global function was false");

    global_bool = true;
    RCLCPP_INFO_FUNCTION(log_node.get_logger(), global_function, "This global function was true");

    rclcpp::shutdown();
    return 0;
}
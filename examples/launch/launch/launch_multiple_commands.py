import os
from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory


def generate_launch_description():
    ld = LaunchDescription()

    robot1_global_parameters = os.path.join(
        get_package_share_directory('my_robot_bringup'),
        'config',
        'robot1_global_params.yaml'
    )

    robot2_global_parameters = os.path.join(
        get_package_share_directory('my_robot_bringup'),
        'config',
        'robot2_global_params.yaml'
    )

    global_param_node_robot1 = Node(
        node_namespace='/robot1',
        package='my_robot_bringup',
        executable='global_parameter_server',
        name='global_parameter_server',
        parameters=[robot1_global_parameters]
    )

    global_param_node_robot2 = Node(
        node_namespace='/robot2',
        package='my_robot_bringup',
        executable='global_parameter_server',
        name='global_parameter_server',
        parameters=[robot2_global_parameters]
    )

    ld.add_action(global_param_node_robot1)
    ld.add_action(global_param_node_robot2)
    return ld

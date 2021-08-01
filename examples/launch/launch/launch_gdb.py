import os
from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory

# https://navigation.ros.org/tutorials/docs/get_backtrace.html
def generate_launch_description():
    ld = LaunchDescription()

    start_sync_slam_toolbox_node = Node(
    parameters=[
      get_package_share_directory("slam_toolbox") + '/config/mapper_params_online_sync.yaml',
      {'use_sim_time': use_sim_time}
    ],
    package='slam_toolbox',
    executable='sync_slam_toolbox_node',
    name='slam_toolbox',
    prefix=['xterm -e gdb -ex run --args'],
    output='screen')

    ld.add_action(start_sync_slam_toolbox_node)
    return ld



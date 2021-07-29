cmake_minimum_required(VERSION 3.5)
project(examples)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(std_msgs REQUIRED)


# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

############ LOGGING EXAMPLES ########################
add_executable(log_in_class_node src/logging/log_in_class_node.cpp)
ament_target_dependencies(log_in_class_node rclcpp)

add_executable(log_in_main_node src/logging/log_in_main_node.cpp)
ament_target_dependencies(log_in_main_node rclcpp)

add_executable(log_severity_and_flags_node src/logging/log_severity_and_flags_node.cpp)
ament_target_dependencies(log_severity_and_flags_node rclcpp)

add_executable(log_expression_node src/logging/log_expression_node.cpp)
ament_target_dependencies(log_expression_node rclcpp)

add_executable(log_once_node src/logging/log_once_node.cpp)
ament_target_dependencies(log_once_node rclcpp)

add_executable(log_skipfirst_node src/logging/log_skipfirst_node.cpp)
ament_target_dependencies(log_skipfirst_node rclcpp)

add_executable(log_function_node src/logging/log_function_node.cpp)
ament_target_dependencies(log_function_node rclcpp)

add_executable(log_stream_node src/logging/log_stream_node.cpp)
ament_target_dependencies(log_stream_node rclcpp geometry_msgs)

add_executable(log_throttle_node src/logging/log_throttle_node.cpp)
ament_target_dependencies(log_throttle_node rclcpp)

install(TARGETS
  log_in_class_node
  log_in_main_node
  log_severity_and_flags_node
  log_expression_node
  log_once_node
  log_skipfirst_node
  log_function_node
  log_stream_node
  log_throttle_node
  DESTINATION lib/${PROJECT_NAME})

############ MULTITHREADED EXAMPLES ########################


############ NODES EXAMPLES ########################


############ PARAM EXAMPLES ########################


############ SPIN EXAMPLES ########################
add_executable(spin_node src/spin/spin_node.cpp)
ament_target_dependencies(spin_node rclcpp std_msgs)

install(TARGETS
  spin_node
  DESTINATION lib/${PROJECT_NAME})


ament_package()

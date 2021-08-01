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
add_executable(log_in_class src/logging/log_in_class.cpp)
ament_target_dependencies(log_in_class rclcpp)

add_executable(log_in_main src/logging/log_in_main.cpp)
ament_target_dependencies(log_in_main rclcpp)

add_executable(log_severity_and_flags src/logging/log_severity_and_flags.cpp)
ament_target_dependencies(log_severity_and_flags rclcpp)

add_executable(log_expression src/logging/log_expression.cpp)
ament_target_dependencies(log_expression rclcpp)

add_executable(log_once src/logging/log_once.cpp)
ament_target_dependencies(log_once rclcpp)

add_executable(log_skipfirst src/logging/log_skipfirst.cpp)
ament_target_dependencies(log_skipfirst rclcpp)

add_executable(log_function src/logging/log_function.cpp)
ament_target_dependencies(log_function rclcpp)

add_executable(log_stream src/logging/log_stream.cpp)
ament_target_dependencies(log_stream rclcpp geometry_msgs)

add_executable(log_throttle src/logging/log_throttle.cpp)
ament_target_dependencies(log_throttle rclcpp)

install(TARGETS
  log_in_class
  log_in_main
  log_severity_and_flags
  log_expression
  log_once
  log_skipfirst
  log_function
  log_stream
  log_throttle
  DESTINATION lib/${PROJECT_NAME})

############ EXECUTOR EXAMPLES ########################


############ NODES EXAMPLES ########################


############ PARAM EXAMPLES ########################


############ SPIN EXAMPLES ########################
add_executable(spin_once src/spin/spin_once.cpp)
ament_target_dependencies(spin_once rclcpp std_msgs)

install(TARGETS
  spin_once
  DESTINATION lib/${PROJECT_NAME})


ament_package()

cmake_minimum_required(VERSION 3.0.2)
project(node_example)

# Find the necessary ROS packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)

# Declare a catkin package
catkin_package()

# Include the directories for the catkin package
include_directories(
  ${catkin_INCLUDE_DIRS}
)

# Add the executable
add_executable(node_test src/node_test.cpp)

# Link the executable with the required ROS libraries
target_link_libraries(node_test
  ${catkin_LIBRARIES}
)

# Make sure dependencies are correctly handled
add_dependencies(node_test ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
cmake_minimum_required(VERSION 3.0.2)
project(rosbagtobin)
set( CMAKE_CXX_STANDARD 14)
# add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  nav_msgs
  pcl_conversions
  pcl_ros
  roscpp
  sensor_msgs
  std_msgs
)
find_package(PCL REQUIRED)
catkin_package(
# INCLUDE_DIRS include
#  LIBRARIES read_rosbag
# CATKIN_DEPENDS nav_msgs pcl_conversions pcl_ros roscpp sensor_msgs std_msgs
# DEPENDS system_lib
)
include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(${PROJECT_NAME} src/rosbagtobin.cpp)
target_link_libraries(${PROJECT_NAME}
  ${catkin_LIBRARIES} ${PCL_LIBRARIES}
)



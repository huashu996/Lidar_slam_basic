cmake_minimum_required(VERSION 3.0.2)
project(pcd)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  pcl_conversions
  pcl_msgs
  pcl_ros
  sensor_msgs
)
catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES my_image_transport
#  CATKIN_DEPENDS cv_bridge image_transport sensor_msgs
#  DEPENDS system_lib
)
find_package(PCL REQUIRED)
include_directories(include ${catkin_INCLUDE_DIRS} ${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_executable(read_pcd src/read_pcd.cpp)
target_link_libraries(read_pcd ${catkin_LIBRARIES} ${PCL_LIBRARIES})


cmake_minimum_required(VERSION 2.8.3)
project(programprojekt)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS roscpp genmsg geometry_msgs)

add_message_files(FILES direction.msg)

generate_messages(DEPENDENCIES std_msgs)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES programprojekt
#  CATKIN_DEPENDS other_catkin_pkg
#  DEPENDS system_lib
)


## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
# include
${catkin_INCLUDE_DIRS}
)

add_executable(${PROJECT_NAME}_interface src/interface.cpp)
add_dependencies(${PROJECT_NAME}_interface ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(${PROJECT_NAME}_interface
${catkin_LIBRARIES}
)
add_executable(${PROJECT_NAME}_calculation src/calculation.cpp)
add_dependencies(${PROJECT_NAME}_calculation ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(${PROJECT_NAME}_calculation
${catkin_LIBRARIES}
)
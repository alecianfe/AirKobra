cmake_minimum_required(VERSION 2.8.3)
project(fake_r2p)

## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS
  roscpp
  geometry_msgs
  sensor_msgs
  r2p_msgs
  message_generation
)


# set c++ flags TODO: probabile errore!
set(CMAKE_CXX_FLAGS "-g -std=c++11 ${OTHERS_DEFINE}")

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/modules)

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)


###################################
## catkin specific configuration ##
###################################
catkin_package(CATKIN_DEPENDS   
  geometry_msgs
  sensor_msgs
  r2p_msgs
  message_runtime)

###########
## Build ##
###########

include_directories(include
  ${Boost_INCLUDE_DIRS}
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable (fake_r2p_node
	src/main.cpp
	src/fake_r2p.cpp
)

target_link_libraries(fake_r2p_node
   ${catkin_LIBRARIES}
)


#add dependencies to the messages
add_dependencies(fake_r2p_node ${catkin_EXPORTED_TARGETS})

#############
## Install ##
#############

## Mark executables and/or libraries for installation
install(TARGETS fake_r2p_node
   ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
   LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
   RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

# Install launch files
install(DIRECTORY launch/
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/launch
  PATTERN ".svn" EXCLUDE
)
  

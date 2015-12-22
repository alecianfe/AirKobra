cmake_minimum_required(VERSION 2.8.3)
project(clock)

## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS roscpp vrep_common)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/modules)

# Find other libraries
find_package(Boost  REQUIRED)

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)


###################################
## catkin specific configuration ##
###################################
catkin_package(CATKIN_DEPENDS message_runtime vrep_common)

###########
## Build ##
###########

include_directories(
  ${catkin_INCLUDE_DIRS}
)

# set c++ flags TODO: probabile errore!
set(CMAKE_CXX_FLAGS "-g -std=c++11 ${OTHERS_DEFINE}")

include_directories(include
  ${EIGEN3_INCLUDE_DIR}
  ${Boost_INCLUDE_DIRS}
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable (vrep_clock_remapper
	src/main.cpp
)

target_link_libraries(vrep_clock_remapper
  ${catkin_LIBRARIES}
)

#add dependencies to the messages
add_dependencies(vrep_clock_remapper ${catkin_EXPORTED_TARGETS})


#############
## Install ##
#############

## Mark executables and/or libraries for installation
install(TARGETS vrep_clock_remapper
   ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
   LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
   RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

# Install launch files
install(DIRECTORY launch/
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/launch
  PATTERN ".svn" EXCLUDE
)
  

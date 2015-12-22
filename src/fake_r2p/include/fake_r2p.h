#include <ros/ros.h>
#include <string>
#include <geometry_msgs/Vector3.h>
#include <geometry_msgs/Twist.h>
#include <sensor_msgs/Imu.h>
#include <nav_msgs/Odometry.h>
#include "r2p_msgs/ImuRaw.h"
#include "r2p_msgs/Vector3_32.h"



class fake_r2p{

public:

  ros::NodeHandle n;

  ros::Publisher odom_pub;	
  ros::Publisher imu_pub;

  bool init();

  void run();

  fake_r2p();



};


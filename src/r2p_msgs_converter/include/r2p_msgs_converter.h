#include <ros/ros.h>
#include <string>
#include <geometry_msgs/Vector3.h>
#include <geometry_msgs/Twist.h>
#include <sensor_msgs/Imu.h>
#include <nav_msgs/Odometry.h>
#include "r2p_msgs/ImuRaw.h"
#include "r2p_msgs/Vector3_32.h"



class r2p_msgs_converter{

public:

  ros::NodeHandle n;

  ros::Publisher odom_pub;	
  ros::Publisher imu_pub;
  ros::Subscriber odom_sub;
  ros::Subscriber imu_sub;

  bool init();

  void run();

	void Vector32_to_Vector3(const r2p_msgs::Vector3_32& vector3_32,geometry_msgs::Vector3& vector3);
	
  r2p_msgs_converter();

  void odometry_CB(const geometry_msgs::Vector3& msg);

  void imu_CB(const r2p_msgs::ImuRaw& msg);

  void odometry_R2ptoRos(const geometry_msgs::Vector3& msg,nav_msgs::Odometry& nav_msgs_odometry);

  void imu_R2ptoRos(const r2p_msgs::ImuRaw& msg,sensor_msgs::Imu& sensor_msgs_imu);


};

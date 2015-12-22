#include <ros/ros.h>
#include <r2p_msgs_converter.h>
#include "r2p_msgs/ImuRaw.h"
#include "r2p_msgs/Vector3_32.h"
#include <sstream>




r2p_msgs_converter::r2p_msgs_converter():n("~"){
};


void r2p_msgs_converter::Vector32_to_Vector3(const r2p_msgs::Vector3_32& vector3_32,geometry_msgs::Vector3& vector3){
	vector3.x=(float)vector3_32.x;
	vector3.y=(float)vector3_32.y;
	vector3.z=(float)vector3_32.z;
}


void r2p_msgs_converter::odometry_CB(const geometry_msgs::Vector3& msg){
	nav_msgs::Odometry nav_msgs_odometry;
	odometry_R2ptoRos(msg,nav_msgs_odometry);
	odom_pub.publish(nav_msgs_odometry);
	ROS_INFO("Received Odometry (%f %f %f) and published",msg.x,msg.y,msg.z);
}

void r2p_msgs_converter::imu_CB(const r2p_msgs::ImuRaw& msg){
	sensor_msgs::Imu sensors_msgs_imu;
	imu_R2ptoRos(msg,sensors_msgs_imu);
	imu_pub.publish(sensors_msgs_imu);
	ROS_INFO("Received Imu, angular velocity (%f %f %f)  linear acceleration (%f %f %f) and published",msg.angular_velocity.x,msg.angular_velocity.y,msg.angular_velocity.z,msg.linear_acceleration.x,msg.linear_acceleration.y,msg.linear_acceleration.z);
}

void r2p_msgs_converter::odometry_R2ptoRos(const geometry_msgs::Vector3& msg,nav_msgs::Odometry& nav_msgs_odometry){
	nav_msgs_odometry.twist.twist.linear.x=msg.x;
	nav_msgs_odometry.twist.twist.linear.y=msg.y;
	nav_msgs_odometry.twist.twist.linear.z=msg.z;
}

void r2p_msgs_converter::imu_R2ptoRos(const r2p_msgs::ImuRaw& msg,sensor_msgs::Imu& sensors_msgs_imu){
	Vector32_to_Vector3(msg.angular_velocity,sensors_msgs_imu.angular_velocity);
	Vector32_to_Vector3(msg.linear_acceleration,sensors_msgs_imu.linear_acceleration);
}


bool r2p_msgs_converter::init(){
	odom_pub = n.advertise<nav_msgs::Odometry>("/base_odometry/odom", 1000);
	imu_pub = n.advertise<sensor_msgs::Imu>("/torso_lift_imu/data", 1000);
	odom_sub=n.subscribe("/r2p/odom", 1000, &r2p_msgs_converter::odometry_CB,this);
	imu_sub=n.subscribe("/r2p/imu_raw", 1000, &r2p_msgs_converter::imu_CB,this);
	return true;
}


void r2p_msgs_converter::run(){
	ros::Rate r(25);
	while (ros::ok()){
		ros::spin();
		r.sleep();
  }
}



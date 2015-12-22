#include <ros/ros.h>
#include <fake_r2p.h>
#include "r2p_msgs/ImuRaw.h"
#include "r2p_msgs/Vector3_32.h"
#include <sstream>




fake_r2p::fake_r2p():n("~"){
};


bool fake_r2p::init(){
	odom_pub = n.advertise<geometry_msgs::Vector3>("/r2p/odom", 1000);

	return true;
}


void fake_r2p::run(){
	ros::Rate r(25);
	while (ros::ok()){
			geometry_msgs::Vector3 msg;
	odom_pub.publish(msg);
		ROS_INFO("Pub Odometry (%f %f %f)",msg.x,msg.y,msg.z);
		r.sleep();
  }
}



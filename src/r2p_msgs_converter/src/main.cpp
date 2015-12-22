#include <ros/ros.h>
#include <sstream>
#include <string>
#include <r2p_msgs_converter.h>


int main(int argc, char **argv){
    ros::init(argc, argv, "r2pSensorsConverter_node");

    r2p_msgs_converter node;

    if(node.init()){
        node.run();
    }

  return 0;
}
#include <ros/ros.h>
#include <sstream>
#include <string>
#include <fake_r2p.h>


int main(int argc, char **argv){
    ros::init(argc, argv, "fake_r2p");

    fake_r2p node;

    if(node.init()){
        node.run();
    }

  return 0;
}

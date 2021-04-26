#include <ros/ros.h>
#include "smb_highlevel_controller/smb_highlevel_controller.hpp"

int main(int argc, char **argv)
{
    //select Ros node name
    const std::string nodeName("smb_highlevel_controller");

    //Init Node with its name
    ros::init(argc, argv, nodeName);

    //create node handle
    ros::NodeHandle nh("~");

    //create object node
    smb_highlevel_controller::SmbHighLevelController smc(nh, nodeName);

    ros::spin();
}
#include <ros/ros.h>
#include <string>
#include "set_speed/setSpeedPub.hpp"

int main(int argc, char **argv)
{
    //select Ros node name
    const std::string nodeName("setSpeed_roscpp");

    //Init Node with its name
    ros::init(argc, argv, nodeName);

    //create node handle
    ros::NodeHandle nh("~");

    //create object node
    SetSpeed::SetSpeed setSpeed(nh, nodeName);

    //Select the rate of node execution
    ros::Rate rate(10);

    while(ros::ok())
    {
        double linearX(0.8f);
        double angularZ(0.5f);
        setSpeed.publishMsg(linearX, angularZ);

        //sleep node until next cycle
        rate.sleep();
    }
}
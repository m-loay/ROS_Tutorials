#include <ros/ros.h>
#include <string>
#include <vector>
#include <sensor_msgs/Temperature.h>
#include "ros_package_template/RosPackageTemplatePub.hpp"

int main(int argc, char **argv)
{
    //select Ros node name
    const std::string nodeName("PubNode_roscpp");

    //Init Node with its name
    ros::init(argc, argv, nodeName);

    //create node handle
    ros::NodeHandle nh("~");

    //create object node
    RosPackageTemplatePub::RosPackageTemplatePub rosPackageTemplatePub(nh, nodeName);

    //create Temp table to publish (simulate sensor)
    const std::vector<double> tempTable{20,40,50,34,33,12,55,43};

    //get tempTable size
    const int size(static_cast<int>(tempTable.size()) - 1);

    //create counter
    int counter(0);


    //Select the rate of node execution
    ros::Rate rate(10);

    while(ros::ok())
    {
        int index(counter % size);
        double tempToPublish(tempTable[index]);

        rosPackageTemplatePub.publishMsg(tempToPublish);
        counter ++;

        //sleep node until next cycle
        rate.sleep();
    }
}
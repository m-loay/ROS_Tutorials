#include <ros/ros.h>
#include "ros_package_template/RosPackageTemplate.hpp"

int main(int argc, char** argv)
{
    const std::string nodeName("ros_package_template");
    ros::init(argc, argv, nodeName);
    ros::NodeHandle nodeHandle("~");

    ros_package_template::RosPackageTemplate rosPackageTemplate(nodeHandle, nodeName);

    ros::spin();
    return 0;
}

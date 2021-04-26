#include "ros_package_template/RosPackageTemplatePub.hpp"

// STD
#include <string>

namespace RosPackageTemplatePub 
{
    RosPackageTemplatePub::RosPackageTemplatePub(ros::NodeHandle& nodeHandle, const std::string &nodeName)
    : nodeHandle_(nodeHandle), nodeName_(nodeName)
    {
        if (!readParameters()) 
        {
            ROS_INFO("Topic --> %s", subscriberTopic_.c_str());
            ROS_ERROR("Could not read parameters.");
            ros::requestShutdown();
        }
        // subscriberTopic_ = "/temperature";
        publisher_ = nodeHandle_.advertise<sensor_msgs::Temperature>(subscriberTopic_, 10);
        ROS_INFO("Successfully launched node --> %s.", nodeName_.c_str());
    }

    RosPackageTemplatePub::~RosPackageTemplatePub()
    {
    }

    bool RosPackageTemplatePub::readParameters()
    {
        if (!nodeHandle_.getParam("subscriber_topic", subscriberTopic_)) return false;
        return true;
    }

    void RosPackageTemplatePub::publishMsg(const double temperture)
    {
        sensor_msgs::Temperature tempMsg;
        tempMsg.temperature = temperture;
        publisher_.publish(tempMsg);
    }

} /* namespace */

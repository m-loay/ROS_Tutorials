#include "ros_package_template/RosPackageTemplate.hpp"

// STD
#include <string>

namespace ros_package_template 
{

    RosPackageTemplate::RosPackageTemplate(ros::NodeHandle& nodeHandle, const std::string &nodeName)
    : nodeHandle_(nodeHandle), nodeName_(nodeName)
    {
        if (!readParameters()) 
        {
            ROS_ERROR("Could not read parameters.");
            ros::requestShutdown();
        }
        subscriber_ = nodeHandle_.subscribe(subscriberTopic_, 1, &RosPackageTemplate::topicCallback, this);
        serviceServer_ = nodeHandle_.advertiseService("get_average",&RosPackageTemplate::serviceCallback, this);
        ROS_INFO("Successfully launched node --> %s.", nodeName_.c_str());
    }

    RosPackageTemplate::~RosPackageTemplate()
    {
    }

    bool RosPackageTemplate::readParameters()
    {
        if (!nodeHandle_.getParam("subscriber_topic", subscriberTopic_)) return false;
        return true;
    }

    void RosPackageTemplate::topicCallback(const sensor_msgs::Temperature& message)
    {
        algorithm_.addData(message.temperature);
    }

    bool RosPackageTemplate::serviceCallback(std_srvs::Trigger::Request& request,
                                            std_srvs::Trigger::Response& response)
    {
        response.success = true;
        response.message = "The average is " + std::to_string(algorithm_.getAverage());
        return true;
    }

} /* namespace */

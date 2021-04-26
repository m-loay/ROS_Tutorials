#include"smb_highlevel_controller/smb_highlevel_controller.hpp"

namespace smb_highlevel_controller
{
    SmbHighLevelController::SmbHighLevelController(ros::NodeHandle& nh,  const std::string nodeName)
    :nodeHandle_(nh),nodeName_(nodeName)
    {
        //get node details from yaml config file
        std::string topic;
        int queue_size;
        if((!nodeHandle_.getParam("subscriber_topic",topic)) || (!nodeHandle_.getParam("queue_size",queue_size)))
        {
            ROS_ERROR("Could not find params for node : %s", nodeName.c_str());
        }
        //create subscriber
        subscriber_ = nodeHandle_.subscribe(topic, queue_size, &SmbHighLevelController::LaserCallback, this);

        //Output node status
        ROS_INFO("%s node has launched", nodeName.c_str());
    }

    void SmbHighLevelController::LaserCallback(const sensor_msgs::LaserScan &msg)
    {
        //find the minimum distance 
        auto minElement = std::min_element(msg.ranges.cbegin(), msg.ranges.cend());

        //Output node status
        ROS_INFO_STREAM("Closest distance is " << *minElement);
    }
    
} //smb_highlevel_controller
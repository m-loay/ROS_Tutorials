
#include "set_speed/setSpeedPub.hpp"
// STD
#include <string>

namespace SetSpeed 
{
    SetSpeed::SetSpeed(ros::NodeHandle& nodeHandle, const std::string &nodeName)
    : nodeHandle_(nodeHandle), nodeName_(nodeName)
    {
        subscriberTopic_ = "/cmd_vel";
        publisher_ = nodeHandle_.advertise<geometry_msgs::Twist>(subscriberTopic_, 10);
        ROS_INFO("Successfully launched node --> %s.", nodeName_.c_str());
    }

    SetSpeed::~SetSpeed()
    {
    }

    void SetSpeed::publishMsg(const double linearX, const double angularZ)
    {
        geometry_msgs::Twist speed_msg;
        speed_msg.linear.x = linearX;
        speed_msg.angular.z = angularZ;
        ROS_INFO("Publish  --> linX =%f , AngZ=%f.", linearX,angularZ);
        publisher_.publish(speed_msg);
    }

} /* namespace */
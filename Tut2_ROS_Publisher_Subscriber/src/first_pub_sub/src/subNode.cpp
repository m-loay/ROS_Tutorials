#include <ros/ros.h>
#include <string>
#include <std_msgs/String.h>

void callback_TopicNode_data(const std_msgs::String& msg)
{
    ROS_INFO("Message Received");
    const std::string msg_info("Sub node is receiving data from " + msg.data);
    ROS_INFO("%s",msg_info.c_str());
}

int main(int argc, char **argv)
{
    //select Ros node name
    const std::string nodeName("SubNode_roscpp");

    //select Ros topic name
    const std::string TopicName("/TopicNodeData");

    //Init Node with its name
    ros::init(argc, argv, nodeName);

    //create node handle
    ros::NodeHandle nh;

    //Configure node node type(Subcriber), the topic Name, and queue size
    ros::Subscriber sub(nh.subscribe(TopicName, 1000, callback_TopicNode_data));

    //keep node running
    ros::spin();
}
#include<ros/ros.h>
#include<string>
#include<std_msgs/Int64.h>
#include "topics.h"

using namespace NumberCounterTopics;
int main(int argc, char **argv)
{
    //select Ros node name
    const std::string nodeName("Number_publisher");

    //Init Node with its name
    ros::init(argc, argv, nodeName);

    //create node handle
    ros::NodeHandle nh;

    //Configure node node type(publisher) , the topic Name, and queue size
    ros::Publisher pub(nh.advertise<std_msgs::Int64>(NumberCounterTopics::number, 10));

    //Select the rate of node execution
    ros::Rate rate(10);

    //Send a Log msg in terminal
    const std::string msg_info(nodeName+" has started");
    ROS_INFO(msg_info.c_str());

    //create publish message
    std_msgs::Int64 msg_pub;
    msg_pub.data = 2;

    while (ros::ok())
    {
        //Publish the msg on the configure Topic
        pub.publish(msg_pub);

        //sleep node until next cycle
        rate.sleep();
    }
}
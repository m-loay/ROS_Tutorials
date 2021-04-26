#include<ros/ros.h>
#include<string>
#include<std_msgs/Int64.h>
#include "topics.h"

using namespace NumberCounterTopics;
int g_counter = 0;
ros::Publisher pub;

void callback_number(const std_msgs::Int64& msg)
{
    //Prepare msg of received number & send it to ROSINFO
    std::string number("Received " + std::to_string(msg.data));
    ROS_INFO("%s",number.c_str());

    //Increment global counter with received data & publish the new value
    g_counter += msg.data;
    std_msgs::Int64 new_msg;
    new_msg.data = g_counter;
    pub.publish(new_msg);

    //Prepare msg of new value & send it to ROSINFO
    std::string pub_msg("Counter now --> " + std::to_string(g_counter));
    ROS_INFO("%s",pub_msg.c_str());
}

int main(int argc, char **argv)
{
    //select Ros node name
    const std::string nodeName("Number_counter");

    //Init Node with its name
    ros::init(argc, argv, nodeName);

    //create node handle
    ros::NodeHandle nh;

    //Configure node type(publisher/Subscriber) , the topic Name, and queue size
    ros::Subscriber sub(nh.subscribe(NumberCounterTopics::number, 1000, callback_number));
    pub = nh.advertise<std_msgs::Int64>(NumberCounterTopics::number_count, 10);

    //keep node running
    ros::spin();
}
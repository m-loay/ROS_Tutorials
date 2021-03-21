#include<ros/ros.h>
#include<string>
#include<std_msgs/Int64.h>
#include<std_srvs/SetBool.h>
#include "topics.h"

using namespace NumberCounterTopics;
int g_counter = 0;
ros::Publisher pub;

bool handle_reset_srv(std_srvs::SetBoolRequest& req, std_srvs::SetBoolResponse &resp)
{
    if(req.data)
    {
        resp.success = true;
        g_counter = 0;
        resp.message = "Counter rest Successfully, and counter value is "+std::to_string(g_counter);
        ROS_INFO(resp.message.c_str());
    }
    else
    {
        resp.success = true;
        resp.message = "Counter will continue counting, and counter value is "+std::to_string(g_counter);
        ROS_INFO(resp.message.c_str());
    }
    return true;
}

void callback_number(const std_msgs::Int64& msg)
{
    //Prepare msg of received number & send it to ROSINFO
    std::string number("Received " + std::to_string(msg.data));
    ROS_INFO(number.c_str());

    //Increment global counter with received data & publish the new value
    g_counter += msg.data;
    std_msgs::Int64 new_msg;
    new_msg.data = g_counter;
    pub.publish(new_msg);

    //Prepare msg of new value & send it to ROSINFO
    std::string pub_msg("Counter now --> " + std::to_string(g_counter));
    ROS_INFO(pub_msg.c_str());
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

    //Configure node node type(publisher) , the topic Name, and queue size
    ros::ServiceServer server(nh.advertiseService(NumberCounterTopics::reset_number_count, handle_reset_srv));

    //keep node running
    ros::spin();
}
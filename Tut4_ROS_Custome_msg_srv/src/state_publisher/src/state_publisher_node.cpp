#include <ros/ros.h>
#include <string>
#include <std_msgs/String.h>
#include <custom_msgs/GenStatus.h>

int main(int argc, char **argv)
{
    //select Ros node name
    const std::string nodeName("State_Publisher_roscpp");

    //select Ros topic name
    const std::string TopicName("/moduleStatus");

    //Init Node with its name
    ros::init(argc, argv, nodeName);

    //create node handle
    ros::NodeHandle nh;

    //Configure node node type(publisher) , the topic Name, and queue size
    ros::Publisher pub(nh.advertise<custom_msgs::GenStatus>(TopicName, 30));

    //Select the rate of node execution
    ros::Rate rate(10);

    //Send a Log msg in terminal
    const std::string msg_info(nodeName+" has started");
    ROS_INFO(msg_info.c_str());

    //create publish message
    const std::string msg_pub(nodeName+" is Publishing data to "+ TopicName);

    while(ros::ok())
    {
        //Prepare the msg according to its type
        custom_msgs::GenStatus msg;
        msg.module_state = "is updating ";
        msg.module_error_state = "No Error ";
        msg.debug_message = "None ";

        //Publish the msg on the configure Topic
        pub.publish(msg);

        //sleep node until next cycle
        rate.sleep();
    }
}
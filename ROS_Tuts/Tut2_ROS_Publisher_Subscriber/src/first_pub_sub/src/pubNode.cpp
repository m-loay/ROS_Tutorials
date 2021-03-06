#include <ros/ros.h>
#include <string>
#include <std_msgs/String.h>
int main(int argc, char **argv)
{
    //select Ros node name
    const std::string nodeName("PubNode_roscpp");

    //select Ros topic name
    const std::string TopicName("/TopicNodeData");

    //Init Node with its name
    ros::init(argc, argv, nodeName);

    //create node handle
    ros::NodeHandle nh;

    //Configure node node type(publisher) , the topic Name, and queue size
    ros::Publisher pub(nh.advertise<std_msgs::String>(TopicName, 10));

    //Select the rate of node execution
    ros::Rate rate(10);

    //Send a Log msg in terminal
    const std::string msg_info(nodeName+" has started");
    ROS_INFO("%s",msg_info.c_str());

    //create publish message
    const std::string msg_pub(nodeName+" is Publishing data to "+ TopicName);

    while(ros::ok())
    {
        //Prepare the msg according to its type
        std_msgs::String msg;
        msg.data = msg_pub;

        //Publish the msg on the configure Topic
        pub.publish(msg);

        //sleep node until next cycle
        rate.sleep();
    }
}
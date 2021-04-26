#include <ros/ros.h>
#include <string>
int main(int argc, char **argv)
{
    //select Ros node name
    const std::string nodeName("first_node_roscpp");

    //Init Node with its name
    ros::init(argc, argv, nodeName);

    //create Node Handle
    ros::NodeHandle nh;

    //Send a Log msg in terminal
    const std::string logMsg(nodeName+" has Started");
    ROS_INFO("%s",logMsg.c_str());

    //create runining msg
    const std::string logMsgRun(nodeName+" is running");

    //Select the rate of node execution
    ros::Rate rate(10);

    //loop while the node is not killed
    while(ros::ok())
    {
        //Send a Log msg in terminal
        ROS_INFO("%s",logMsgRun.c_str());
        rate.sleep();
    }
}
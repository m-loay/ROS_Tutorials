#include <ros/ros.h>
#include <string>
#include<std_srvs/SetBool.h>
#include "topics.h"


int main(int argc, char **argv)
{
    //select Ros node name
    const std::string nodeName("client_false");

    //Init Node with its name
    ros::init(argc, argv, nodeName);

    //create node handle
    ros::NodeHandle nh;

    //Configure node node type(publisher) , the topic Name, and queue size
    ros::ServiceClient client(nh.serviceClient<std_srvs::SetBool>(NumberCounterTopics::reset_number_count));

    //Select the rate of node execution
    std_srvs::SetBool request;
    request.request.data= false;

    if(client.call(request))
    {
        ROS_INFO("%s",request.response.message.c_str());
    }
    else
    {
        ROS_WARN("Service call failed");
    }
}
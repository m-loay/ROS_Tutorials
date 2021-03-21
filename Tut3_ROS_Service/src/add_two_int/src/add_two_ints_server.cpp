#include <ros/ros.h>
#include <string>
#include <rospy_tutorials/AddTwoInts.h>

bool handl_add_two_ints(rospy_tutorials::AddTwoInts::Request &req, rospy_tutorials::AddTwoInts::Response &resp)
{
    int result(req.a + req.b);
    const std::string sum("The Sum of"+ std::to_string(req.a) + " and " + std::to_string(req.a) + " ---> "
                          + std::to_string(result));
    ROS_INFO(sum.c_str());
    resp.sum = result;
    return true;
}

int main(int argc, char **argv)
{
    //select Ros node name
    const std::string nodeName("add_two_ints_server_roscpp");

    //select Ros topic name
    const std::string serviceName("/add_two_ints_server");

    //Init Node with its name
    ros::init(argc, argv, nodeName);

    //create node handle
    ros::NodeHandle nh;

    //Configure node node type(publisher) , the topic Name, and queue size
    ros::ServiceServer server(nh.advertiseService(serviceName, handl_add_two_ints));

    //Select the rate of node execution
    ros::spin();
}
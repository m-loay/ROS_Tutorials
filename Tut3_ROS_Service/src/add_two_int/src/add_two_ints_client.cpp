#include <ros/ros.h>
#include <string>
#include <rospy_tutorials/AddTwoInts.h>


int main(int argc, char **argv)
{
    //select Ros node name
    const std::string nodeName("add_two_ints_client_roscpp");

    //select Ros topic name
    const std::string serviceName("/add_two_ints_server");

    //Init Node with its name
    ros::init(argc, argv, nodeName);

    //create node handle
    ros::NodeHandle nh;

    //Configure node node type(publisher) , the topic Name, and queue size
    ros::ServiceClient client(nh.serviceClient<rospy_tutorials::AddTwoInts>(serviceName));

    //Select the rate of node execution
    rospy_tutorials::AddTwoInts srv;
    srv.request.a = 12;
    srv.request.b = 5;

    if(client.call(srv))
    {
        const std::string sum("The Sum of"+ std::to_string(srv.request.a) + " and " + std::to_string(srv.request.b) 
                              + " ---> "+ std::to_string(srv.response.sum));
        ROS_INFO(sum.c_str());
    }
    else
    {
        ROS_WARN("Service call failed");
    }
}

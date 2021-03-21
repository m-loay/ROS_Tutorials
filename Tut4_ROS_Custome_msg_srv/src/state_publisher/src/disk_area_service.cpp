#include <ros/ros.h>
#include <string>
#include <custom_msgs/computeDiskArea.h>

#define PI 3.14159

bool handl_disk_area(custom_msgs::computeDiskArea::Request &req, custom_msgs::computeDiskArea::Response &resp)
{
    auto radius(req.radius);
    if (radius > 0.0)
    {
        resp.area = PI*(radius*radius);
    }
    else
    {
        resp.area = 0.0;
    }
    return true;
}

int main(int argc, char **argv)
{
    //select Ros node name
    const std::string nodeName("disk_area_service");

    //select Ros topic name
    const std::string serviceName("/calc_disk_area");

    //Init Node with its name
    ros::init(argc, argv, nodeName);

    //create node handle
    ros::NodeHandle nh;

    //Configure node node type(publisher) , the topic Name, and queue size
    ros::ServiceServer server(nh.advertiseService(serviceName, handl_disk_area));

    //Select the rate of node execution
    ros::spin();
}
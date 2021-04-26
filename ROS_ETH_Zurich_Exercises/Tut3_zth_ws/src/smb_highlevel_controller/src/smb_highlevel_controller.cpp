#include"smb_highlevel_controller/smb_highlevel_controller.hpp"
#define MAX_LASER_SENSOR_ANGLE 2.35619

namespace smb_highlevel_controller
{
    SmbHighLevelController::SmbHighLevelController(ros::NodeHandle& nh,  const std::string nodeName)
    :nodeHandle_(nh),nodeName_(nodeName)
    {
        //get node details from yaml config file
        std::string topic;
        int queue_size;
        float kp,ki,kd,maxMinAngle,minDist;
        if((!nodeHandle_.getParam("subscriber_topic",topic)) || (!nodeHandle_.getParam("queue_size",queue_size))
           ||(!nodeHandle_.getParam("kpVal",kp)) || (!nodeHandle_.getParam("kiVal",ki))
           ||(!nodeHandle_.getParam("kdVal",kd)) ||(!nodeHandle_.getParam("maxAngleRad",maxMinAngle))
           ||(!nodeHandle_.getParam("minTolDist",minDist)))
        {
            ROS_ERROR("Could not find params for node : %s", nodeName.c_str());
        }
        //create laser scan subscriber
        subscriber_ = nodeHandle_.subscribe(topic, queue_size, &SmbHighLevelController::LaserCallback, this);

        //create robot cma publisher
        robotCmdPublisher_ = nodeHandle_.advertise<geometry_msgs::Twist>("/cmd_vel",1);

        //create pid controller object
        controllerPID_.controllerInit(kp, ki, kd, maxMinAngle, -maxMinAngle);

        //create robot cma publisher
        rvizPublisher_ = nodeHandle_.advertise<visualization_msgs::Marker>("visualization_marker", 1);

        //Output node status
        ROS_INFO("%s node has launched", nodeName.c_str());

        //init robot velocity
        minTolDist_ = minDist;
        float val = 1.0f;
        linearVelocityUpdate(val);

        //init rviz
        rvizInit();
    }

    void SmbHighLevelController::LaserCallback(const sensor_msgs::LaserScan &msg)
    {
        //get time
        float dt(0);
        if(true == firstTime_)
        {
            lastTime_ = ros::Time::now();
            firstTime_ = false;
            return;
        }
        else
        {
            ros::Time currentTime(ros::Time::now());
            ros::Duration diffTime(currentTime - lastTime_);
            lastTime_ = currentTime;
            dt = static_cast<float> (diffTime.toSec());
        }
        
        //find the minimum distance 
        auto minElementDist (std::min_element(msg.ranges.cbegin(), msg.ranges.cend()));

        //calculate the distance & angle of the pillar
        int count(minElementDist - msg.ranges.cbegin());
        float angle(msg.angle_min + msg.angle_increment * count);


        //calculate the position of the pillar
        pillarPosition_.x = *minElementDist * std::cos(angle);
        pillarPosition_.y = *minElementDist * std::sin(angle);

        //Output node status
        ROS_INFO_STREAM("Min distance is " << *minElementDist << " Angle is " <<angle/M_PI*180.0<<" deg");

        //update robot
        if(*minElementDist <= minTolDist_)
        {
            robotCmd_.linear.x = 0.0f;
            robotCmd_.angular.z = 0.0f;
        }
        else
        {
            float val = 2.0f;
            linearVelocityUpdate(val);
            angularVelocityUpdate(angle, dt);
        }
        robotCmdPublish();

        //update RVIZ
        rvizUpdate();
        rvizPublishData();
    }

    void SmbHighLevelController::linearVelocityUpdate(const float &vel)
    {
        robotCmd_.linear.x = vel;
    }

    void SmbHighLevelController::angularVelocityUpdate(const float &angle, const float dt)
    {
        if(fabs(angle)>0.1f)
        {
            robotCmd_.linear.x =0.0f;
        }
        robotCmd_.angular.z = -1.0f * controllerPID_.controllerUpdate(0.0f, angle, dt);
    }


    void SmbHighLevelController::robotCmdPublish(void)
    {
        robotCmdPublisher_.publish(robotCmd_);
    }

    void SmbHighLevelController::rvizInit(void)
    {
        marker_.header.frame_id = "base_link";
        marker_.header.stamp = ros::Time();
        marker_.ns = "pillar";
        marker_.id = 0;
        marker_.type = visualization_msgs::Marker::CYLINDER;
        marker_.action = visualization_msgs::Marker::ADD;
        marker_.pose.position.x = pillarPosition_.x;
        marker_.pose.position.y = pillarPosition_.y;
        marker_.pose.position.z = 0.0;
        marker_.scale.x = 1.0;
        marker_.scale.y = 1.0;
        marker_.scale.z = 5.0;
        marker_.color.a = 1.0; // Don't forget to set the alpha!
        marker_.color.r = 0.0;
        marker_.color.g = 1.0;
        marker_.color.b = 0.0;        
    }

    void SmbHighLevelController::rvizUpdate(void)
    {
        marker_.pose.position.x = pillarPosition_.x;
        marker_.pose.position.y = pillarPosition_.y;
        marker_.pose.position.z = 0.0f;       
    }

    void SmbHighLevelController::rvizPublishData(void)
    {
        rvizPublisher_.publish(marker_);   
    }
    
} //smb_highlevel_controller
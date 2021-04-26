#pragma once

// ROS
#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
namespace SetSpeed 
{

    /*!
    * Main class for the node to handle the ROS interfacing.
    */
    class SetSpeed
    {
        public:
            /*!
            * Constructor.
            * @param nodeHandle the ROS node handle.
            * @param nodeName the ROS node name.
            */
            SetSpeed(ros::NodeHandle& nodeHandle, const std::string &nodeName);

            /*!
            * Destructor.
            */
            virtual ~SetSpeed();

            /*!
            * publishMsg on topic.
            * @param temperture The required temperture.
            * @return void.
            */
            void publishMsg(const double linearX, const double angularZ);

            private:

            //! ROS node handle.
            ros::NodeHandle& nodeHandle_;

            //! ROS node name.
            const std::string nodeName_;

            //! ROS topic publisher.
            ros::Publisher publisher_;

            //! ROS topic name to subscribe to.
            std::string subscriberTopic_;

    };

} /* namespace */

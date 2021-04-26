#pragma once

// ROS
#include <ros/ros.h>
#include <sensor_msgs/Temperature.h>

namespace RosPackageTemplatePub 
{

    /*!
    * Main class for the node to handle the ROS interfacing.
    */
    class RosPackageTemplatePub
    {
        public:
            /*!
            * Constructor.
            * @param nodeHandle the ROS node handle.
            */
            RosPackageTemplatePub(ros::NodeHandle& nodeHandle, const std::string &nodeName);

            /*!
            * Destructor.
            */
            virtual ~RosPackageTemplatePub();

            /*!
            * publishMsg on topic.
            * @param temperture The required temperture.
            * @return void.
            */
            void publishMsg(const double temperture);

            private:
            /*!
            * Reads and verifies the ROS parameters.
            * @return true if successful.
            */
            bool readParameters();

            //! ROS node handle.
            ros::NodeHandle& nodeHandle_;

            //! ROS node name.
            const std::string nodeName_;

            //! ROS topic publisher.
            ros::Publisher publisher_;

            //! ROS topic name to subscribe to.
            std::string subscriberTopic_;

            //! ROS service server.
            ros::ServiceServer serviceServer_;
    };

} /* namespace */

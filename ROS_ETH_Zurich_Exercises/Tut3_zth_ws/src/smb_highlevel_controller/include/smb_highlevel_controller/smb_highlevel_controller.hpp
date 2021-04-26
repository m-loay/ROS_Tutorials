#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>
#include <geometry_msgs/Twist.h>
#include <visualization_msgs/Marker.h>
#include <vector>
#include <cmath>
#include "math.hpp"
#include "smb_highlevel_controller_pid.hpp"

namespace smb_highlevel_controller
{
    struct PositionS
    {
        float x;
        float y;
        float angle;
    };

    /*!
    * Main class for the node to handle the ROS interfacing.
    */
    class SmbHighLevelController
    {
        private:
        /*data*/
        //! ROS node handle.
        ros::NodeHandle nodeHandle_;

        //! ROS topic name to subscribe to.
        ros::Subscriber subscriber_;

        //! ROS topic Robot velocity publisher.
        ros::Publisher robotCmdPublisher_;

        //! ROS topic rviz publisher.
        ros::Publisher rvizPublisher_;

        //! ROS node name.
        const std::string nodeName_;

        //! Robot Command.
        geometry_msgs::Twist robotCmd_;

        //! Pillar Position.
        struct PositionS pillarPosition_;

         //! PID Controller Object.
        SmbHighLevelControllerPID controllerPID_;

        //! Rviz Marker.
        visualization_msgs::Marker marker_;

        //! save simulation last time stamp.
        ros::Time lastTime_;

        //Minimum tolernace distance to stop befor hit an object.
        float minTolDist_;

        //! check init state.
        bool firstTime_;

        /*!
        * LaserCallback publish the minimum distances based on laser scanner.
        * @param msg range distances of all laser scanner.
        * @return void.
        */
        void LaserCallback(const sensor_msgs::LaserScan &msg);

        /*!
        * linearVelocityUpdate publish the minimum distances based on laser scanner.
        * @param msg range distances of all laser scanner.
        * @return void.
        */
        void linearVelocityUpdate(const float &vel);

        /*!
        * angularVelocityUpdate publish the minimum distances based on laser scanner.
        * @param msg range distances of all laser scanner.
        * @return void.
        */
        void angularVelocityUpdate(const float &angle, const float dt);

        /*!
        * robotCmdPublish publish the minimum distances based on laser scanner.
        * @param msg range distances of all laser scanner.
        * @return void.
        */
        void robotCmdPublish(void);

        /*!
        * rvizInit publish the minimum distances based on laser scanner.
        * @param msg range distances of all laser scanner.
        * @return void.
        */
        void rvizInit(void);

        /*!
        * rvizUpdate publish the minimum distances based on laser scanner.
        * @param msg range distances of all laser scanner.
        * @return void.
        */
        void rvizUpdate(void);

        /*!
        * publishRvizData publish the minimum distances based on laser scanner.
        * @param msg range distances of all laser scanner.
        * @return void.
        */
        void rvizPublishData(void);

        public:
        /*!
        * Constructor.
        * @param nodeHandle the ROS node handle.
        * @param nodeName the ROS node name.
        */
        SmbHighLevelController(ros::NodeHandle& nh, const std::string nodeName);

        /* @brief: Copy constructor
        * defined as DELETED for simplicity 
        * @comments: at this moment, I don't think this is necessarily a good
        * practice to wrap up node handlers, subscribers etc. into a new class,
        * because we should be very careful with the behavior of copy constructors.
        * However, if we really want to copy this class, remember to
        * copy both vars 'nodeHandle' & 'subscriber'. Do NOT initialize
        * the subscriber again from the method 'NodeHandle.subscribe()'.
        * Refer to the source code
        * http://wiki.ros.org/roscpp/Overview/NodeHandles
        * https://github.com/ros/ros_comm/blob/kinetic-devel/clients/roscpp/src/libros/node_handle.cpp
        * https://github.com/ros/ros_comm/blob/kinetic-devel/clients/roscpp/src/libros/subscriber.cpp
        */
        SmbHighLevelController(const SmbHighLevelController &) = delete;
        SmbHighLevelController& operator=(const SmbHighLevelController &) = delete;

        /*!
        * Destructor.
        */
        ~SmbHighLevelController() = default;
    };
}

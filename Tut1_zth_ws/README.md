# Exercise 1 in ETH Zurich
This is the solution to exercise 1, course Eth zurich. 

## Directory Structure
* [set_speed/](./src/set_speed)
  * [include/](./src/set_speed/include)
    * [set_speed/](./src/set_speed/include/set_speed)
      * [setSpeedPub.hpp](./src/set_speed/include/set_speed/setSpeedPub.hpp)
  * [launch/](./src/set_speed/launch)
    * [set_speed.launch](./src/set_speed/launch/set_speed.launch)
  * [src/](./src/set_speed/src)
    * [pub_node.cpp](./src/set_speed/src/pub_node.cpp)
    * [setSpeedPub.cpp](./src/set_speed/src/setSpeedPub.cpp)
  * [worlds/](./src/set_speed/worlds)
    * [big_map_summer_school.world](./src/set_speed/worlds/big_map_summer_school.world)
    * [empty.world](./src/set_speed/worlds/empty.world)
    * [planner_tutorial.world](./src/set_speed/worlds/planner_tutorial.world)
  * [CMakeLists.txt](./src/set_speed/CMakeLists.txt)
  * [package.xml](./src/set_speed/package.xml)
* [smb_control/](./src/smb_control)
  * [config/](./src/smb_control/config)
    * [control.yaml](./src/smb_control/config/control.yaml)
    * [empty.yaml](./src/smb_control/config/empty.yaml)
    * [gazebo_interface.yaml](./src/smb_control/config/gazebo_interface.yaml)
    * [localization.yaml](./src/smb_control/config/localization.yaml)
    * [public_interface.yaml](./src/smb_control/config/public_interface.yaml)
    * [twist_mux.yaml](./src/smb_control/config/twist_mux.yaml)
  * [launch/](./src/smb_control/launch)
    * [control.launch](./src/smb_control/launch/control.launch)
  * [CMakeLists.txt](./src/smb_control/CMakeLists.txt)
  * [package.xml](./src/smb_control/package.xml)
* [smb_description/](./src/smb_description)
  * [bin/](./src/smb_description/bin)
    * [generate_urdf.sh](./src/smb_description/bin/generate_urdf.sh)
  * [launch/](./src/smb_description/launch)
    * [debug.launch](./src/smb_description/launch/debug.launch)
    * [load.launch](./src/smb_description/launch/load.launch)
  * [resources/](./src/smb_description/resources)
    * [smb.urdf](./src/smb_description/resources/smb.urdf)
  * [rviz/](./src/smb_description/rviz)
    * [smb_description.rviz](./src/smb_description/rviz/smb_description.rviz)
  * [urdf/](./src/smb_description/urdf)
    * [meshes/](./src/smb_description/urdf/meshes)
      * [wheel.dae](./src/smb_description/urdf/meshes/wheel.dae)
    * [new_payload/](./src/smb_description/urdf/new_payload)
      * [meshes/](./src/smb_description/urdf/new_payload/meshes)
        * [SMB_blackfly_camera.dae](./src/smb_description/urdf/new_payload/meshes/SMB_blackfly_camera.dae)
        * [SMB_blackfly_camera.stl](./src/smb_description/urdf/new_payload/meshes/SMB_blackfly_camera.stl)
        * [SMB_imu.dae](./src/smb_description/urdf/new_payload/meshes/SMB_imu.dae)
        * [SMB_imu.stl](./src/smb_description/urdf/new_payload/meshes/SMB_imu.stl)
        * [SMB_lidar_mount.dae](./src/smb_description/urdf/new_payload/meshes/SMB_lidar_mount.dae)
        * [SMB_lidar_mount.stl](./src/smb_description/urdf/new_payload/meshes/SMB_lidar_mount.stl)
        * [SMB_step.dae](./src/smb_description/urdf/new_payload/meshes/SMB_step.dae)
        * [SMB_step.stl](./src/smb_description/urdf/new_payload/meshes/SMB_step.stl)
    * [sensor_plugins/](./src/smb_description/urdf/sensor_plugins)
      * [smb_blackfly.gazebo.xacro](./src/smb_description/urdf/sensor_plugins/smb_blackfly.gazebo.xacro)
      * [smb_blackfly_stereo.gazebo.xacro](./src/smb_description/urdf/sensor_plugins/smb_blackfly_stereo.gazebo.xacro)
      * [smb_depth.gazebo.xacro](./src/smb_description/urdf/sensor_plugins/smb_depth.gazebo.xacro)
      * [smb_gps.gazebo.xacro](./src/smb_description/urdf/sensor_plugins/smb_gps.gazebo.xacro)
      * [smb_imu.gazebo.xacro](./src/smb_description/urdf/sensor_plugins/smb_imu.gazebo.xacro)
      * [smb_mono.gazebo.xacro](./src/smb_description/urdf/sensor_plugins/smb_mono.gazebo.xacro)
      * [smb_odometry.gazebo.xacro](./src/smb_description/urdf/sensor_plugins/smb_odometry.gazebo.xacro)
      * [smb_velodyne.gazebo.xacro](./src/smb_description/urdf/sensor_plugins/smb_velodyne.gazebo.xacro)
    * [temp/](./src/smb_description/urdf/temp)
      * [smb.urdf.xacro](./src/smb_description/urdf/temp/smb.urdf.xacro)
    * [smb.urdf.xacro](./src/smb_description/urdf/smb.urdf.xacro)
    * [smb_big_properties.urdf.xacro](./src/smb_description/urdf/smb_big_properties.urdf.xacro)
    * [smb_lidar_mount.urdf.xacro](./src/smb_description/urdf/smb_lidar_mount.urdf.xacro)
    * [smb_ros_control.gazebo.xacro](./src/smb_description/urdf/smb_ros_control.gazebo.xacro)
    * [smb_ros_skid_steer.gazebo.xacro](./src/smb_description/urdf/smb_ros_skid_steer.gazebo.xacro)
    * [smb_standalone.urdf.xacro](./src/smb_description/urdf/smb_standalone.urdf.xacro)
    * [smb_utils.urdf.xacro](./src/smb_description/urdf/smb_utils.urdf.xacro)
  * [CMakeLists.txt](./src/smb_description/CMakeLists.txt)
  * [README.md](./src/smb_description/README.md)
  * [TODO](./src/smb_description/TODO)
  * [package.xml](./src/smb_description/package.xml)
* [smb_gazebo/](./src/smb_gazebo)
  * [config/](./src/smb_gazebo/config)
    * [default.yaml](./src/smb_gazebo/config/default.yaml)
    * [parameters.yaml](./src/smb_gazebo/config/parameters.yaml)
    * [publishers.yaml](./src/smb_gazebo/config/publishers.yaml)
    * [services.yaml](./src/smb_gazebo/config/services.yaml)
  * [include/](./src/smb_gazebo/include)
    * [smb_gazebo/](./src/smb_gazebo/include/smb_gazebo)
      * [OdometrySource.hpp](./src/smb_gazebo/include/smb_gazebo/OdometrySource.hpp)
  * [launch/](./src/smb_gazebo/launch)
    * [smb_gazebo.launch](./src/smb_gazebo/launch/smb_gazebo.launch)
  * [src/](./src/smb_gazebo/src)
    * [OdometrySource.cpp](./src/smb_gazebo/src/OdometrySource.cpp)
  * [worlds/](./src/smb_gazebo/worlds)
    * [big_map_summer_school.world](./src/smb_gazebo/worlds/big_map_summer_school.world)
    * [clearpath_playpen.world](./src/smb_gazebo/worlds/clearpath_playpen.world)
    * [empty.world](./src/smb_gazebo/worlds/empty.world)
    * [planner_tutorial.world](./src/smb_gazebo/worlds/planner_tutorial.world)
    * [singlePillar.world](./src/smb_gazebo/worlds/singlePillar.world)
  * [CMakeLists.txt](./src/smb_gazebo/CMakeLists.txt)
  * [package.xml](./src/smb_gazebo/package.xml)
* [CMakeLists.txt](./src/CMakeLists.txt)
## Exercise Description

In this exercise, it's required the following:  
1. Send velocity command to robot:  
    -  use the launch file to start the simulation:
    `roslaunch smb_gazebo smb_gazebo.launch`
    - show topic message info:
    `rostopic type /cmd_vel | rosmsg show`
    - publish message:
    `rostopic pub /cmd_vel geometry_msgs/Twist -r 1 '[2.0, .0, .0]' '[.0, .0, 1.0]'`

2.  Use `teleop_twist_keyboard`:  
Use keyboard to control the rrobot  
    - use the launch file to start the simulation:  
      `roslaunch smb_gazebo smb_gazebo.launch` 

    - Run ros-node to activate `teleop_twist_keyboard`:   
      `rosrun teleop_twist_keyboard teleop_twist_keyboard.py`

3. Write launch file to create a simulation  :  
I created a package `set_speed` for it with a ros node to control the robot.

## Dependencies for Running Locally
* cmake >= 2.8
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* ROS  >= (Kinetic/Melodic/Noetic)
  * For all platform and OS [Click here for installation instructions](http://wiki.ros.org/ROS/Installation)

## Basic Build Instructions

1. Clone this repo.
2. Inside cloned folder `catkin_make`
3. Then source the workspace: `source devel/setup.bash`
4. Then run the launch files: `roslaunch set_speed set_speed.launch`


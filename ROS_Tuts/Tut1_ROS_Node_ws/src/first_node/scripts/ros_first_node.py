#! /usr/bin/env python3

import rospy

if __name__ == '__main__':
    #select Ros node name
    nodeName = "first_node_rospy"

    #Init Node with its name
    rospy.init_node(nodeName)

    #Send a Log msg in terminal
    rospy.loginfo(nodeName+" has started")

    #Select the rate of node execution
    rate = rospy.Rate(10)

    #loop while the node is not killed
    while not rospy.is_shutdown():
        #Send a Log msg in terminal
        rospy.loginfo(nodeName+" is running")
        rate.sleep()
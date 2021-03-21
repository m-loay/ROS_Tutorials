#!/usr/bin/env python3

import rospy
from rospy_tutorials.srv import AddTwoInts

if __name__ == '__main__':

    #select service name
    nodeName = "add_two_ints_client"

    #select service name
    serviceName = "/add_two_ints"

    #Init Node with its name
    rospy.init_node(nodeName)

    #Send a Log msg in terminal
    rospy.loginfo(nodeName+" has been created")

    #wait for the service
    rospy.wait_for_service(serviceName)

    try:
        add_two_ints = rospy.ServiceProxy(serviceName, AddTwoInts)
        response = add_two_ints(5,-1)
        rospy.loginfo("Sum is: " + str(response.sum))
    except rospy.ServiceException as e:
        rospy.logwarn("Service Failed " + str(e))
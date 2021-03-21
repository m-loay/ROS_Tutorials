#!/usr/bin/env python3

import rospy
from rospy_tutorials.srv import AddTwoInts

def handle_add_two_ints(req):
    result = req.a +req.b
    rospy.loginfo('Sum of '+ str(req.a) +' and '+ str(req.b)+ ' is '+ str(result))
    return result

if __name__ == '__main__':

    #select service name
    nodeName = "add_two_ints_server"

    #select service name
    serviceName = "/add_two_ints"

    #Init Node with its name
    rospy.init_node(nodeName)

    #Send a Log msg in terminal
    rospy.loginfo(nodeName+" has been created")

    #configure service with msg and callb-back
    service = rospy.Service(serviceName,AddTwoInts, handle_add_two_ints)

    rospy.spin()


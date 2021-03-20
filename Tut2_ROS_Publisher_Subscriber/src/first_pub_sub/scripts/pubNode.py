#!/usr/bin/env python3

import rospy
from std_msgs.msg import String

if __name__ == '__main__':
    #select Ros node name
    nodeName = "PubNode_rospy"

    #select Ros topic name
    TopicName = "/TopicNodeData"

    #Init Node with its name
    rospy.init_node(nodeName)

    #Configure node node type(publisher) , the topic Name, and queue size
    pub = rospy.Publisher(TopicName,String,queue_size=10)

    #Select the rate of node execution
    rate = rospy.Rate(10)

    #Send a Log msg in terminal
    rospy.loginfo(nodeName+" has started")

    #loop while the node is not killed
    while not rospy.is_shutdown():
        #Prepare the msg according to its type
        msg = String()
        msg.data = nodeName+" is Publishing data to "+ TopicName

        #Publish the msg on the configure Topic
        pub.publish(msg)

        #sleep node until next cycle
        rate.sleep()

    #Send a Log msg when node killed
    logInfoMsg = nodeName+" is shutdown"
    rospy.loginfo(logInfoMsg)

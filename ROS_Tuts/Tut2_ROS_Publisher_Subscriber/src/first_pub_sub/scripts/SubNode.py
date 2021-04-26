#!/usr/bin/env python3

import rospy
from std_msgs.msg import String

def callback_TopicNode_data(msg):
    rospy.loginfo("Message Received")
    infoMsg ="Sub node is receiving data from " + msg.data
    rospy.loginfo(infoMsg)

if __name__ == '__main__':
    #select Ros node name
    nodeName = "SubNode_rospy"

    #select Ros topic name
    TopicName = "/TopicNodeData"

    #Init Node with its name
    rospy.init_node(nodeName)

    #Configure node node type(Subcriber) ,the topic Name, and callback
    sub = rospy.Subscriber(TopicName,String,callback_TopicNode_data)

    #keep node running
    rospy.spin()





#!/usr/bin/python

import rospy
import subprocess
import os
import signal


class RosbagRecord:
    def __init__(self):
        self.record_script = 'rosbag record /gps_head /gps_tail /gps_waypoint /robot_cmd /steering_angle /waypoint_key /robot_heading /joy_cmd /joy_trigger'
        self.record_folder = '/home/tric/catkin_ws/src/20200615_tric_navigation/src'
        rospy.on_shutdown(self.stop_recording_handler)

        # Start recording.
        command = self.record_script
        self.p = subprocess.Popen(command, stdin=subprocess.PIPE, shell=True, cwd=self.record_folder)

        # Wait for shutdown signal to close rosbag record
        #rospy.spin()

    def terminate_ros_node(self, s):
        # Adapted from http://answers.ros.org/question/10714/start-and-stop-rosbag-within-a-python-script/
        list_cmd = subprocess.Popen("rosnode list", shell=True, stdout=subprocess.PIPE)
        list_output = list_cmd.stdout.read()
        retcode = list_cmd.wait()
        assert retcode == 0, "List command returned %d" % retcode
        for str in list_output.split("\n"):
            if (str.startswith(s)):
                os.system("rosnode kill " + str)

    def stop_recording_handler(self):
        rospy.loginfo(rospy.get_name() + ' stop recording.')
        self.terminate_ros_node("/record")

if __name__ == '__main__':
    rospy.init_node('rosbag_record')
    rospy.loginfo(rospy.get_name() + ' start')

    # Go to class functions that do all the heavy lifting. Do error checking.
    try:
        rosbag_record = RosbagRecord()
    except rospy.ROSInterruptException:
        pass

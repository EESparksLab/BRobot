#!/bin/bash

nohup ros2 run joy joy_node > joynode.out 2>&1 &
nohup python3 /source/joy_driver2.py > joydriver.out 2>&1 &
python3 /source/brobotAcquisition.py

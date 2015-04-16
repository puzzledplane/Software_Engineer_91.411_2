#!/bin/bash

echo "Running script..."

rosrun sound_play say.py "Initiating camera activation sequence."

rosrun image_view image_view image:=/camera/rgb/image_raw

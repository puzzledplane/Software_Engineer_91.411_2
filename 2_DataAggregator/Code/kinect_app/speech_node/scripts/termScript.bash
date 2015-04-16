#!/bin/bash

echo Running END script...
rosrun sound_play say.py "Terminating."

#pkill -f "ManageNodeStatus"
pkill -f "soundplay_node"
pkill -f "voice_nav_commands"
pkill -f "image_view"
echo Detection terminated successfully...in theory

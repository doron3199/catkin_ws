#!/bin/sh
export ROBOT_INITIAL_POSE="-Y 1.57"
xterm -e  " roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=$(rospack find pick_objects)/worlds/ER.world" &
sleep 15
xterm -e  " roslaunch turtlebot_gazebo amcl_demo.launch map_file:=$(rospack find pick_objects)/maps/map.yaml" &
sleep 10
xterm  -e  " roslaunch turtlebot_rviz_launchers view_navigation.launch"
#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>

// Define a client for to send goal requests to the move_base server through a SimpleActionClient
typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

int main(int argc, char** argv){
  // Initialize the simple_navigation_goals node
  ros::init(argc, argv, "pick_objects");
  
  ros::NodeHandle n;
	n.setParam("isPickUp", false);
	n.setParam("isDrop", false);

  //tell the action client that we want to spin a thread by default
  MoveBaseClient ac("move_base", true);

  // Wait 5 sec for move_base action server to come up
  while(!ac.waitForServer(ros::Duration(5.0))){
    ROS_INFO("Waiting for the move_base action server to come up");
  }

  move_base_msgs::MoveBaseGoal goal;

  // set up the frame parameters
  goal.target_pose.header.frame_id = "map";
  goal.target_pose.header.stamp = ros::Time::now();

  // Define a position and orientation for the robot to reach
  goal.target_pose.pose.position.x = -3.0;
  goal.target_pose.pose.position.y = 3.0; 
  goal.target_pose.pose.orientation.w = 1.0;

   // Send the goal position and orientation for the robot to reach
  ROS_INFO("Sending pickup");
  ac.sendGoal(goal);

  // Wait an infinite time for the results
  ac.waitForResult();

  // Check if the robot reached its goal
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
    ROS_INFO("Hooray, I reached pickup!");
		n.setParam("isPickUp", true);
  } else
    ROS_INFO("I failllleeddd pickup you won this time");

  // I need to pick up stuff smh
  ros::Duration(5).sleep(); 
  // Define a position and orientation for the robot to reach goal 2
  goal.target_pose.pose.position.x = -5.0;
  goal.target_pose.pose.position.y = -9.0; 
  goal.target_pose.pose.orientation.w = 0.0;
  goal.target_pose.pose.orientation.z = 2.7;

  // Send the goal position and orientation for the robot to reach goal 2
  ROS_INFO("Sending drop");
  ac.sendGoal(goal);

  // Wait an infinite time for the results
  ac.waitForResult();

   // Check if the robot reached its goal
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
    ROS_INFO("Hooray, I reached drop!");
 	  n.setParam("isDrop", true);

  }
  else
    ROS_INFO("I failllleeddd drop you won this time");


  return 0;
}
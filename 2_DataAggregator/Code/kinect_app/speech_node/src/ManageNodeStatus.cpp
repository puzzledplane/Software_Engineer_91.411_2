#include <ros/ros.h>
#include <std_msgs/String.h>
#include <iostream>

#include "ManageNodeStatus.h"
using namespace std;

ManageNodeStatus::ManageNodeStatus()
{
  ;
}


void ManageNodeStatus::callback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("I heard: [%s]", msg->data.c_str() );

  cout << "processing: " << msg->data.c_str() << endl;

  if(strcmp(msg->data.c_str(), "hi jarvis") == 0)
  {
    runScript(1);
  }
  else if(strcmp(msg->data.c_str(), "jarvis") == 0)
  {
    runScript(1);
  }
  else if(strcmp(msg->data.c_str(), "terminate") == 0)
  {
    runScript(2);
  }

}


void ManageNodeStatus::runScript(int whichScript)
{
  ROS_INFO("Attempting to run script");
  char cwd[1024];
  cout << getcwd(cwd, sizeof(cwd) ) << endl;
  //instead, call launch file.

  if(whichScript == 1)
  {  
    system("./src/sensor_admin/speech_node/scripts/jarvis.bash");
  }
  else if(whichScript == 2)
    system("./src/sensor_admin/speech_node/scripts/termScript.bash");
  //system("kill firefox");

}


ManageNodeStatus::~ManageNodeStatus()
{
  ;
}


//--------------------------------
int main(int argc, char **argv)
{

  ros::init(argc, argv, "Listener");
  ros::NodeHandle nh;
  ManageNodeStatus mns;
  ros::Subscriber sub = nh.subscribe("/recognizer/output", 1000, &ManageNodeStatus::callback, &mns);

  ros::spin();
  return 0;
}

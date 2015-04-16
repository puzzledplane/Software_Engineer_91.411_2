#include "Respond.h"

Respond::Respond()
{
  ;
}


void Respond::setInstructions(const std_msgs::String::ConstPtr& msg)
{
  if(strcmp(msg->data.c_str(), "begin detection") == 0)
  {
    speak();
  }
}


void Respond::speak()
{
  currentResponce.say("Activating detector node");
  sleep(5);
}


Respond::~Respond()
{
  ;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "Respond");

  ros::NodeHandle nh;
  Respond acknowledgement;
  ros::Subscriber sub = nh.subscribe("/recognizer/output", 1, &Respond::setInstructions, &acknowledgement);
  cout << "Hear ye, hear ye" << endl; 

  ros::spin();
  return 0;
}

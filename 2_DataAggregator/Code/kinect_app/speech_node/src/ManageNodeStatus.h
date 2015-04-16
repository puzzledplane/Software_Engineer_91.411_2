/*
 * File: MangeNodeStatus.h
 * Author: James Kuczynski
 * Email: jkuczyns@cs.uml.edu
 * File Description: Subscribes to (...) to recieve the user's vocal commands, published from PocketSphinx.
*/

#ifndef MANAGENODESTATUS_H
#define MANAGENODESTATUS_H

#include <ros/ros.h>
#include <std_msgs/String.h>
#include <iostream>
using namespace std;

class ManageNodeStatus
{
private:
  ;


public:
  ManageNodeStatus();
  void callback(const std_msgs::String::ConstPtr& msg);
  void runScript(int whichScript);
  ~ManageNodeStatus();

};

#endif /* MANAGENODESTATUS_H */

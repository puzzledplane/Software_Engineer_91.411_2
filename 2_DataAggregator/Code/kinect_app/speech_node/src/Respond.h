/*
 * File:Respond.h
 * Author: James Kuczynski
 * Email: jkuczyns@cs.uml.edu
 * File Description: Subscribes to (...) to recieve the user's vocal commands, published from PocketSphinx.
*/


#ifndef RESPOND_H
#define RESPOND_H

#include <ros/ros.h>
#include <std_msgs/String.h>
#include <sound_play/sound_play.h>
#include <unistd.h>
#include <iostream>
using namespace std;

class Respond
{

private:
  sound_play::SoundClient currentResponce; /**Soundclient object*/


public:
  /**
   * Empty constructor.
   */
  Respond();
  void setInstructions(const std_msgs::String::ConstPtr& msg);
  void speak();
  ~Respond();


};

#endif /*RESPOND_H*/

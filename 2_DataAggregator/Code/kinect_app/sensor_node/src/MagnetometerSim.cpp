/*
 * File: MagnetometerSim.cpp
 * Author: James Kuczynski
 * Email: jkuczyns@cs.uml.edu
 * File Description: This file simulates a magnetometer. Note: the magnetic_field_covariance
 *		     field is not implemented.
 * 
 * Created 04/02/2015 11:25am
 */

#include <ros/ros.h>
#include <sensor_msgs/MagneticField.h>
#include <geometry_msgs/Vector3.h>
#include <std_msgs/Float64.h>


using namespace ros;

int main(int argc, char **argv)
{
  init(argc, argv, "talker");
  
  ROS_INFO("Beginning accelerometer simulation...");

  NodeHandle n;
  
  //create array of simulated points to construct the message from
  geometry_msgs::Vector3 magneticFieldArr[1000];
  //std_msgs::Float64 magneticFieldCovarianceArr[1000];
 
  //verify array contents 
  for(size_t i = 0; i < 1000; i++)
  {
     magneticFieldArr[i].x = i/10.0;
     magneticFieldArr[i].x = i/10.0;
     magneticFieldArr[i].x = i/10.0;

     //magneticFieldCovarianceArr[i].data = i/10.0;
     //magneticFieldCovarianceArr[i].data = i/10.0;
     //magneticFieldCovarianceArr[i].data = i/10.0;
  }  

  Publisher chatter_pub = n.advertise<sensor_msgs::MagneticField>("/accelerometer/magneticfield/sim", 1000);

  Rate loop_rate(10);

  int count = 0;
  while (ok())
  {
    sensor_msgs::MagneticField msg;
    msg.magnetic_field = magneticFieldArr[count];
    //msg.magnetic_field_covariance = magneticFieldCovarianceArr[count]; 
    
    ROS_INFO("%f", msg.magnetic_field.x);
    chatter_pub.publish(msg);

    spinOnce();

    loop_rate.sleep();
    ++count;
  }


  return 0;
}

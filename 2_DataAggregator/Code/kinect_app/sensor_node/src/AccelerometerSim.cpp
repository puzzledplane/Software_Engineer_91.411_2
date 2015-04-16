/**
 * File: AccelerometerSim.cpp
 * Author: James Kuczynski
 * Email: jkuczyns@cs.uml.edu
 * File Description: This program is a ROS publisher.  It publishes simulated accelerometer
 *  		     messages of type sensor_msgs/Imu.
 *
 * Created: 04/01/2015 12:55am
 */

#include <ros/ros.h>
#include <sensor_msgs/Imu.h>
#include <geometry_msgs/Vector3.h>


using namespace ros;

int main(int argc, char **argv)
{
  init(argc, argv, "talker");
  
  ROS_INFO("Beginning accelerometer simulation...");

  NodeHandle n;
  
  //create array of simulated points to construct the message from
  geometry_msgs::Quaternion quaternionArr[1000];
  geometry_msgs::Vector3 angularVelocityArr[1000];
  geometry_msgs::Vector3 linearAccelerationCovarianceArr[1000];
  
  for(size_t i = 0; i < 1000; i++)
  {
    quaternionArr[i].x = i/10.0;
    quaternionArr[i].y = i/10.0;
    quaternionArr[i].z = i/10.0;

    angularVelocityArr[i].x = i/10.0;
    angularVelocityArr[i].y = i/10.0;
    angularVelocityArr[i].z = i/10.0;

    linearAccelerationCovarianceArr[i].x = i/10.0;
    linearAccelerationCovarianceArr[i].y = i/10.0;
    linearAccelerationCovarianceArr[i].z = i/10.0;
  }  

  //don't forget to connect this!!

  Publisher chatter_pub = n.advertise<sensor_msgs::Imu>("/accelerometer/imu/sim", 1000);

  Rate loop_rate(10);

  int count = 0;
  while (ok())
  {
    sensor_msgs::Imu msg;
    msg.orientation = quaternionArr[count];
    msg.angular_velocity = angularVelocityArr[count];
    msg.linear_acceleration = linearAccelerationCovarianceArr[count];

    //ROS_INFO("%f", msg.linear_acceleration.x);
    ROS_INFO("%lu", sizeof(msg) );
    chatter_pub.publish(msg);

    spinOnce();

    loop_rate.sleep();
    ++count;
  }


  return 0;
}

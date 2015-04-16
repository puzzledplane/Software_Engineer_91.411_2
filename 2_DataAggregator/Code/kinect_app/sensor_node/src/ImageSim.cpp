/**
 * File: ImageSIm.cpp
 * Author: James Kuczynski
 * Email: jkuczyns@cs.uml.edu
 * File Description: This program is a ROS publisher.  It publishes simulated "kinect" device
 *  		     messages of type sensor_msgs/Image
 *
 * Created: 04/01/2015 1:15am
 */

#include <ros/ros.h>
#include <sensor_msgs/Image.h>
#include <std_msgs/UInt32.h>

using namespace ros;

int main(int argc, char **argv)
{
  init(argc, argv, "talker");
  
  ROS_INFO("Beginning \"Kinect\"-type image simulation...");

  NodeHandle n;
  
  //create array of Vector3 points to simulate rgb fields.
  std_msgs::UInt32 dataArr[1000][1000];
  
  for(size_t i = 0; i < 1000; i++)
  {
    for(size_t k = 0; k < 1000; k++)
    {
      dataArr[i][k].data = 0;
      dataArr[i][k].data = 0;
    }
  }  
  //don't forget to connect this!!

  Publisher chatter_pub = n.advertise<sensor_msgs::Image>("/camera/image/sim", 1000);

  Rate loop_rate(10);

  int count = 0;
  while (ok())
  {
    sensor_msgs::Image msg;
    msg.height = 0;
    msg.width = 0;

    ROS_INFO("%d", msg.height);
    chatter_pub.publish(msg);

    spinOnce();

    loop_rate.sleep();
    ++count;
  }


  return 0;
}

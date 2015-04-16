###**Software Engineering I Term Project**
![Logo](https://github.com/DeepBlue14/Software_Engineer_91.411_2/blob/master/2_DataAggregator/Code/kinect_app/app_node/share/se_logo.png)


*Authors*:  
James Kuczynski, James_Kuczynski@student.uml.edu  
Michael Forsyth, Michael_Forsyth@student.uml.edu  
Nicholas Forsyth, Nicholas_Forsyth@student.uml.edu  
Neel Tripathi, Neel_Tripathi@student.uml.edu  
Robert Vecchione, Robert_Vecchione@student.uml.edu  


####**Index**
- Project Synopsis
- Dependencies
- Installation (Linux/ROS Version)
- Build & Run: GUI Frontend--IDEs
- Build & Run: Entire Project
- Build & Run: Execution




####**Project Synopsis**
Robotic sensor administration application interface framework.  The final goal of this project is to create a [ROS][1]-based system to allow interactive communication between a sensor device and a cloud.  It is being developed for [Ubuntu][5] 12.04-15.04, although it should run on other UNIX/Linux-based systems.  This package also includes basic simulated TCP/IP message topics for imu (accelerometer), compass, image, and pointcloud types. 
**Warning: This project is currently in a Beta phase.  Expected completion date is May 4 2015.**
**Warning: Installer scripts have not yet been fully tested.  Since they make modifications on an operating systems level, we do not advice using them at this point.**


####**Dependencies**
- [Ubuntu][5] 12.04-15.04
- [ROS][1] hydro or later (catkin)
- [QT4][3] Project
- [QGLViewer][8]
- [QJson][7]
- [Boost][4]
- [SQLite][6] Database



####**Installation (Linux/ROS Version)**

Follow the instructions for installing [ROS][1].  It is strongly advised to choose
the ```ros-<version>-desktop-full``` option to install all necessary ROS packages. 
*Note: This step is not necessary for running the **frontend** or **prototype**.*

Install additional packages via ros:
```
sudo apt-get install ros-indigo-sound*
sudo apt-get install ros-indigo-pocketsphinx
```

Install pocketsphinx dependency:
```
sudo apt-get install gstreamer0.10-gconf
```


Install the [Boost][4] C++ libraries:
```
sudo apt-get install libboost-all-dev
```

Install [QT4][3]:
```
sudo apt-get install libqt4-*
```

Install [QGLViewer][8]:
```
sudo apt-get install libqglviewer2 libqglviewer-dev
```

Now you must make some modifications so it can be compiled
with CMake: ```sudo vim /usr/include/QGLViewer/vec.h```.  Now change
```#include <QDomElement>``` to ```#include <QtXml/QDomElement>```.
Then save and quit.  Next, run ```sudo vim /usr/include/QGLViewer/config.h```.
Change ```#include <QGLWidget>``` to ```#include <QtOpenGL/QGLWidget>```.

Install [QJson][7]
```
sudo apt-get install libqjson0 libqjson-*
```

Install [SQLite][6]
```
sudo apt-get install sqlite3 libsqlite3-dev
```



####**Build & Run**

#####**GUI Frontend--IDEs**

*Note: This option allows the user to run the GUI frontend only.  It does not include the simulators or other modules.  This was tested on the NetBeans IDE.*
Install an IDE of your choice.
Go to an apropriate location and run:
```
git clone https://github.com/DeepBlue14/sensor-admin.git
```

- Run IDE
- Open ```sensor_admin_NB```
- Build & Run

*This project has **ONLY** been tested on the NetBeans IDE.  If you are using an IDE that cannot process CMake files, you may have to manually link against the dependencies (this is NOT nessisary for NetBeans):*
```
QtCore
QtGui
QtWidgets
QNetwork
QtOpenGL
QtSql
QtXml

boost_system
boost_filesystem
boost_regex
qjson
QGLViewer
sqlite3
```


#####**Entire Project**

Set up a ROS workspace:
```
mkdir -p ~/se_ws/src
cd ~/se_ws
catkin_init_workspace
catkin_make
```

Clone the package:
```
cd ~/se_ws/src
git clone https://github.com/DeepBlue14/sensor-admin.git
cd ~/se_ws
source devel/setup.bash
catkin_make
```

####**Execution**

#####**1) Individual Nodes**

Frontend:
```
roscore
rosrun app_node main
```


Speech responsive node:
```
roslaunch speech_node voice_nav_commands.launch
rosrun sound_play soundplay_node.py
rosrun speech_node ManageNodeStatus
```


#####**2) Launch Files**

*(not yet implimented)*
```

```


#####**3) Simulations**

There are several sensor simulations.

Accelerometer simulator will publish ```sensor_msgs/Imu``` to
```/accelerometer/imu/sim```.  It will also print the linear acceleration
x field:
```
rosrun sensor_node AccelerometerSim
```

Image data:
```
rosrun sensor_node ImageSim
```

PointCloud2:
```
rosrun sensor_node PointCloud2Sim
```

Magnetometer:
```
rosrun sensor_node MagnetometerSim
```






<!--links-->

[1]: http://ros.org/
[2]: https://github.com/DeepBlue14/Software_Engineer_91.411_2/blob/master/2_DataAggregator/Code/kinect_app/app_node/scripts/Install.bash
[3]: http://qt-project.org/
[4]: http://www.boost.org/
[5]: http://www.ubuntu.com/
[6]: https://sqlite.org/
[7]: http://qjson.sourceforge.net/
[8]: http://www.libqglviewer.com/


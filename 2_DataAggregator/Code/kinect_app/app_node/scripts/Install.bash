##########################################################
##							##
## File: Ros_Install.bash				##
## Author: James Kuczynski				##
## Email: jkuczyns@cs.uml.edu				##
## File Description: Installer file for prototype.	##
##							##
## Created: April 4 2015 1:35pm				##
##							##
##########################################################

#!/bin/bash

ICON="sensor_admin_NB/se_logo.xpm"
EXEC="sensor_admin_NB/dist/Debug/GNU-Linux-x86/sensor_admin_NB"

echo "Do you want this script to install dependencies (Y/n)?"
read DEPS

if [ "$DEPS" == "n" ] || [ "$DEPS" == "N" ]; then
    echo "Make sure to manually install dependencies"
else
    echo "Installing packages..."
    #sudo apt-get install libboost-all-dev
    #sudo apt-get install libqt4-*
    #sudo apt-get install libqjson0 libqjson-*
    #sudo apt-get install sqlite3 libsqlite3-dev
fi

echo "Enter absolute path to the location you want this installed."
echo "(press [ENTER] to choose default location: ~/)"
read LOC

if ["$LOC" = ""]; then
    LOC="~/"
fi

mkdir $(LOC)/sensor-admin
cd $(LOC)/sensor-admin
git clone https://github.com/DeepBlue14/sensor-admin.git

#build CMakeLists:
DIR=pwd
sed -i 's/'$(DIR)'/beautiful/g' ./SoftEng.desktop
chmod +x SoftEng.desktop
cp SoftEng.desktop ~/Desktop

echo "Instalation complete."



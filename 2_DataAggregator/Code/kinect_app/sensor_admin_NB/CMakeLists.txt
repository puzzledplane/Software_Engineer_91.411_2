cmake_minimum_required(VERSION 2.8.3)
project(frontend_ui)


## System dependencies are found with CMake's conventions
# find_package(Boost REQUIRED COMPONENTS system)
find_package(Boost REQUIRED COMPONENTS system filesystem regex)

find_package(QJSON)

find_package(Qt4 REQUIRED COMPONENTS QtCore QtGui QtOpenGL QtSql QtXml)
include(${QT_USE_FILE})
ADD_DEFINITIONS(${QT_DEFINITIONS})

set(CMAKE_AUTOMOC ON)





###########
## Build ##
###########



#############
## Install ##
#############


add_executable(main src/main.cpp
	       	src/AddDeviceGui.cpp
		src/AddUserGui.cpp
		src/CenterGui.cpp
		src/DeviceAbstractGui.cpp
		src/DevicesGui.cpp
		src/HelpGui.cpp
		src/HistoryGui.cpp
		src/LoginGui.cpp
		src/MasterGui.cpp
		src/Menu.cpp
		src/ModifyDeviceGui.cpp
		src/ModifyUserGui.cpp
		src/OpeningGui.cpp
		src/ResultsGui.cpp
		src/SplashGui.cpp
		src/UserAbstractGui.cpp
		src/UsersGui.cpp
		src/VideoGui.cpp
		src/ViewUserGui.cpp)
target_link_libraries(main ${catkin_LIBRARIES})
target_link_libraries(main ${QT_LIBRARIES})
target_link_libraries(main ${Boost_LIBRARIES})
target_link_libraries(main ${QJson})


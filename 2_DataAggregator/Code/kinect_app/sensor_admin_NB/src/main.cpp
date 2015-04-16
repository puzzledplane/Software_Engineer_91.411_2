/*
 * File: main.cpp
 * Author: James Kuczynski
 * Email: jkuczyns@cs.uml.edu
 * File Description: 
 *
 * Created on March 7, 2015, 4:00mp
 */

#include <QApplication>

#include <iostream>
#include <cstdlib>

#include "SplashGui.h"
#include "LoginGui.h"
#include "CenterGui.h"
#include "Menu.h"
#include "MasterGui.h"
#include <QVector>

#include "Coder.h"
#include "LocalDBMaster.h"

using namespace std;

int main(int argc, char **argv)
{

    QApplication app(argc, argv);
    
    MasterGui masterGui;
    masterGui.show();
    
    //LocalDBMaster localDBMaster;
    //localDBMaster.connectDB();
    //localDBMaster.disconnectDB();
    
    return app.exec();
}
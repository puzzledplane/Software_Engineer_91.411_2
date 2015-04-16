/* 
 * File:   AddUserGui.h
 * Author: James Kuczynski
 * Email: jkuczyns@cs.uml.edu
 * File Description: This class provides an interface to allow the user to
 *                   register sensor devices.
 *
 * Created on April 3, 2015, 1:06 PM
 */

#ifndef ADD_Device_GUI_H
#define	ADD_Device_GUI_H

#include "DeviceAbstractGui.h"

using namespace std;

class AddDeviceGui : public DeviceAbstractGui
{
    Q_OBJECT
    
private:
    ;
    
private slots:
    ;
    
public:
    /**
     * Constructor.
     */
    AddDeviceGui();
    
    /**
     * Destructor.
     */
    ~AddDeviceGui();
    
};

#endif	/* ADD_Device_GUI_H */


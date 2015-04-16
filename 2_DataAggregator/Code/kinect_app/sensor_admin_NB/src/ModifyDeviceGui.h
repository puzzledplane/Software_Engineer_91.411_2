/* 
 * File:   ModifyDeviceGui.h
 * Author: James Kuczynski
 * Email: jkuczyns@cs.uml.edu
 * File Description: This class provides a GUI for the user to modify
 *                   the attributes of existing devices.  It inherits from
 *                   class DeviceAbstractGui.
 *
 * Created on April 4, 2015, 5:55 PM
 */

#ifndef MODIFY_DEVICE_GUI_H
#define	MODIFY_DEVICE_GUI_H

#include "DeviceAbstractGui.h"

using namespace std;

class ModifyDeviceGui : public DeviceAbstractGui
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
    ModifyDeviceGui();
    
    /**
     * Destructor.
     */
    ~ModifyDeviceGui();
    
};

#endif	/* MODIFY_DEVICE_GUI_H */

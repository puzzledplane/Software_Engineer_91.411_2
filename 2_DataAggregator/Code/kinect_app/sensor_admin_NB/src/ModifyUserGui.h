/* 
 * File:   ModifyUserGui.h
 * Author: James Kuczynski
 * Email: jkuczyns@cs.uml.edu
 * File Description: This class provides a GUI to allow the user to modify
 *                   his own attributes, or those of others if he is an
 *                   administrator.
 *
 * Created on April 4, 2015, 5:54 PM
 */

#ifndef MODIFY_USER_GUI_H
#define	MODIFY_USER_GUI_H

#include "UserAbstractGui.h"

using namespace std;

class ModifyUserGui : public UserAbstractGui
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
    ModifyUserGui();
    
    /**
     * Destructor.
     */
    ~ModifyUserGui();
    
};

#endif	/* MODIFY_USER_GUI_H */

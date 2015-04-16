/* 
 * File:   AddUserGui.h
 * Author: James Kuczynski
 * Email: jkuczyns@cs.uml.edu
 * File Description: This class provides an interface for the user to
 *                   register himself, or register others if he himself
 *                   is an administrator.
 *
 * Created on April 3, 2015, 1:59 PM
 */

#ifndef ADD_USER_GUI_H
#define	ADD_USER_GUI_H

#include "UserAbstractGui.h"

using namespace std;

class AddUserGui : public UserAbstractGui
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
    AddUserGui();
    
    /**
     * Destructor.
     */
    ~AddUserGui();
    
};


#endif	/* ADD_USER_GUI_H */


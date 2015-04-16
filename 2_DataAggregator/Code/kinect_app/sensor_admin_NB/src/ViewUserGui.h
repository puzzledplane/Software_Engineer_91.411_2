/* 
 * File:   ViewUser.h
 * Author: James Kuczynski
 * Email: jkuczyns@cs.uml.edu
 * File Description: This class provides a GUI to display the attributes of
 *                   a specified user.
 *
 * Created on April 7, 2015, 4:31 PM
 */

#ifndef VIEW_USER_GUI_H
#define	VIEW_USER_GUI_H

#include "UserAbstractGui.h"

using namespace std;

class ViewUserGui : public UserAbstractGui
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
    ViewUserGui();
    
    /**
     * Destructor.
     */ 
    ~ViewUserGui();
    
};

#endif	/* VIEW_USER_GUI_H */


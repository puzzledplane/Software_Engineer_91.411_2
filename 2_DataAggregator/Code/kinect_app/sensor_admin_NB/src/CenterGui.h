/* 
 * File:   GeneralGui.h
 * Author: James Kuczynski
 * Email: jkuczyns@cs.uml.edu
 * File Description: This class provides the GUI which is loaded upon user
 *                   login.  It will display the last login date and other
 *                   attributes.
 *
 * Created on April 4, 2015, 10:05 PM
 */

#ifndef GENERAL_GUI_H
#define	GENERAL_GUI_H

#include <QWidget>
#include <QLabel>
#include <QTextEdit>
#include <QGridLayout>

class CenterGui : public QWidget
{
    Q_OBJECT
            
private:
    /**
     * Pointer to a QLabel prompt for the user's username.
     */
    QLabel* usernameLbl;
    
    /**
     * Pointer to a QLabel displaying the user's last login date/time.
     */
    QLabel* lastLoginLbl;
    
    /**
     * Pointer to a QLabel displaying the user's list of exercises.
     */
    QLabel* exercisesLbl;
    
    /**
     * Pointer to a QGridLayout which will be the base layout.
     */
    QGridLayout* outerLayout;
    
public:
    /**
     * Constructor.
     * @param parent pointer to instance of virtual parent class.
     */
    CenterGui(QWidget* parent = 0);
    
    /**
     * Destructor.
     */
    ~CenterGui();
        
    
};

#endif	/* GENERAL_GUI_H */

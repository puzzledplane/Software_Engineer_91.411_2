/* 
 * File: MasterGui.h
 * Author: James Kuczynski
 * Email: jkuczyns@cs.uml.edu
 * File Description: This class will serve as the "master" class.  It will
 *                   handle the control flow of the program.
 * 
 * References: http://doc.qt.digia.com/qq/qq16-background.html
 *
 * Created on April 2, 2015, 9:38 PM
 */

#ifndef MASTER_GUI_H
#define	MASTER_GUI_H

#include <QWidget>
#include <QDesktopWidget>
#include <QRect>
#include <QPushButton>
#include <QTabWidget>
#include <QToolBar>
#include <QGridLayout>

#include <iostream>

#include "AppStyles.h"
#include "OpeningGui.h"
#include "UserAbstractGui.h"
#include "LoginGui.h"
#include "CenterGui.h"
#include "VideoGui.h"
#include "ResultsGui.h"
#include "UsersGui.h"
#include "DevicesGui.h"
#include "HistoryGui.h"
#include "HelpGui.h"

using namespace std;

class MasterGui : public QWidget
{
    Q_OBJECT
    
private:
    OpeningGui* openingGui; /**Pointer to object of class OpeningGui.*/
    UserAbstractGui* userAbstractGui; /**Pointer to object of class UserAbstractGui.*/
    LoginGui* loginGui; /**Pointer to object of class LoginGui.*/
    CenterGui* centerGui; /**Pointer to object of class CenterGui.*/
    VideoGui* videoGui; /**Pointer to object of class VideoGui.*/
    ResultsGui* resultsGui; /**Pointer to object of class ResultsGui.*/
    UsersGui* usersGui; /**Pointer to object of class UsersGui.*/
    DevicesGui* devicesGui; /**Pointer to object of class DevicesGui.*/
    HistoryGui* historyGui; /**Pointer to object of class HistoryGui.*/
    HelpGui* helpGui; /**Pointer to object of class HelpGui.*/
    
    QPushButton* signUpBtn; /**Button to allow the user without existing account to sign up to application.*/
    QPushButton* signInBtn; /**Button to allow the user with existing account to sign in.*/
    QPushButton* registerBtn; /**Button to allow the user to register after selecting signUpBtn and entering his/her data.*/
    QPushButton* backBtn; /**Button to return to original signup/signin menu if he/she selects signUp and then changes mind.*/
    QPushButton* cancel0Btn; /**Button to exit the application.*/
    QPushButton* loginBtn; /**Button to initiate username/password verification.*/
    QPushButton* cancelBtn; /**Button to exit the application.*/
            
    QToolBar* toolbar; /**Toolbar to allow the user to swap pages.*/
    QPushButton* activateBtn; /**Button to initiate activation of the device.*/
    QPushButton* videoBtn; /**Button to initiate loading of the video page.*/
    QPushButton* resultsBtn; /**Button to initiate loading of the results page.*/
    QPushButton* usersBtn; /**Button to initiate loading of the users page.*/
    QPushButton* devicesBtn; /**Button to initiate loading of the devices page.*/
    QPushButton* historyBtn; /**Button to initiate loading of the history page.*/
    QPushButton* helpBtn; /**Button to execute the help GUI.*/
    QPushButton* exitBtn; /**Button to gracefully exit the application.*/
    
    QPushButton* toolbarViewBtn; /**Button to show/hide the tool-bar.*/
    bool isVisable; /**Variable to control if the tool-bar is currently visible.*/
    
    QHBoxLayout* registerBtnLayout; /**Layout the Register button.*/
    QHBoxLayout* loginBtnLayout; /**Layout to contain the LoginGui object and login buttons.*/
    QGridLayout* outerLayout; /**Base layout to be loaded directly to GUI.*/
    
    enum Page /**Enums to represent pages.*/
    {
        SPLASH_GUI,
        OPENING_GUI,
        SIGNUP_GUI,
        LOGIN_GUI,
        CENTER_GUI,
        VIDEO_GUI,
        RESULTS_GUI,
        USERS_GUI,
        DEVICES_GUI,
        HISTORY_GUI
    };
    
    Page currentPage; /**The current page loaded/displayed.*/
    
private slots:
    void handleSignUpBtnSlot(); /**Slot to handle the "Sign Up" button.*/
    void handleSignInBtnSlot(); /**Slot to handle the "Sign In" button.*/
    void handleLoginBtnSlot(); /**Slot to handle the "Login" button.*/
    void handleRegisterBtnSlot(); /**Slot to handle the "Register" button*/
    void handleBackBtnSlot(); /**Slot to handle the "Back" button.*/
    void handleCancel0BtnSlot(); /**Slot to handle a "Cancel" button.*/
    void handleCancelBtnSlot(); /**Slot to handle a "Cancel" button.*/
    void handleActivateBtnSlot(); /**Slot to handle a "Activate" button.*/
    void handleVideoBtnSlot(); /**Slot to handle the "Video" button.*/
    void handleResultsBtnSlot(); /**Slot to handle the "Results" button.*/
    void handleUsersBtnSlot(); /**Slot to handle the "Users" button.*/
    void handleDevicesBtnSlot(); /**Slot to handle the "Devices" button.*/
    void handleHistoryBtnSlot(); /**Slot to handle the "History" button.*/
    void handleHelpBtnSlot(); /**Slot to handle the "Help" button.*/
    void handleExitBtnSlot(); /**Slot to handle the "Exit" button.*/
    void handleToolbarViewBtnSlot(); /**Slot to handle the button which reveals/hides the toolbar.*/
    
public:
    /**
     * Constructor.
     * @param parent Pointer to object of parent type QWidget.
     */
    MasterGui(QWidget* parent = 0);
    
    /**
     * Method to initialize the core; i.e. instantiate objects and load the base GUI.
     */
    void initCore();
    
    /**
     * Method to create and load the tool-bar.
     */
    void loadToolbar();
    
    /**
     * Method to control the flow of swapping pages.  It calls load/unload
     * helper methods.
     * @param newPage The new page to be loaded.
     */
    void switchPage(Page newPage);
    
    /**
     * Helper method to load the object of class OpeningGui.
     */
    void loadOpeningGui();
    
    /**
     * Helper method to unload the object of class OpeningGui and hide/set
     * un-editable the corresponding aforementioned object and appropriate buttons. 
     */
    void unloadOpeningGui();
    
    /**
     * Helper method to load the object of class UserAbstractGui.
     */
    void loadUserAbstractGui();
    
    /**
     * Helper method to unload the object of class UserAbstractGui and hide/set
     * un-editable the corresponding aforementioned object and appropriate buttons. 
     */
    void unloadUserAbstractGui();
    
    /**
     * Helper method to load the object of class LoginGui.
     */
    void loadLoginGui();
    
    /**
     * Helper method to unload the object of class LoginGui and hide/set
     * un-editable the corresponding aforementioned object and appropriate buttons. 
     */
    void unloadLoginGui();
    
    /**
     * Helper method to load the object of class CenterGui.
     */
    void loadCenterGui();
    
    /**
     * Helper method to unload the object of class CenterGui and hide/set
     * un-editable the corresponding aforementioned object and appropriate buttons. 
     */
    void unloadCenterGui();
    
    /**
     * Helper method to load the object of class VideoGui.
     */
    void loadVideoGui();
    
    /**
     * Helper method to unload the object of class VideoGui and hide/set
     * un-editable the corresponding aforementioned object and appropriate buttons. 
     */
    void unloadVideoGui();
    
    /**
     * Helper method to load the object of class ResultsGui.
     */
    void loadResultsGui();
    
    /**
     * Helper method to unload the object of class ResultsGui and hide/set
     * un-editable the corresponding aforementioned object and appropriate buttons. 
     */
    void unloadResultsGui();
    
    /**
     * Helper method to load the object of class UsersGui.
     */
    void loadUsersGui();
    
    /**
     * Helper method to unload the object of class UsersGui and hide/set
     * un-editable the corresponding aforementioned object and appropriate buttons. 
     */
    void unloadUsersGui();
    
    /**
     * Helper method to load the object of class DevicesGui.
     */
    void loadDevicesGui();
    
    /**
     * Helper method to unload the object of class DevicesGui and hide/set
     * un-editable the corresponding aforementioned object and appropriate buttons. 
     */
    void unloadDevicesGui();
    
    /**
     * Helper method to load the object of class HistoryGui.
     */
    void loadHistoryGui();
    
    /**
     * Helper method to unload the object of class HistoryGui and hide/set
     * un-editable the corresponding aforementioned object and appropriate buttons. 
     */    
    void unloadHistoryGui();
    
    /**
     * Destructor.
     */
    ~MasterGui();
            
    
};

#endif	/* MASTER_GUI_H */

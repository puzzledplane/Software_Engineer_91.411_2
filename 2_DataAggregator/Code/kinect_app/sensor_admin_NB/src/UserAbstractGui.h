/* 
 * File:   UserAbstractGui.h
 * Author: James Kuczynski
 * Email: jkuczyns@cs.uml.edu
 * File Description: This class provides a GUI to display user data.  This
 *                   class is inherited by several subclasses.
 *
 * Created on April 3, 2015, 4:53 PM
 */

#ifndef USER_ABSTRACT_GUI_H
#define	USER_ABSTRACT_GUI_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QString>
#include <QStringList>
#include <QComboBox>
#include <QTextEdit>
#include <QPushButton>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QGridLayout>

#include <iostream>

using namespace std;

class UserAbstractGui : public QWidget
{
    Q_OBJECT
    
private:
    QLineEdit* nameLe; /**Entry for user's name.*/
    QLineEdit* emailLe; /**Entry for user's email address.*/
    QLineEdit* usernameLe; /**Entry for users username.*/
    QLineEdit* passwordLe; /**Entry for user's password.*/
    QStringList* accountTypesLst; /**List of account types.*/
    QComboBox* accountTypeCb; /**Combobox to allow the user to select an account type.*/
    QLabel* retypePasswordLbl; /**Label to prompt the user to re-type the new password to varify it.*/
    QLineEdit* retypePasswordLe; /**Entry for the user to re-type the new password to varify it.*/
    QTextEdit* exerciesTe; /**Entry for the user to enter exercies(es).*/
    QTextEdit* noteTe; /**Entry for the user to enter notes about him/herself.*/
    QPushButton* okBtn; /**Button to save entered data and close child GUI.*/
    QPushButton* applyBtn; /**Button to save entered data without closing child GUI.*/
    QPushButton* cancelBtn; /**Button to close child GUI without saving data.*/
    
    QFormLayout* formLayout; /**Layout to contain lable/entry pairs.*/
    QHBoxLayout* buttonLayout; /**Layout to contain buttons relevent to this class.*/
    QGridLayout* outerLayout; /**Base layout to be entered directly to GUI.*/
    
private slots:
    void handlePasswordLeSlot(); /**Slot to load retypePassword fields when password is innitialy entered.*/
    void handleOkBtnSlot(); /**Slot to handle "OK" button.*/
    void handleApplyBtnSlot(); /**Slot to handle "Apply" button.*/
    void handleCancelBtnSlot(); /**Slot to handle "Cancel" button.*/
    
public:
    /**
     * Constructor.
     * @param parent Pointer to object of parent class type QWidget.
     */
    UserAbstractGui(QWidget* parent = 0);
    
    /**
     * Method to unload the default buttons.
     */ 
    void unloadDefaultBtns();
    
    /**
     * Destructor.
     */
    ~UserAbstractGui();
    
};

#endif	/* USER_ABSTRACT_GUI_H */

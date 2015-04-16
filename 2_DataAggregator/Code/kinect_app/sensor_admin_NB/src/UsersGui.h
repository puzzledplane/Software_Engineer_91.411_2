/* 
 * File:   UsersGui.h
 * Author: James Kuczynski
 * Email: jkuczyns@cs.uml.edu
 * File Description: This class provides a GUI to display attributes of
 *                   all registered users.
 *
 * Created on April 6, 2015, 7:57 PM
 */

#ifndef USERS_GUI_H
#define	USERS_GUI_H

#include <QWidget>
#include <QVector>
#include <QStringList>
#include <QTableWidget>
#include <QPushButton>
#include <QComboBox>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QMessageBox>

#include <iostream>

#include "AddUserGui.h"
#include "ModifyUserGui.h"

using namespace std;

class UsersGui : public QWidget
{
    Q_OBJECT
    
private: 
    AddUserGui* addUserGui; /**Pointer to object of type AddUserGui.*/
    ModifyUserGui* modifyUserGui; /**Pointer to object of type ModifyUserGui.*/
    
    QMessageBox* verifyMessageBox; /**Messagebox to prompt verification of user action.*/
    
    QStringList* tableStrLst; /**List of users' data.*/
    //QVector<QPushButton*>* tableButtonVec;
    //QVector<QComboBox*>* tableComboBoxVec;
    QTableWidget* tableWidget; /**Table to display users' data.*/
    QPushButton* addBtn; /**Button to initiate the adding of a new user.*/
    QPushButton* modifyBtn; /**Button to initiate the modification of a pre-existing user.*/
    QPushButton* removeBtn; /**Button to initiate the removal of a user.*/
    QHBoxLayout* buttonLayout; /**Layout to contain buttons relevent to this class.*/
    QGridLayout* outerLayout; /**Base layout to be loaded directly to the GUI.*/
    
private slots:
    void handleMoreBtnSlot(); /**Slot to handle "More" button.*/
    void handleAddBtnSlot(); /**Slot to handle "Add" button.*/
    void handleModifyBtnSlot(); /**Slot to handle "Modify" button.*/
    void handleRemoveBtnSlot(); /**Slot to handle "Remove" button.*/
    
public:
    /**
     * Constructor.
     * @param parent Pointer to object of parent class type QWidget.
     */
    UsersGui(QWidget* parent = 0);
    
    /**
     * Destructor.
     */
    ~UsersGui();
        
};

#endif	/* USERS_GUI_H */


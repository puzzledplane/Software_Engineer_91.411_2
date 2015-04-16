/* 
 * File:   Devices.h
 * Author: James Kuczynski
 * Email: jkuczyns@cs.uml.edu
 * File Description: This class provides an interface to display the device
 *                   data in table format. 
 *
 * Created on April 3, 2015, 8:03 PM
 * 
 * References: http://stackoverflow.com/questions/6957943/how-to-add-new-row-to-existing-qtablewidget
 */

#ifndef DEVICES_GUI_H
#define	DEVICES_GUI_H

#include <QWidget>
#include <QVector>
#include <QStringList>
#include <QTableWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QMessageBox>

#include <iostream>

#include "AddDeviceGui.h"
#include "ModifyDeviceGui.h"

using namespace std;

class DevicesGui : public QWidget
{
    Q_OBJECT
    
private:
    AddDeviceGui* addDeviceGui; /**Pointer to object of class AddDeviceGui.*/
    ModifyDeviceGui* modifyDeviceGui; /**Pointer to object of class ModifyDeviceGui.*/
    
    QMessageBox* verifyMessageBox; /**Mesage box to ask user to verify data before saving entries.*/
    
    QStringList* tableStrLst; /**List of device data.*/
    QTableWidget* tableWidget; /**Table to display device data.*/
    QPushButton* addBtn; /**Button to add new device data.*/
    QPushButton* modifyBtn; /**Button to submit modifyed device data.*/
    QPushButton* removeBtn; /**Button to remove device data.*/
    QHBoxLayout* buttonLayout; /**Layout to contain buttons contained in this class.*/
    QGridLayout* outerLayout; /**Base layout added directly to the class.*/
    
private slots:
    /**
     * Slot to save data of a new device when "Add" button is selected.
     */
    void handleAddBtnSlot();
    
    /**
     * Slot to save modified data of a pre-existing device when "Modify"
     * button is selected.
     */
    void handleModifyBtnSlot();
    
    /**
     * Slot to remove the data of a device when "Remove" button is selected.
     */
    void handleRemoveBtnSlot();
    
public:
    /**
     * Constructor.
     * @param parent Pointer to object of parent class QWidget.
     */
    DevicesGui(QWidget* parent = 0);
    
    /**
     * Destructor.
     */
    ~DevicesGui();
        
};

#endif	/* DEVICES_GUI_H */


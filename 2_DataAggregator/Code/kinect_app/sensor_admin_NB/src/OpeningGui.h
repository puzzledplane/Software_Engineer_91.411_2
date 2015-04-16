/* 
 * File:   OpeningGui.h
 * Author: James Kuczynski
 * Email: jkuczyns@cs.uml.edu
 * File Description: This file provides the GUI which appears on startup.
 *
 * Created on April 3, 2015, 11:35 PM
 */

#ifndef OPENINGGUI_H
#define	OPENINGGUI_H

#include <QtGui>
#include <QDialog>
#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include <QLineEdit>
#include <QPushButton>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QGridLayout>

class OpeningGui : public QWidget
{
    Q_OBJECT

private:
    QLabel* titleLbl; /**Title of this sub-GUI.*/
    QLabel* imageFieldLbl; /**Icon of this project.*/


    QHBoxLayout* buttonLayout; /**Layout to contain buttons relating to this GUI.*/
    QGridLayout* outerLayout; /**Base layout to be loaded directly to the GUI.*/

public:
    /**
     * Constructor.
     * @param parent Pointer to object of parent class type QWidget.
     */
    OpeningGui(QWidget* parent = 0);
    
    /**
     * This method handles the control flow of this class.
     */ 
    void OpeningGuiMaster();
    
    /**
     * Destructor.
     */
    ~OpeningGui();

};


#endif	/* OPENINGGUI_H */

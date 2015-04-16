/* 
 * File:   Menu.h
 * Author: James Kuczynski
 * Email: jkuczyns@cs.uml.edu
 * File Description: This is a "sandbox" class, used to test style sheets and
 *                   other design features.
 *
 * Created on April 2, 2015, 1:21 AM
 */

#ifndef MENU_H
#define	MENU_H

#include <QtGui>
#include <QPushButton>
#include <QMenuBar>
#include <QVBoxLayout>

#include <QVector>

using namespace std;

class Menu : public QWidget
{
    Q_OBJECT
            
private:
    QVector<QPushButton*> menuBtnVec; /**Vector of buttons contained in the menu-bar.*/
    QMenuBar* menubar; /**Pointer to menu-bar.*/
    QVBoxLayout* menuLayout; /**Layout to contain menu-bar.*/
    
private slots:
    ;
    
public:
    /**
     * Constructor.
     * @param parent Pointer to object of parent class type QWidget.
     */
    Menu(QWidget* parent = 0);
    
    /**
     * Method to load the menu into the frame.
     * @param btnNameVec Vector of buttons to be loaded into the menu-bar.
     */
    void loadMenu(QVector<QString> btnNameVec);
    
    /**
     * Destructor.
     */
    ~Menu();
    
    
};

#endif	/* MENU_H */

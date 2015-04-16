/* 
 * File:   HelpGui.h
 * Author: James Kuczynski
 * Email: jkuczyns@cs.uml.edu
 * File Description: This class provides a GUI for some basic user assistance,
 *                   including external links.
 *
 * Created on April 2, 2015, 8:07 PM
 */

#ifndef HELP_GUI_H
#define	HELP_GUI_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QHBoxLayout>

#include <iostream>
using namespace std;


class HelpGui : public QWidget
{
    Q_OBJECT
    
private:
    QLabel* titleLbl; /**Title of Help GUI.*/
    QLabel* contentLbl; /**Index of pages in Help GUI.*/
    
    int pageNum; /**Number of current page in Help GUI.*/
    const int NUM_OF_PAGES; /**Number of pages in Help GUI*/
    
    QPushButton* previousPb; /**Button to load previous page.*/
    QPushButton* nextPb; /**Button to load next page.*/
    QPushButton* exitPb; /**Button to close Help GUI.*/
    
    QGridLayout* outerLayout; /**Base layout to be loaded directly into Help GUI.*/
    QHBoxLayout* buttonLayout; /**Layout to contain buttons of this class.*/
    
private slots:
    /**
     * Slot for when "Previous" button is selected.
     */
    void handlePreviousBtnSlot();
    
    /**
     * Slot for when "Next" button is selected.
     */
    void handleNextBtnSlot();
    
    /**
     * Slot for when "Exit" button is selected.
     */
    void handleExitBtnSlot();
    
public:
    /**
     * Constructor.
     * @param parent Pointer to object of parent type.
     * @param numOfPages Constant number of pages of Help GUI.
     */
    explicit HelpGui(QWidget* parent = 0, int numOfPages = 4);
    
    /**
     * "Master" type method to control the switching of pages.
     * @param pageNum New page number to be loaded.
     */
    void managePages(int pageNum);
    
    /**
     * Method to load page one.
     */
    void loadPageOne();
    
    /**
     * Method to load page two.
     */
    void loadPageTwo();
    
    /**
     * Method to load page three.
     */
    void loadPageThree();
    
    /**
     * Method to load page four.
     */
    void loadPageFour();
    
    /**
     * Destructor.
     */
    ~HelpGui();
    
};

#endif	/* HELP_GUI_H */


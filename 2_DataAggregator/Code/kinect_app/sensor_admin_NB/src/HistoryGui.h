/* 
 * File:   HistoryGui.h
 * Author: James Kuczynski
 * Email: jkuczyns@cs.uml.edu
 * File Description: This class provides a GUI for displaying previous results.
 *
 * Created on April 5, 2015, 8:05 PM
 */

#ifndef HISTORY_GUI_H
#define	HISTORY_GUI_H

#include <QWidget>
#include <QGridLayout>

class HistoryGui : public QWidget
{
    Q_OBJECT
    
private:
    QGridLayout* outerLayout; /**Base layout to be loaded directly to GUI.*/
    
private slots:
    ;
    
public:
    /**
     * Constructor.
     * @param parent Pointer to object of parent type QWidget.
     */
    HistoryGui(QWidget* parent = 0);
    
    /**
     * Destructor.
     */
    ~HistoryGui();
        
};

#endif	/* HISTORY_GUI_H */

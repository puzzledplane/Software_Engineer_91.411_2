/* 
 * File:   Results.h
 * Author: James Kuczynski
 * Email: jkuczyns@cs.uml.edu
 * File Description: This class provides a GUI to display results of this
 *                   current run.
 *
 * Created on April 5, 2015, 7:47 PM
 */

#ifndef RESULTS_H
#define	RESULTS_H

#include <QWidget>
#include <QGridLayout>

class ResultsGui : public QWidget
{
    Q_OBJECT
    
private:
    QGridLayout* outerLayout; /**Base layout to be loaded directly into the GUI.*/
    
private slots:
    ;
    
public:
    /**
     * Constructor.
     * @param parent Pointer to object of parent class type QWidget.
     */
    ResultsGui(QWidget* parent = 0);
    
    /**
     * Destructor.
     */
    ~ResultsGui();
        
};

#endif	/* RESULTS_H */

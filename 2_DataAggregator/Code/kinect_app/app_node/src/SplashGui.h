/* 
 * File:   SplashGui.h
 * Author: James Kuczynski
 * Email: jkuczyns@cs.uml.edu
 * File Description: This class provides a splash screen. Note: thus far,
 *                   the application loads fast enough that we have not
 *                   yet found it necessary to enable this feature.
 *
 * References: http://ajaxload.info/
 * 
 * Created on April 2, 2015, 8:36 PM
 */

#ifndef SPLASHGUI_H
#define	SPLASHGUI_H

#include <QWidget>
#include <QPixmap>
#include <QSplashScreen>
#include <QMovie>
#include <QLabel>

class SplashGui : public QWidget
{
    Q_OBJECT
    
private:
    QPixmap* imagePxmp; /**Application icon.*/
    QSplashScreen* splash; /**Splash screen.*/
    QMovie* animation; /**Animation while loading app.*/
    QLabel* animationLbl; /**label to contain animation.*/
    
public:
    /**
     * Constructor.
     * @param parent Pointer to object of parent class type QWidget.
     */
    SplashGui(QWidget* parent = 0);
    
    /**
     * Destructor.
     */
    ~SplashGui();
};

#endif	/* SPLASHGUI_H */


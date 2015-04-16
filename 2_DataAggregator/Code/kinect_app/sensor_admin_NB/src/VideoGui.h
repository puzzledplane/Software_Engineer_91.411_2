/* 
 * File: VideoGui.h
 * Author: James Kuczynski
 * Email: jkuczyns@cs.uml.edu
 * File Description: This class provides an GUI to display video feeds, both
 *                   image and point cloud. 
 *
 * Created on April 8, 2015, 12:16 AM
 */

#ifndef VIDEO_GUI_H
#define	VIDEO_GUI_H

#include <QWidget>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>
#include <QVector>
#include <QVBoxLayout>
//#include <QMap>
//# include <QClipboard>
//#include <qglobal.h>
//#include <QGLViewer/qglviewer.h>

#include <iostream>

using namespace std;

class VideoGui : public QWidget
{
    Q_OBJECT
            
private:
    QLabel* imageLbl; /**Image stream label.*/
    QLabel* pointcloudLbl; /**Pointcloud stream label.*/
    QTextEdit* imageTe; /**Temp for where the image stream will be.*/
    QTextEdit* pointcloudTe; /**Temp field for where the point cloud stream will be.*/
    
    QGridLayout* outerLayout; /**Base layout to be loaded directly into GUI.*/
    
private slots:
    ;
    
    
public:
    /**
     * Constructor.
     * @param parent Pointer to object of parent class type QWidget.
     */
    VideoGui(QWidget* parent = 0);
    
    /**
     * Destructor.
     */
    ~VideoGui();
    
    
};

#endif	/* VIDEO_GUI_H */


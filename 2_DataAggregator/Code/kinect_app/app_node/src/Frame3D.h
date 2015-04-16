/*
 * File: Frame3D.h
 * Author: James Kuczynski
 * Email: jkuczyns@cs.uml.edu
 * File Description: 3D frame using QT's OpenGL module to contain pointclouds.
 *
 * Created: April 8 2015 2:20pm
 */

#ifndef FRAME3D_H
#define FRAME3D_H

#include <QGLViewer/qglviewer.h>

class Viewer : public QGLViewer
{
protected :
  virtual void draw();
  virtual void init();
  virtual QString helpString() const;
};

#endif /* FRAME3D_H */

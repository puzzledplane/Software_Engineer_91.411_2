#include "VideoGui.h"

VideoGui::VideoGui(QWidget* parent) : QWidget(parent)
{   
    imageLbl = new QLabel("Image", this);
    pointcloudLbl = new QLabel("Pointcloud", this);
    
    imageTe = new QTextEdit();
    pointcloudTe = new QTextEdit();
    
    outerLayout = new QGridLayout(this);
    outerLayout->addWidget(imageLbl, 0, 0);
    outerLayout->addWidget(imageTe, 1, 0);
    outerLayout->addWidget(pointcloudLbl, 0, 1);
    outerLayout->addWidget(pointcloudTe, 1, 1);
    
    this->setLayout(outerLayout);
}


VideoGui::~VideoGui()
{
    ;
}

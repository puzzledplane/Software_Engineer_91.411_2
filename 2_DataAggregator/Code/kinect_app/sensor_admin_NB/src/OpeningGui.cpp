#include "OpeningGui.h"

OpeningGui::OpeningGui(QWidget* parent) : QWidget(parent)
{
    titleLbl = new QLabel("<b>Sensor Management Center</b>", this);
    imageFieldLbl = new QLabel("Sensor Management Center", this);
    QPixmap iconPm("se_logo.xpm");
    imageFieldLbl->setPixmap(iconPm);
    iconPm.scaled(100, 75, Qt::IgnoreAspectRatio, Qt::FastTransformation);


    outerLayout = new QGridLayout();


    outerLayout->addWidget(titleLbl, 0, 0, Qt::AlignHCenter);
    outerLayout->addWidget(imageFieldLbl, 1, 0, 2, 0, Qt::AlignHCenter); 

    this->setLayout(outerLayout);
}


void OpeningGui::OpeningGuiMaster()
{
    ;
}


OpeningGui::~OpeningGui()
{
    ;
}

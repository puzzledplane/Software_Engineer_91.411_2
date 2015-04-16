#include "ResultsGui.h"


ResultsGui::ResultsGui(QWidget* parent) : QWidget(parent)
{
    outerLayout = new QGridLayout();
    
    
    this->setLayout(outerLayout);
}


ResultsGui::~ResultsGui()
{
    ;
}

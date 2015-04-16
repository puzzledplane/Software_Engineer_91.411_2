#include "HistoryGui.h"


HistoryGui::HistoryGui(QWidget* parent) : QWidget(parent)
{
    outerLayout = new QGridLayout();
    
    
    this->setLayout(outerLayout);
}


HistoryGui::~HistoryGui()
{
    ;
}

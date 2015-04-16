#include "DeviceAbstractGui.h"


DeviceAbstractGui::DeviceAbstractGui(QWidget* parent) : QWidget(parent)
{
    typeLe = new QLineEdit();
    idLe = new QLineEdit();
    ipAddressLe = new QLineEdit();
    preferenceCb = new QCheckBox();
    noteTe = new QTextEdit();
    
    okBtn = new QPushButton("OK", this);
    applyBtn = new QPushButton("Apply", this);
    cancelBtn = new QPushButton("Cancel", this);
    
    formLayout = new QFormLayout();
    formLayout->addRow(tr("&Type"), typeLe);
    formLayout->addRow(tr("&ID"), idLe);
    formLayout->addRow(tr("&IP Address"), ipAddressLe);
    formLayout->addRow(tr("&Preference"), preferenceCb);
    formLayout->addRow(tr("&Note"), noteTe);
    
    buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(okBtn);
    buttonLayout->addWidget(applyBtn);
    buttonLayout->addWidget(cancelBtn);
    
    outerLayout = new QGridLayout();
    outerLayout->addLayout(formLayout, 0, 0);
    outerLayout->addLayout(buttonLayout, 1, 0, Qt::AlignRight);
    
    this->setLayout(outerLayout);
}


void DeviceAbstractGui::handleOkBtnSlot()
{
    cout << "\"Ok\" button pressed" << endl;
}


void DeviceAbstractGui::handleApplyBtnSlot()
{
    cout << "\"Apply\" button pressed" << endl;
}


void DeviceAbstractGui::handleCancelBtnSlot()
{
    cout << "\"Cancel\" button pressed" << endl;
}


DeviceAbstractGui::~DeviceAbstractGui()
{
    ;
}

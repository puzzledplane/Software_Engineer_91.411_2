#include "DevicesGui.h"


DevicesGui::DevicesGui(QWidget* parent) : QWidget(parent)
{
    addDeviceGui = new AddDeviceGui();
    modifyDeviceGui = new ModifyDeviceGui();
    
    verifyMessageBox = new QMessageBox();
    verifyMessageBox->setText("<qt>The specified action is <b>irrevocable.</b><qt>");
    verifyMessageBox->setInformativeText("<qt>\nAre you sure you would like to continue?</qt>");
    verifyMessageBox->setStandardButtons(QMessageBox::No | QMessageBox::Yes);
    verifyMessageBox->setDefaultButton(QMessageBox::No);
    verifyMessageBox->setIcon(QMessageBox::Warning);
    
    
    tableStrLst = new QStringList();
    tableStrLst->append("Type");
    tableStrLst->append("ID");
    tableStrLst->append("Address");
    tableStrLst->append("Status");
    tableWidget = new QTableWidget(5, 4, this);
    tableWidget->setHorizontalHeaderLabels(*tableStrLst);
    
    addBtn = new QPushButton("Add", this);
    modifyBtn = new QPushButton("Modify", this);
    removeBtn = new QPushButton("Remove", this);
    
    connect(addBtn, SIGNAL(released() ), this, SLOT(handleAddBtnSlot() ) );
    connect(modifyBtn, SIGNAL(released() ), this, SLOT(handleModifyBtnSlot() ) );
    connect(removeBtn, SIGNAL(released() ), this, SLOT(handleRemoveBtnSlot() ) );
    
    buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(addBtn);
    buttonLayout->addWidget(modifyBtn);
    buttonLayout->addWidget(removeBtn);
    
    outerLayout = new QGridLayout();
    outerLayout->addWidget(tableWidget, 0, 0);
    outerLayout->addLayout(buttonLayout, 1, 0, Qt::AlignRight);
    
    this->setLayout(outerLayout);
}


void DevicesGui::handleAddBtnSlot()
{
    cout << "\"add\" button pressed" << endl;
    addDeviceGui->show();
}


void DevicesGui::handleModifyBtnSlot()
{
    cout << "\"modify\" button pressed" << endl;
    modifyDeviceGui->show();
}


void DevicesGui::handleRemoveBtnSlot()
{
    cout << "\"remove\" button pressed" << endl;
    int ret = verifyMessageBox->exec();
    
    switch(ret)
    {
        case QMessageBox::Yes:
            ;
            break;
        case QMessageBox::No:
            ;
            break;
        default:
            ;
    }
}


DevicesGui::~DevicesGui()
{
    ;
}

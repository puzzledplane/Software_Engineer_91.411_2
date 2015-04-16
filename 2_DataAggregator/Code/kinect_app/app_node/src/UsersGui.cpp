#include "UsersGui.h"
#include "ModifyDeviceGui.h"

UsersGui::UsersGui(QWidget* parent) : QWidget(parent)
{
    addUserGui = new AddUserGui();
    modifyUserGui = new ModifyUserGui();
    
    verifyMessageBox = new QMessageBox();
    verifyMessageBox->setText("<qt>The specified action is <b>irrevocable.</b><qt>");
    verifyMessageBox->setInformativeText("<qt>\nAre you sure you would like to continue?</qt>");
    verifyMessageBox->setStandardButtons(QMessageBox::No | QMessageBox::Yes);
    verifyMessageBox->setDefaultButton(QMessageBox::No);
    verifyMessageBox->setIcon(QMessageBox::Warning);
    
    tableStrLst = new QStringList();
    tableStrLst->append("Name");
    tableStrLst->append("Email");
    tableStrLst->append("Exercise(s)");
    tableStrLst->append("More");
    tableWidget = new QTableWidget(5, 4, this);
    tableWidget->setHorizontalHeaderLabels(*tableStrLst);
    //tableWidget->setCellWidget(4, 3, new QPushButton("More", this) );
    for(size_t i = 0; i < tableWidget->rowCount(); i++)
    {
        tableWidget->setCellWidget(i, 2, new QComboBox(this) );
        tableWidget->setCellWidget(i, 3, new QPushButton("More", this) );
    }
    
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


void UsersGui::handleMoreBtnSlot()
{
    cout << "\"more\" button pressed" << endl;
}


void UsersGui::handleAddBtnSlot()
{
    cout << "\"add\" button pressed" << endl;
    addUserGui->show();
}


void UsersGui::handleModifyBtnSlot()
{
    cout << "\"modify\" button pressed" << endl;
    modifyUserGui->show();
}


void UsersGui::handleRemoveBtnSlot()
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


UsersGui::~UsersGui()
{
    ;
}

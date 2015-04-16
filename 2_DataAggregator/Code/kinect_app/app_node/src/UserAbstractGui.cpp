#include "UserAbstractGui.h"


UserAbstractGui::UserAbstractGui(QWidget* parent) : QWidget(parent)
{   
    
    nameLe = new QLineEdit();
    emailLe = new QLineEdit();
    usernameLe = new QLineEdit();
    passwordLe = new QLineEdit();
    //connect(passwordLe, SIGNAL(textChanged() ), this, SLOT(handlePasswordLeSlot() ) );
    accountTypesLst = new QStringList();
    accountTypesLst->push_back("Admin");
    accountTypesLst->push_back("User");
    accountTypeCb = new QComboBox();
    accountTypeCb->addItems(*accountTypesLst);
    retypePasswordLbl = new QLabel("Retype Password", this);
    retypePasswordLbl->setVisible(false);
    retypePasswordLe = new QLineEdit();
    retypePasswordLe->setVisible(false);
    exerciesTe = new QTextEdit();
    noteTe = new QTextEdit();
    
    okBtn = new QPushButton("Ok", this);
    applyBtn = new QPushButton("Apply", this);
    cancelBtn = new QPushButton("Cancel", this);
    
    formLayout = new QFormLayout();
    formLayout->addRow(tr("&Name"), nameLe);
    formLayout->addRow(tr("&Email"), emailLe);
    formLayout->addRow(tr("&Username"), usernameLe);
    formLayout->addRow(tr("&Password"), passwordLe);
    formLayout->addRow(retypePasswordLbl, retypePasswordLe);
    formLayout->addRow(tr("&Account Type"), accountTypeCb);
    formLayout->addRow(tr("&Exercise(s)"), exerciesTe);
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


void UserAbstractGui::handlePasswordLeSlot()
{
    retypePasswordLbl->setVisible(true);
    retypePasswordLe->setVisible(true);
}


void UserAbstractGui::handleOkBtnSlot()
{
    cout << "\"Ok\" button pressed" << endl;
}


void UserAbstractGui::handleApplyBtnSlot()
{
    cout << "\"Apply\" button pressed" << endl;
}


void UserAbstractGui::handleCancelBtnSlot()
{
    cout << "\"Cancel\" button pressed" << endl;
}


void UserAbstractGui::unloadDefaultBtns()
{
    outerLayout->removeItem(buttonLayout);
    okBtn->setEnabled(false);
    okBtn->setVisible(false);
    applyBtn->setEnabled(false);
    applyBtn->setVisible(false);
    cancelBtn->setEnabled(false);
    cancelBtn->setVisible(false);
}


UserAbstractGui::~UserAbstractGui()
{
    ;
}

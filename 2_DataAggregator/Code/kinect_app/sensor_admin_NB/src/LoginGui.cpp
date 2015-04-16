#include "LoginGui.h"

LoginGui::LoginGui(QWidget* parent) : QWidget(parent)
{
    titleLbl = new QLabel("<b>Sensor Management Center</b>", this);
    imageFieldLbl = new QLabel("Sensor Management Center", this);
    QPixmap iconPm("se_logo.xpm");
    imageFieldLbl->setPixmap(iconPm);
    iconPm.scaled(100, 75, Qt::IgnoreAspectRatio, Qt::FastTransformation);

    userNameLe = new QLineEdit(this);
    passwordLe = new QLineEdit(this);
    passwordLe->setEchoMode(QLineEdit::Password);

    //loginBtn = new QPushButton("Login", this);
    //cancelBtn = new QPushButton("Cancel", this);


    outerLayout = new QGridLayout();
    inputFieldsLayout = new QFormLayout();
    //buttonLayout = new QHBoxLayout();

    inputFieldsLayout->addRow(tr("&Username:"), userNameLe);
    inputFieldsLayout->addRow(tr("&Password:"), passwordLe);


    //buttonLayout->addWidget(loginBtn);
    //buttonLayout->addWidget(cancelBtn);


    outerLayout->addWidget(titleLbl, 0, 0, Qt::AlignHCenter);
    outerLayout->addWidget(imageFieldLbl, 1, 0, 2, 0, Qt::AlignHCenter);
    outerLayout->addLayout(inputFieldsLayout, 3, 0, Qt::AlignCenter);
    //outerLayout->addLayout(buttonLayout, 4, 0, Qt::AlignRight);



    this->setLayout(outerLayout);
}


void LoginGui::loginGuiMaster()
{
    ;
}


LoginGui::~LoginGui()
{
    ;
}

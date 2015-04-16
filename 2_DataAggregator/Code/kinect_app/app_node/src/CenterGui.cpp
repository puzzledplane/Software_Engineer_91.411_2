#include "CenterGui.h"

CenterGui::CenterGui(QWidget* parent) : QWidget(parent)
{
    usernameLbl = new QLabel("<qt>Welcome, <b>username_here</b></qt>");
    lastLoginLbl = new QLabel("Last login: last_login_date_here");
    exercisesLbl = new QLabel("Exercises: \n\t- bullet\n\t- points\n\t- containing\n\t- exercises");
    
    outerLayout = new QGridLayout(this);
    outerLayout->addWidget(usernameLbl, 0, 0, Qt::AlignCenter);
    outerLayout->addWidget(lastLoginLbl, 1, 0, Qt::AlignHCenter);
    outerLayout->addWidget(exercisesLbl, 2, 0, Qt::AlignHCenter);
    
    this->setLayout(outerLayout);
    this->setMinimumSize(500, 300);//setMinimumSize(600, 400);
}


CenterGui::~CenterGui()
{
    ;
}

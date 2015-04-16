#include "Menu.h"



Menu::Menu(QWidget* parent) : QWidget(parent)
{
    menuLayout = new QVBoxLayout(this);
    
    this->setStyleSheet("background-color:black;");
    this->setStyleSheet("background-color:black;"
                        "background-image:url(/home/james/se_ws/src/sensor-admin/sensor_admin_NB/background1.jpg);");
    
    menubar = new QMenuBar(this);
    QMenu* menu1 = new QMenu("MENU1");
    menu1->addMenu(new QMenu("menu1_SubMenu"));
    QMenu* menu2 = new QMenu("MENU2");
    menu2->addMenu(new QMenu("menu2_SubMenu"));
    menubar->addMenu(menu1);
    menubar->addMenu(menu2);
    
    this->setLayout(menuLayout);
}


void Menu::loadMenu(QVector<QString> btnNameVec)
{
    for(size_t i = 0; i < btnNameVec.size(); i++)
    {
        menuBtnVec.push_back( new QPushButton(btnNameVec.at(i), this) );
        menuLayout->addWidget(menuBtnVec.at(i) );
    }
    
    //------
    //http://qt-project.org/doc/qt-4.8/stylesheet-examples.html
    menuBtnVec.at(0)->setStyleSheet("QPushButton {background-color: #A3C1DA; color: red;}");
    menuBtnVec.at(1)->setStyleSheet("QPushButton {background-color: yellow}");
    menuBtnVec.at(2)->setStyleSheet("QPushButton {"
    "color: grey;"
    "border-image: url(/home/james/se_ws/src/sensor-admin/sensor_admin_NB/button.jpg) 3 10 3 10;"
    "border-top: 3px transparent;"
    "border-bottom: 3px transparent;"
    "border-right: 10px transparent;"
    "border-left: 10px transparent;"
    "}");
    //------
}


Menu::~Menu()
{
    ;
}

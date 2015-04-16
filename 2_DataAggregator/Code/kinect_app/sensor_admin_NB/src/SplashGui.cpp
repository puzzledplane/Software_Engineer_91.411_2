#include "SplashGui.h"


SplashGui::SplashGui(QWidget* parent) : QWidget(parent)
{
    imagePxmp = new QPixmap("/home/james/se_ws/src/sensor-admin/sensor_admin_NB/se_logo.png");
    splash = new QSplashScreen(*imagePxmp);
    animation = new QMovie("/home/james/se_ws/src/sensor-admin/sensor_admin_NB/ajax-loader.gif");
    animationLbl = new QLabel("test", this);
    animationLbl->setMovie(animation);
    animation->start();
}


SplashGui::~SplashGui()
{
    ;
}
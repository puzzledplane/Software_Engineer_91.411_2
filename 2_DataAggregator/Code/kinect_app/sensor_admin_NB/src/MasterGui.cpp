#include "MasterGui.h"



MasterGui::MasterGui(QWidget* parent) : QWidget(parent)
{
    this->setWindowIcon(QIcon("se_logo.xpm") );
    this->setWindowIcon(QIcon("/home/james/se_ws/src/sensor-admin/se_logo.xpm") );
    this->setWindowTitle("Software Engineering I");
    
    AppStyles::loadStyle(this, AppStyles::CLASSIC);
    //AppStyles::loadStyle<int>(5);
    
    QDesktopWidget desktop;
    int desktopHeight = desktop.geometry().height();
    int desktopWidth = desktop.geometry().width();
    cout << "Desktop is: " << desktopHeight << " high and " << desktopWidth << " wide.";
    //this->resize(desktopWidth, desktopHeight);
    
    initCore();
    
    this->setLayout(outerLayout);
}


void MasterGui::handleSignUpBtnSlot()
{
    switchPage(SIGNUP_GUI);
}


void MasterGui::handleSignInBtnSlot()
{
    switchPage(LOGIN_GUI);
}


void MasterGui::handleLoginBtnSlot()
{
    switchPage(CENTER_GUI);
}


void MasterGui::handleRegisterBtnSlot()
{
    cout << "currentPage is: " << currentPage << endl;
    switchPage(CENTER_GUI);
}


void MasterGui::handleBackBtnSlot()
{
    currentPage = SIGNUP_GUI;
    switchPage(OPENING_GUI);
}


void MasterGui::handleCancel0BtnSlot()
{
    ;
}


void MasterGui::handleCancelBtnSlot()
{
    close();
}


void MasterGui::handleActivateBtnSlot()
{
    if(activateBtn->text() == "Activate")
    {
        activateBtn->setText("Deactivate");
    }
    else if(activateBtn->text() == "Deactivate")
    {
        activateBtn->setText("Activate");
    }
    else
    {
        cerr << "Error at MasterGui::handleActiveBtnSlot()" << endl;
    }
    
}


void MasterGui::handleVideoBtnSlot()
{
    switchPage(VIDEO_GUI);
}


void MasterGui::handleResultsBtnSlot()
{
    switchPage(RESULTS_GUI);
}


void MasterGui::handleUsersBtnSlot()
{
    switchPage(USERS_GUI);
}


void MasterGui::handleDevicesBtnSlot()
{
    switchPage(DEVICES_GUI);
}


void MasterGui::handleHistoryBtnSlot()
{
    switchPage(HISTORY_GUI);
}


void MasterGui::handleHelpBtnSlot()
{
    helpGui->show();
}


void MasterGui::handleExitBtnSlot()
{
    this->close();
}


void MasterGui::handleToolbarViewBtnSlot()
{
    cout << "\"<->\" button pressed" << endl;
    
    switch(isVisable)
    {
        case true:
            outerLayout->removeWidget(toolbar);
            toolbar->setVisible(false);
            toolbar->setEnabled(false);
            toolbarViewBtn->setText("<-");
            toolbarViewBtn->setToolTip("view toolbar");
            isVisable = false;
            break;
        case false:
            outerLayout->addWidget(toolbar, 0, 3);
            toolbar->setVisible(true);
            toolbar->setEnabled(true);
            toolbarViewBtn->setText("->");
            toolbarViewBtn->setToolTip("Hide toolbar");
            isVisable = true;
            break;
        default:
            cerr << "Invalid option at MasterGui::handleToolbarViewBtnSlot()" << endl;
    }
    
}

void MasterGui::initCore()
{
    openingGui = new OpeningGui();
    userAbstractGui = new UserAbstractGui();
    loginGui = new LoginGui();
    centerGui = new CenterGui();
    videoGui = new VideoGui();
    resultsGui = new ResultsGui();
    usersGui = new UsersGui();
    devicesGui = new DevicesGui();
    historyGui = new HistoryGui();
    helpGui = new HelpGui();
    
    signUpBtn = new QPushButton("Sign Up", this);
    signInBtn = new QPushButton("Sign In", this);
    registerBtn = new QPushButton("Register");
    registerBtn->setVisible(false);
    registerBtn->setEnabled(false);
    backBtn = new QPushButton("Back");
    backBtn->setVisible(false);
    backBtn->setEnabled(false);
    cancel0Btn = new QPushButton("Cancel");
    cancel0Btn->setVisible(false);
    cancel0Btn->setEnabled(false);
    loginBtn = new QPushButton("Login", this);
    loginBtn->setVisible(false);
    loginBtn->setEnabled(false);
    cancelBtn = new QPushButton("Cancel", this);
    cancelBtn->setVisible(false);
    cancelBtn->setEnabled(false);
    
    
    registerBtnLayout = new QHBoxLayout();
    registerBtnLayout->addWidget(registerBtn);
    registerBtnLayout->addWidget(backBtn);
    registerBtnLayout->addWidget(cancel0Btn);
    
    loginBtnLayout = new QHBoxLayout();
    loginBtnLayout->addWidget(loginBtn);
    loginBtnLayout->addWidget(cancelBtn);
    
    connect(signUpBtn, SIGNAL(released() ), this, SLOT(handleSignUpBtnSlot() ) );
    connect(signInBtn, SIGNAL(released() ), this, SLOT(handleSignInBtnSlot() ) );
    connect(registerBtn, SIGNAL(released() ), this, SLOT(handleRegisterBtnSlot() ) );
    connect(backBtn, SIGNAL(released() ), this, SLOT(handleBackBtnSlot() ) );
    connect(cancel0Btn, SIGNAL(released() ), this, SLOT(handleCancel0BtnSlot() ) );
    connect(loginBtn, SIGNAL(released() ), this, SLOT(handleLoginBtnSlot() ) );
    connect(cancelBtn, SIGNAL(released() ), this, SLOT(handleCancelBtnSlot() ) );
    
    outerLayout = new QGridLayout();
    //loadLoginGui();
    loadOpeningGui();
    
    currentPage = OPENING_GUI;
}


void MasterGui::loadToolbar()
{
    toolbar = new QToolBar();
    toolbar->addWidget(activateBtn = new QPushButton("Activate", this) );
    toolbar->addWidget(videoBtn = new QPushButton("Video", this) );
    toolbar->addWidget(resultsBtn = new QPushButton("Results", this) );
    toolbar->addWidget(usersBtn = new QPushButton("Users", this) );
    toolbar->addWidget(devicesBtn = new QPushButton("Devices", this) );
    toolbar->addWidget(historyBtn = new QPushButton("History", this) );
    toolbar->addWidget(helpBtn = new QPushButton("Help", this) );
    toolbar->addWidget(exitBtn = new QPushButton("Exit", this) );
    
    connect(activateBtn, SIGNAL(released() ), this, SLOT(handleActivateBtnSlot() ) );
    connect(videoBtn, SIGNAL(released() ), this, SLOT(handleVideoBtnSlot() ) );
    connect(resultsBtn, SIGNAL(released() ), this, SLOT(handleResultsBtnSlot() ) );
    connect(usersBtn, SIGNAL(released() ), this, SLOT(handleUsersBtnSlot() ) );
    connect(devicesBtn, SIGNAL(released() ), this, SLOT(handleDevicesBtnSlot() ) );
    connect(historyBtn, SIGNAL(released() ), this, SLOT(handleHistoryBtnSlot() ) );
    connect(helpBtn, SIGNAL(released() ), this, SLOT(handleHelpBtnSlot() ) );
    connect(exitBtn, SIGNAL(released() ), this, SLOT(handleExitBtnSlot() ) );
    
    toolbar->setOrientation(Qt::Vertical);
    toolbar->setStyleSheet("QToolBar{spacing:10px;}");
    //toolbar->setStyleSheet("background-color:gray;");
    
    toolbarViewBtn = new QPushButton("->", this);
    connect(toolbarViewBtn, SIGNAL(released() ), this, SLOT(handleToolbarViewBtnSlot() ) );
    toolbarViewBtn->setToolTip("Hide toolbar");
    isVisable = true;
    
    outerLayout->addWidget(toolbar, 0, 3);
    outerLayout->addWidget(toolbarViewBtn, 1, 3);
}


void MasterGui::switchPage(Page newPage)
{
    switch(currentPage)
    {
        case OPENING_GUI:
            unloadOpeningGui();
            break;
        case SIGNUP_GUI:
            unloadUserAbstractGui();
            break;
        case LOGIN_GUI:
            unloadLoginGui();
            break;
        case CENTER_GUI:
            unloadCenterGui();
            break;
        case VIDEO_GUI:
            unloadVideoGui();
            break;
        case RESULTS_GUI:
            unloadResultsGui();
            break;
        case USERS_GUI:
            unloadUsersGui();
            break;
        case DEVICES_GUI:
            unloadDevicesGui();
            break;
        case HISTORY_GUI:
            unloadHistoryGui();
            break;
        default:
            cerr << "Error in switch 1 at MasterGui::switchPages" << endl;
    }
    
    switch(newPage)
    {
        case OPENING_GUI:
            loadOpeningGui();
            break;
        case SIGNUP_GUI:
            loadUserAbstractGui();
            cout << "case SIGNUP_GUI is switch 2 at MasterGui::switchPages not implemented yet" << endl;
            break;
        case LOGIN_GUI:
            loadLoginGui();
            break;
        case CENTER_GUI:
            loadCenterGui();
            loadToolbar();
            break;
        case VIDEO_GUI:
            loadVideoGui();
            break;
        case RESULTS_GUI:
            loadResultsGui();
            break;
        case USERS_GUI:
            loadUsersGui();
            break;
        case DEVICES_GUI:
            loadDevicesGui();
            break;
        case HISTORY_GUI:
            loadHistoryGui();
            break;
        default:
            cerr << "Error in switch 2 at MasterGui::switchPages" << endl; 
    }
    
    currentPage = newPage;
    
}


void MasterGui::loadOpeningGui()
{
    cout << "loadOpeningGui" << endl;
    openingGui->setVisible(true);
    openingGui->setEnabled(true);
    outerLayout->addWidget(openingGui, 0, 0);
    outerLayout->addWidget(signUpBtn, 1, 0, Qt::AlignHCenter);
    outerLayout->addWidget(signInBtn, 2, 0, Qt::AlignHCenter);
    signUpBtn->setVisible(true);
    signUpBtn->setEnabled(true);
    signInBtn->setVisible(true);
    signInBtn->setEnabled(true);
}


void MasterGui::unloadOpeningGui()
{
    outerLayout->removeWidget(openingGui);
    outerLayout->removeWidget(signUpBtn);
    outerLayout->removeWidget(signInBtn);
    openingGui->setVisible(false);
    openingGui->setEnabled(false);
    signUpBtn->setVisible(false);
    signUpBtn->setEnabled(false);
    signInBtn->setVisible(false);
    signInBtn->setEnabled(false);
    
}


void MasterGui::loadUserAbstractGui()
{
    cout << "MasterGui::loadAddUserGui() has not been implemented yet" << endl;
    outerLayout->addWidget(userAbstractGui, 0, 0);
    userAbstractGui->unloadDefaultBtns();
    userAbstractGui->setVisible(true);
    registerBtn->setVisible(true);
    registerBtn->setEnabled(true);
    backBtn->setVisible(true);
    backBtn->setEnabled(true);
    cancel0Btn->setVisible(true);
    cancel0Btn->setEnabled(true);
    outerLayout->addLayout(registerBtnLayout, 1, 0, Qt::AlignRight);
}


void MasterGui::unloadUserAbstractGui()
{
    cout << "MasterGui::unloadAddUserGui() has not been implemented yet" << endl;
    outerLayout->removeWidget(userAbstractGui);
    userAbstractGui->setVisible(false);
    outerLayout->removeItem(registerBtnLayout);
    registerBtn->setVisible(false);
    registerBtn->setEnabled(false);
    backBtn->setVisible(false);
    backBtn->setEnabled(false);
    cancel0Btn->setVisible(false);
    cancel0Btn->setEnabled(false);
}


void MasterGui::loadLoginGui()
{
    outerLayout->addWidget(loginGui, 0, 0);
    loginBtn->setVisible(true);
    loginBtn->setEnabled(true);
    outerLayout->addLayout(loginBtnLayout, 1, 0, Qt::AlignRight);
}


void MasterGui::unloadLoginGui()
{
    outerLayout->removeWidget(loginGui);
    loginGui->setVisible(false);
    loginBtn->setVisible(false);
    cancelBtn->setVisible(false);
}


void MasterGui::loadCenterGui()
{
    outerLayout->addWidget(centerGui, 0, 0);
    centerGui->setVisible(true);
}


void MasterGui::unloadCenterGui()
{
    outerLayout->removeWidget(centerGui);
    centerGui->setVisible(false);
}


void MasterGui::loadVideoGui()
{
    outerLayout->addWidget(videoGui, 0, 0);
    videoGui->setVisible(true);
}


void MasterGui::unloadVideoGui()
{
    outerLayout->removeWidget(videoGui);
    videoGui->setVisible(false);
}


void MasterGui::loadResultsGui()
{
    outerLayout->addWidget(resultsGui, 0, 0);
    resultsGui->setVisible(true);
}


void MasterGui::unloadResultsGui()
{
    outerLayout->removeWidget(resultsGui);
    resultsGui->setVisible(false);
}


void MasterGui::loadUsersGui()
{
    outerLayout->addWidget(usersGui, 0, 0);
    usersGui->setVisible(true);
}


void MasterGui::unloadUsersGui()
{
    outerLayout->removeWidget(usersGui);
    usersGui->setVisible(false);
}


void MasterGui::loadDevicesGui()
{
    outerLayout->addWidget(devicesGui, 0, 0);
    devicesGui->setVisible(true);
}


void MasterGui::unloadDevicesGui()
{
    outerLayout->removeWidget(devicesGui);
    devicesGui->setVisible(false);
}


void MasterGui::loadHistoryGui()
{
    outerLayout->addWidget(historyGui, 0, 0);
    historyGui->setVisible(true);
}


void MasterGui::unloadHistoryGui()
{
    outerLayout->removeWidget(historyGui);
    historyGui->setVisible(false);
}


MasterGui::~MasterGui()
{
    ;
}
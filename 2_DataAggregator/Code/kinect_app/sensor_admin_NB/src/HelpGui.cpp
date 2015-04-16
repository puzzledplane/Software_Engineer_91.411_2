#include "HelpGui.h"

HelpGui::HelpGui(QWidget* parent, int numOfPages) : QWidget(parent), NUM_OF_PAGES(numOfPages)
{
    titleLbl = new QLabel(this);
    contentLbl = new QLabel(this);
    loadPageOne();
    
    pageNum = 1;
    
    previousPb = new QPushButton("Previous", this);
    nextPb = new QPushButton("Next", this);
    exitPb = new QPushButton("Exit", this);
    
    previousPb->setToolTip("Previous page");
    previousPb->setDisabled(true);
    nextPb->setToolTip("Next page");
    exitPb->setToolTip("Exit help tab");
    
    connect(previousPb, SIGNAL(released() ), this, SLOT(handlePreviousBtnSlot() ) );
    connect(nextPb, SIGNAL(released() ), this, SLOT(handleNextBtnSlot() ) );
    connect(exitPb, SIGNAL(released() ), this, SLOT(handleExitBtnSlot() ) );
    
    outerLayout = new QGridLayout();
    outerLayout->addWidget(titleLbl, 0, 0, Qt::AlignCenter);
    outerLayout->addWidget(contentLbl, 1, 0, Qt::AlignCenter);
    
    buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(previousPb, Qt::AlignCenter);
    buttonLayout->addWidget(nextPb, Qt::AlignCenter);
    buttonLayout->addWidget(exitPb, Qt::AlignCenter);
    
    outerLayout->addLayout(buttonLayout, 4, 0, Qt::AlignRight);
    
    setMinimumSize(150, 400);
    setLayout(outerLayout);
}


void HelpGui::handlePreviousBtnSlot()
{
    //cout << "pageNum: " << pageNum << endl;
    if(!nextPb->isEnabled() )
    {
        nextPb->setDisabled(false);
    }
    
    if(pageNum == 2)
    {
        previousPb->setDisabled(true);
    }
    
    
    managePages(--pageNum);  
}


void HelpGui::handleNextBtnSlot()
{
    //cout << "pageNum: " << pageNum << endl;
    if(!previousPb->isEnabled() )
    {
        previousPb->setDisabled(false);
    }
    
    if(pageNum == 2)
    {
        nextPb->setDisabled(true);
    }
    
    
    managePages(++pageNum);
}


void HelpGui::handleExitBtnSlot()
{
    close();//qt SLOT to gracefully exit the window.
}


void HelpGui::managePages(int pageNum)
{
    switch(pageNum)
    {
        case 1:
            loadPageOne();
            break;
        case 2:
            loadPageTwo();
            break;
        case 3:
            loadPageThree();
        case 4:
            loadPageFour();
        default:
            ;
    }
}


void HelpGui::loadPageOne()
{
    titleLbl->setText("Index");
    contentLbl->setText("* Execution Instructions"
                      "\n\n *Project Overview"
                      "\n\n *External Resources\n\n");
}


void HelpGui::loadPageTwo()
{
    titleLbl->setText("Execution Instructions");
    contentLbl->setText("This page has not yet been implemented (page 1)");
}


void HelpGui::loadPageThree()
{
    titleLbl->setText("Project Overview");
    contentLbl->setText("This page has not yet been impleented yet (page 2)");
}


void HelpGui::loadPageFour()
{
    titleLbl->setText("External Resources");
    contentLbl->setText("<qt>*&nbsp;For more details about the software,"
                        "<br>&nbsp;&nbsp;&nbsp;&nbsp;and to access the source code and"
                        "<br>&nbsp;&nbsp;&nbsp;&nbsp;documentations, go to:</qt>"
                        "<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"
                        "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"
                        "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"
                        "<u><a href=\"https://github.com/DeepBlue14/sensor_admin\">QtCentre</a></u>"
                        "<qt>*&nbspYou can contact the author at:</qt>"
                        "<br>&nbsp;&nbsp;&nbsp;&nbsp;<i>jkuczyns@cs.uml.edu</i>");
}


HelpGui::~HelpGui()
{
    ;
}

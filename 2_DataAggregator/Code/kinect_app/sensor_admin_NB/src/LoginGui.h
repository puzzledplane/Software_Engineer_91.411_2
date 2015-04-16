/* 
 * File: Login.h
 * Author: James Kuczynski
 * Email: jkcuzyns@cs.uml.edu
 * File Description: This class provides a GUI for user login.
 * 
 * References: http://www.tutorialspoint.com/sqlite/sqlite_c_cpp.htm
 *             http://doc.qt.io/qt-5/json.html
 *             https://www.google.com/webhp?sourceid=chrome-instant&ion=1&espv=2&ie=UTF-8#q=rapidjson
 * Created on April 1, 2015, 5:55mp
 */

#ifndef LOGIN_GUI_H
#define LOGIN_GUI_H

#include <QtGui>
#include <QDialog>
#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include <QLineEdit>
#include <QPushButton>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QGridLayout>

class LoginGui : public QWidget
{
    Q_OBJECT

private:
    QLabel* titleLbl; /**Title of class LoginGui.*/
    QLabel* imageFieldLbl; /**Project icon.*/
    QLineEdit* userNameLe; /**Entry for the user's username.*/
    QLineEdit* passwordLe; /**Entry for the user's password.*/


    QGridLayout* outerLayout; /**Base layout to load directly into GUI.*/
    QFormLayout* inputFieldsLayout; /**Layout to contain label-entry pairs of this class.*/

public:
    /**
     * Constructor.
     * @param parent Pointer to object of parent type QWidget.
     */
    LoginGui(QWidget* parent = 0);
    
    /**
     * "Master" type method to handle control flow of this class.
     */
    void loginGuiMaster();
    
    /**
     * Destructor.
     */
    
    ~LoginGui();

};

#endif /*LOGIN_GUI_H*/

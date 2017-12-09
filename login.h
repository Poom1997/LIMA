//--------------------------------------------------//
// Bhurinuth Wongsrisakul ID:58090030  (SY2015/2)   //
// 7th SE KMITL (Object Oriented Programing Project)//
// LIMA - LIbrary Management and Administration     //
// Filename: login.h   Type: Header File            //
//--------------------------------------------------//

//--------------------------------------------------//
// This class is the first and the main window of   //
// the program. It handles all the function of      //
// the login window.                                //
//--------------------------------------------------//

#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include "userarea.h"
#include "registration.h"
#include "admin.h"
#include "message.h"

namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT

public:
    QSqlDatabase db;
    void sqlconnClose();    //Function for connecting to the SQL Database.
    bool sqlconnOpen();     //Function for disconnecting from the SQL Database.

    explicit Login(QWidget *parent = 0);
    ~Login();

private slots:  //This part holds all the function for the buttons.
    void on_loginbutton_clicked();
    void on_registernew_clicked();

private:
    Ui::Login *ui;
    QString CURRPATH;
    int allowreg;
    userarea ua;
    Admin adm;
    message msg;
};

#endif // LOGIN_H

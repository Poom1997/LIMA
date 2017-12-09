//--------------------------------------------------//
// Bhurinuth Wongsrisakul ID:58090030  (SY2015/2)   //
// 7th SE KMITL (Object Oriented Programing Project)//
// LIMA - LIbrary Management and Administration     //
// Filename: dataedit.h   Type: Header File         //
//--------------------------------------------------//

//----------------------------------------------//
// This class serves to function the data edit  //
// aspects of the program. It handles all the   //
// function of the edit data window.            //
//----------------------------------------------//

#ifndef DATAEDIT_H
#define DATAEDIT_H

#include <QDialog>
#include "login.h"
#include "message.h"

namespace Ui {
class dataedit;
}

class dataedit : public QDialog
{
    Q_OBJECT

public:
    explicit dataedit(QWidget *parent = 0);
    void passinfo(QString idnum, QString stat); //This is the function for holding the value from the admin/user window.
    void update();                              //Function to update the window after the query.
    void deleteuser(QString idnum, QString role);   //Function to delete the useraccount.
    ~dataedit();

private slots:  //This part holds all the function for the buttons.
    void on_cancel_clicked();
    void on_changepasw_clicked();
    void on_changerole_clicked();
    void on_editok_clicked();

private:
    Ui::dataedit *ui;
    message msg;
    QString id,role,newrole,password,status,CURRPATH;
    bool paswchk=false;
};

#endif // DATAEDIT_H

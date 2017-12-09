//--------------------------------------------------//
// Bhurinuth Wongsrisakul ID:58090030  (SY2015/2)   //
// 7th SE KMITL (Object Oriented Programing Project)//
// LIMA - LIbrary Management and Administration     //
// Filename: userarea.h   Type: Header File         //
//--------------------------------------------------//

//--------------------------------------------------//
// This class serves to function the user's area    //
// aspects of the program. It handles all the       //
// function of the userarea window.                 //
//--------------------------------------------------//


#ifndef USERAREA_H
#define USERAREA_H

#include <QMainWindow>
#include "message.h"

namespace Ui {
class userarea;
}

class userarea : public QMainWindow
{
    Q_OBJECT

public:
    explicit userarea(QWidget *parent = 0);
    void idRec(QString oID);    //Function to record the function from the login page.
    void bookupdate();          //Function to update the book's information.
    void update();              //Function to update the windows information after a query.
    void settingupdate();       //Function to apply settings from the SQL Database.
    ~userarea();

private slots:  //This part holds all the function for the buttons.
    void on_logout_clicked();
    void on_editprofile_clicked();
    void on_changephoto_clicked();
    void on_deleteme_clicked();
    void on_search_clicked();
    void on_borrow_clicked();
    void on_return_2_clicked();
    void on_lost_clicked();

private:
    Ui::userarea *ui;
    message msg;
    QString id, CURRPATH,role,bookid;
    int fine,book,allowphotochange,fine_book,reg,usr_changephoto,usr_editinfo;
};

#endif // USERAREA_H

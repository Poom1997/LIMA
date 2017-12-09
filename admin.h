//--------------------------------------------------//
// Bhurinuth Wongsrisakul ID:58090030  (SY2015/2)   //
// 7th SE KMITL (Object Oriented Programing Project)//
// LIMA - LIbrary Management and Administration     //
// Filename: admin.h   Type: Header File            //
//--------------------------------------------------//

//--------------------------------------------------//
// This class serves to function the administrator  //
// aspects of the program. It handles all the       //
// function of the administrator window.            //
//--------------------------------------------------//

#ifndef ADMIN_H
#define ADMIN_H

#include <QMainWindow>
#include "message.h"

namespace Ui {
class Admin;
}

class Admin : public QMainWindow
{
    Q_OBJECT

public:
    explicit Admin(QWidget *parent = 0);
    void idRec(QString oID); //Function for Passing the Info from the Login page.
    void update(int type);   //Function to update the data after a query.
    void advancesettings();  //Function to update the advance settings tab.
    void bookupdate();       //Function to update the book information.
    void togglefields(QString a); //Function to toggle the fields and buttons.
    ~Admin();

private slots:  //This part holds all the function for the buttons.

    void on_changephoto_clicked();
    void on_logout_clicked();
    void on_editprofile_clicked();
    void on_findid_button_clicked();
    void on_changephoto_2_clicked();
    void on_editdata_clicked();
    void on_apply_clicked();
    void on_clear_clicked();
    void on_deleteusr_clicked();
    void on_deleteme_clicked();
    void on_addbook_clicked();
    void on_reserve_clicked();
    void on_search_clicked();
    void on_edit_clicked();
    void on_changebookphoto_clicked();
    void on_applyedit_clicked();
    void on_clearloan_clicked();
    void on_delete_2_clicked();
    void on_usrreg_toggle_clicked();
    void on_usrinfo_toggle_clicked();
    void on_usrphoto_toggle_clicked();


private:
    Ui::Admin *ui;
    message msg;
    QString id, CURRPATH, usrid,role,bookid;
    int reserve, reg, usr_changephoto, usr_editinfo;
};

#endif // ADMIN_H

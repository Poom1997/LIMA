//--------------------------------------------------//
// Bhurinuth Wongsrisakul ID:58090030  (SY2015/2)   //
// 7th SE KMITL (Object Oriented Programing Project)//
// LIMA - LIbrary Management and Administration     //
// Filename: registration.h   Type: Header File     //
//--------------------------------------------------//

//--------------------------------------------------//
// This class serves to function the registration   //
// aspects of the program. It handles all the       //
// function of the registration window.             //
//--------------------------------------------------//


#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <QDialog>
#include "login.h"
#include "message.h"

namespace Ui {
class Registration;
}

class Registration : public QDialog
{
    Q_OBJECT

public:
    explicit Registration(QWidget *parent = 0);
    ~Registration();

private slots:  //This part holds all the function for the buttons.
    void on_pushButton_clicked();
    void on_registerok_clicked();

private:
    Ui::Registration *ui;
    message msg;
};

#endif // REGISTRATION_H

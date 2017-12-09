//--------------------------------------------------//
// Bhurinuth Wongsrisakul ID:58090030  (SY2015/2)   //
// 7th SE KMITL (Object Oriented Programing Project)//
// LIMA - LIbrary Management and Administration     //
// Filename: bookregis.h   Type: Header File        //
//--------------------------------------------------//

//------------------------------------------------------//
// This class serves to function the book registration  //
// aspects of the program. It handles all the           //
// function of the book registration window.            //
//------------------------------------------------------//

#ifndef BOOKREGIS_H
#define BOOKREGIS_H

#include <QDialog>
#include "message.h"
#include "login.h"

namespace Ui {
class bookregis;
}

class bookregis : public QDialog
{
    Q_OBJECT

public:
    explicit bookregis(QWidget *parent = 0);
    ~bookregis();

private slots:  //This part holds all the function for the buttons.
    void on_editok_clicked();
    void on_cancel_clicked();

private:
    Ui::bookregis *ui;
    message msg;
    QString CURRPATH;
};

#endif // BOOKREGIS_H

//--------------------------------------------------//
// Bhurinuth Wongsrisakul ID:58090030  (SY2015/2)   //
// 7th SE KMITL (Object Oriented Programing Project)//
// LIMA - LIbrary Management and Administration     //
// Filename: registration.cpp   Type: Source File   //
//--------------------------------------------------//

#include "registration.h"
#include "ui_registration.h"
//New User Registration Area//

Registration::Registration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Registration)
{
    ui->setupUi(this);

    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    this->setFixedSize(398,277);

    Login conn;
    if(!conn.sqlconnOpen())
        ui->dbstatus->setText("Offline");
    else
        ui->dbstatus->setText("Online");
}
Registration::~Registration()
{
    delete ui;
}
void Registration::on_registerok_clicked()
{
    bool complete;
    Login conn;
    QString id, fullname, username, password, email, role;
    id = ui->id->text();
    fullname = ui->name->text();
    username = ui->username->text();
    email = ui->email->text();
    role = ui->role->text();
    complete = true;
    password = ui->password->text();
    if((id=="")||(fullname=="")||(username=="")||(email=="")||(password==""))
    {
        msg.empty();
        complete = false;
    }
    conn.sqlconnOpen();
    QSqlQuery sameID;
    sameID.exec("SELECT userid FROM userdata WHERE userid = '"+id+"'");
    while(sameID.next())
    {
        QString check;
        check = sameID.value(0).toString();
        if(id == check)
        {
            msg.duplicateusrID();
            complete = false;
            break;
        }
    }
    QSqlQuery same;
    same.exec("SELECT username FROM userdata WHERE username = '"+username+"'");
    while(same.next())
    {
        QString check;
        check = same.value(0).toString();
        if(username == check)
        {
            msg.duplicateusrregis();
            complete = false;
            break;
        }
    }
    conn.sqlconnClose();
    if(ui->password->text() != ui->confirmpass->text())
    {
        msg.passwordmismatch();
        ui->password->clear();
        ui->confirmpass->clear();
        complete = false;
    }
    if(complete)
    {
        conn.sqlconnOpen();
        QSqlQuery write;
        write.prepare("INSERT INTO userdata (userid,fullname,email,username,password,role,fine) VALUES('"+id+"','"+fullname+"','"+email+"','"+username+"','"+password+"','"+role+"',0)");
        if (msg.informationconfirm())
        {
            if(write.exec())
            {
                msg.databasewriteOK();
                conn.sqlconnClose();
                this->close();
            }
            else
                msg.databasewriteFAIL();
        }
    }       
}
void Registration::on_pushButton_clicked()
{
    if (msg.cancel())
        this->close();
}

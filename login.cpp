//--------------------------------------------------//
// Bhurinuth Wongsrisakul ID:58090030  (SY2015/2)   //
// 7th SE KMITL (Object Oriented Programing Project)//
// LIMA - LIbrary Management and Administration     //
// Filename: login.cpp   Type: Source File          //
//--------------------------------------------------//

#include <QMessageBox>
#include "login.h"
#include "ui_login.h"

//The Main Window for this application//

Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    CURRPATH = QCoreApplication::applicationDirPath();
    QPixmap pix(CURRPATH + "/img/login.png");
    ui->loginPicture->setPixmap(pix);

    this->setFixedSize(400,238);

    if(!sqlconnOpen())
        ui->dbstatus->setText("Database -> Disconnected - Please reinstall the program.");
    else
        ui->dbstatus->setText("Database -> Online");
}
Login::~Login()
{
    delete ui;
}
bool Login::sqlconnOpen()
{
    QString PATH = QCoreApplication::applicationDirPath() + "/sql/database.sqlite";
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(PATH);
    if(!db.open())
        return false;
    else
        return true;
}
void Login::sqlconnClose()
{
    db.close();
    db.removeDatabase(QSqlDatabase::defaultConnection);
}
void Login::on_loginbutton_clicked()
{
    QString username, password,usrrole,id;
    username = ui->username->text();
    password = ui->password->text();
    sqlconnOpen();
    QSqlQuery qry;
    if(qry.exec("SELECT role,userid result FROM userdata WHERE username='"+username+"' and password='"+password+"'"))
    {
        qry.first();
        usrrole = qry.value(0).toString();
        id = qry.value(1).toString();
    }
    QSqlQuery qry2;
    qry2.prepare("SELECT * FROM userdata WHERE username='"+username+"' and password='"+password+"'");
    if(qry2.exec())
    {
        int count=0;
        while(qry2.next())
        {
            count++;
        }
        if(count==1 && usrrole == "user")
        {
            this->close();
            sqlconnClose();
            ua.idRec(id);
            ua.show();
        }
        if(count==1 && usrrole == "admin")
        {
            this->close();
            sqlconnClose();
            adm.idRec(id);
            adm.show();
        }
        if(count==0)
            msg.invalidLogin();
        if(count>1)
            msg.duplicateUsername();
    }
}
void Login::on_registernew_clicked()
{
    sqlconnOpen();
    QSqlQuery qry;
    if(qry.exec("SELECT canregister result FROM settings"))
    {
        qry.next();
        allowreg = qry.value(0).toInt();
        sqlconnClose();
    }
    if(allowreg)
    {
        Registration reg;
        reg.setModal(true);
        reg.exec();
    }
    else
        msg.actionForbidden();
}

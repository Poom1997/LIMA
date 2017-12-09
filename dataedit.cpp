//--------------------------------------------------//
// Bhurinuth Wongsrisakul ID:58090030  (SY2015/2)   //
// 7th SE KMITL (Object Oriented Programing Project)//
// LIMA - LIbrary Management and Administration     //
// Filename: dataedit.cpp   Type: Source File       //
//--------------------------------------------------//

#include <QMessageBox>
#include "dataedit.h"
#include "ui_dataedit.h"
#include "registration.h"

//Data Edit for admin and users//

dataedit::dataedit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dataedit)
{
    ui->setupUi(this);

    CURRPATH = QCoreApplication::applicationDirPath();

    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    this->setFixedSize(398,277);

    Login conn;
    if(!conn.sqlconnOpen())
        ui->dbstatus->setText("Offline");
    else
        ui->dbstatus->setText("Online");
}
dataedit::~dataedit()
{
    delete ui;
}
void dataedit::update()
{
    Login conn;
    conn.sqlconnOpen();
    QSqlQuery dataquery;
    if(dataquery.exec("SELECT fullname,email,username,password,role result FROM userdata WHERE userid='"+id +"'"))
    {
        dataquery.next();
        ui->id->setText(id);
        ui->name->setText(dataquery.value(0).toString());
        ui->email->setText(dataquery.value(1).toString());
        ui->username->setText(dataquery.value(2).toString());
        password = dataquery.value(3).toString();
        role = dataquery.value(4).toString();
        newrole = role;
        ui->role->setText(role);
    }
    conn.sqlconnClose();
    if(role=="user")
        ui->changerole->setEnabled(false);
    if(role=="admin" || status == "override")
        ui->changerole->setEnabled(true);
}
void dataedit::passinfo(QString idnum,QString stat)
{
    id = idnum;
    status = stat;
    update();
}
void dataedit::on_changepasw_clicked()
{
    if (msg.areyousure())
    {
        ui->password->setEnabled(true);
        ui->confirmpass->setEnabled(true);
        paswchk = true;
    }
}
void dataedit::on_changerole_clicked()
{
    int count=0;
    Login conn;
    conn.sqlconnOpen();
    QSqlQuery admchk;
    if(admchk.exec("SELECT role FROM userdata WHERE role ='admin'"))
    {
        while(admchk.next())
        {
           count++;
        }
    }
    conn.sqlconnClose();
    if(role == "admin")
    {
        if(count <= 1)
        {
            msg.onlyadminalert();
            if(QMessageBox::question(this,tr("Create new Account?"),tr("Do you want to create a new normal user account now?"))==QMessageBox::Yes)
            {
                Registration reg;
                reg.setModal(true);
                reg.exec();
            }
        }
        else
            if(QMessageBox::question(this,tr("Are you sure?"),tr("You are about to change your account status to normal user which you will lose all access to protected resources.\nDo you want to continue with this operation?"))==QMessageBox::Yes)
            {
                newrole = "user";
                ui->role->setText("user");
            }
    }
    if(role == "user")
        if(QMessageBox::question(this,tr("Are you sure?"),tr("You are about to change the account status to administrator which the user will have all access to protected resources.\nDo you want to continue with this operation?"))==QMessageBox::Yes)
        {
            newrole = "admin";
            ui->role->setText("admin");
        }

}
void dataedit::on_editok_clicked()
{
    QString name, username, email;
    bool complete = true;
    if((id=="")||(name=="")||(username=="")||(email=="")||(password==""))
    {
        msg.empty();
        complete = false;
    }
    if(paswchk)
    {
        if(ui->password->text() != ui->confirmpass->text())
        {
            msg.passwordmismatch();
            ui->password->clear();
            ui->confirmpass->clear();
            complete = false;
        }
        else
        {
            password = ui->password->text();
            complete = true;
        }
    }
    if(complete)
    {
        if (msg.informationconfirm())
        {
            name = ui->name->text();
            username = ui->username->text();
            email = ui->email->text();
            Login conn;
            conn.sqlconnOpen();
            QSqlQuery qry;
            qry.prepare("UPDATE userdata SET fullname ='"+name+"',email ='"+email+"',username='"+username+"',password='"+password+"',role='"+newrole+"' WHERE userid = '"+id+"'");
            if(qry.exec())
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
void dataedit::deleteuser(QString idnum,QString role)
{
    bool actioncontinue=true;
    int count=0;
    Login conn;
    conn.sqlconnOpen();
    QSqlQuery admchk;
    if(admchk.exec("SELECT role FROM userdata WHERE role ='admin'"))
    {
        while(admchk.next())
        {
           count++;
        }
    }
    conn.sqlconnClose();
    if(role=="admin" && count <=1)
    {
        msg.onlyadminalert();
        actioncontinue=false;
    }
    if(actioncontinue)
    {
        Login conn;
        conn.sqlconnOpen();
        QSqlQuery qry;
        qry.prepare("DELETE FROM userdata WHERE userid = '"+idnum+"'");
        if(qry.exec())
        {
            QMessageBox::information(this, tr("Data Deleted"), tr("The data was deleted successfully."));
            conn.sqlconnClose();
            QFile rem;
            rem.remove(CURRPATH + "/img/" + idnum + ".jpg");
        }
        else
            msg.databasewriteFAIL();
    }
}
void dataedit::on_cancel_clicked()
{
    if (msg.cancel())
        this->close();
}

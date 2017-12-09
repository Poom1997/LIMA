//--------------------------------------------------//
// Bhurinuth Wongsrisakul ID:58090030  (SY2015/2)   //
// 7th SE KMITL (Object Oriented Programing Project)//
// LIMA - LIbrary Management and Administration     //
// Filename: admin.cpp   Type: Source File          //
//--------------------------------------------------//

#include <QMessageBox>
#include <QFileDialog>
#include "admin.h"
#include "ui_admin.h"
#include "login.h"
#include "dataedit.h"
#include "bookregis.h"
#include <QDebug>


//Administration User Operation//

Admin::Admin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Admin)
{
    ui->setupUi(this);

    CURRPATH = QCoreApplication::applicationDirPath();
    this->setFixedSize(455,442);
}
Admin::~Admin()
{
    delete ui;
}

void Admin::on_logout_clicked()
{
    if (msg.logoutExit())
        this->close();
}

void Admin::idRec(QString oID)
{
    id = oID;
    update(0);
    update(3);
}

void Admin::update(int type)
{
    if(type==0)
    {
        Login conn;
        conn.sqlconnOpen();
        QSqlQuery dataquery;
        if(dataquery.exec("SELECT userid,fullname,email,username,role result FROM userdata WHERE userid='"+id +"'"))
        {
            dataquery.next();
            ui->id->setText(dataquery.value(0).toString());
            ui->name->setText(dataquery.value(1).toString());
            ui->welcome->setText("Welcome, " + dataquery.value(1).toString() + " ID# " + id);
            ui->email->setText(dataquery.value(2).toString());
            ui->username->setText(dataquery.value(3).toString());
            ui->role->setText(dataquery.value(4).toString());
            role = dataquery.value(4).toString();
        }
        conn.sqlconnClose();
        QPixmap pix(CURRPATH + "/img/" + id + ".jpg");
        ui->picture->setPixmap(pix);
    }
    if(type==1)
    {
        Login conn;
        conn.sqlconnOpen();
        QSqlQuery dataquery;
        if(dataquery.exec("SELECT userid,fullname,email,username,role,fine,bookamt,booklim result FROM userdata WHERE userid='"+usrid +"'"))
        {
            dataquery.next();
            ui->id_usr->setText(dataquery.value(0).toString());
            ui->name_usr->setText(dataquery.value(1).toString());
            ui->email_usr->setText(dataquery.value(2).toString());
            ui->username_usr->setText(dataquery.value(3).toString());
            ui->role_usr->setText(dataquery.value(4).toString());
            role = dataquery.value(4).toString();
            if(dataquery.value(0).toString()=="")
                togglefields("usrnotfound");
            if(role=="user")
            {
                ui->fine_usr->setText(dataquery.value(5).toString() + " THB");
                ui->bookamt_usr->setText(dataquery.value(6).toString() + " Books");
                ui->booklim_usr->setText(dataquery.value(7).toString() + " Books at any time");
                ui->fine_spin->setValue(dataquery.value(5).toInt());
                ui->borrow_spin->setValue(dataquery.value(6).toInt());
                ui->booklim->setValue(dataquery.value(7).toInt());
                togglefields("user");
            }
            else
                togglefields("admin");

        }
        conn.sqlconnClose();
        QPixmap pix(CURRPATH + "/img/" + usrid + ".jpg");
        ui->picture_usr->setPixmap(pix);
    }
    if(type==3)
        advancesettings();
}

void Admin::advancesettings()
{
    Login conn;
    conn.sqlconnOpen();
    QSqlQuery qry;
    qry.exec("SELECT canregister, canchangephoto, caneditinfo FROM settings WHERE rowid = 1");
    qry.first();
    reg = qry.value(0).toInt();
    usr_changephoto = qry.value(1).toInt();
    usr_editinfo = qry.value(2).toInt();
    if(!reg)
        ui->usrreg_toggle->setText("Disabled");
    else
        ui->usrreg_toggle->setText("Enabled");
    if(!usr_changephoto)
        ui->usrphoto_toggle->setText("Disabled");
    else
        ui->usrphoto_toggle->setText("Enabled");
    if(!usr_editinfo)
        ui->usrinfo_toggle->setText("Disabled");
    else
        ui->usrinfo_toggle->setText("Enabled");
    conn.sqlconnClose();
}

void Admin::on_changephoto_clicked()
{
    msg.pictureDimension();
    QString filename;
    filename = QFileDialog::getOpenFileName(this,tr("Open File"),"::{20D04FE0-3AEA-1069-A2D8-08002B30309D}","JPG Files (*.jpg)");
    QFile img;
    if(img.exists(CURRPATH + "/img/" + id + ".jpg"))
    {
        img.remove(CURRPATH + "/img/" + id + ".jpg");
    }
    img.copy(filename,CURRPATH + "/img/" + id + ".jpg");
    update(0);
}

void Admin::on_editprofile_clicked()
{
    dataedit edit;
    edit.setModal(true);
    edit.passinfo(id,"norm");
    edit.exec();
    update(0);
}

void Admin::on_findid_button_clicked()
{
    usrid = ui->findid->text();
    QPixmap pix(CURRPATH + "/img/" + usrid + ".jpg");
    ui->picture_usr->setPixmap(pix);
    if(usrid == id)
    {
        togglefields("findidself");
    }
    else
        togglefields("findidnotself");
    update(1);
}

void Admin::on_changephoto_2_clicked()
{
    msg.pictureDimension();
    QString filename;
    filename = QFileDialog::getOpenFileName(this,tr("Open File"),"::{20D04FE0-3AEA-1069-A2D8-08002B30309D}","JPG Files (*.jpg)");
    QFile img;
    if(img.exists(CURRPATH + "/img/" + usrid + ".jpg"))
    {
        img.remove(CURRPATH + "/img/" + usrid + ".jpg");
    }
    img.copy(filename,CURRPATH + "/img/" + usrid + ".jpg");
    update(1);
}

void Admin::on_editdata_clicked()
{
    dataedit edit;
    edit.setModal(true);
    edit.passinfo(usrid,"override");
    edit.exec();
    update(1);
}

void Admin::on_apply_clicked()
{
    QString booklim,fine,bookamt;
    booklim = ui->booklim->text();
    fine = ui->fine_spin->text();
    bookamt = ui-> borrow_spin->text();
    Login conn;
    conn.sqlconnOpen();
    QSqlQuery qry;
    qry.prepare("UPDATE userdata SET booklim ='"+booklim+"',bookamt='"+bookamt+"', fine='"+fine+"' WHERE userid = '"+usrid+"'");
    if(qry.exec())
    {
        msg.databasewriteOK();
        conn.sqlconnClose();
    }
    else
        msg.databasewriteFAIL();
    update(1);
}

void Admin::on_clear_clicked()
{
    if (msg.areyousure())
    {
        Login conn;
        conn.sqlconnOpen();
        QSqlQuery qry;
        qry.prepare("UPDATE userdata SET fine =0,bookamt=0 WHERE userid = '"+usrid+"'");
        if(qry.exec())
        {
            msg.databasewriteOK();
            conn.sqlconnClose();
        }
        else
            msg.databasewriteFAIL();
        update(1);
    }
}

void Admin::on_deleteusr_clicked()
{
    msg.dangerousoperation();
    if (msg.areyousure())
    {
        dataedit edit;
        edit.deleteuser(usrid,role);
        update(1);
    }
}

void Admin::on_deleteme_clicked()
{
    update(0);
    msg.dangerousoperation();
    dataedit edit;
    edit.deleteuser(id,role);
    msg.programscram();
    this->close();
}

//Administrator Book Operation//

void Admin::on_addbook_clicked()
{
    bookregis newbook;
    newbook.setModal(true);
    newbook.exec();
}
void Admin::on_reserve_clicked()
{
    QString name, username, email;
    name = ui->name->text();
    username = ui->username->text();
    email = ui->email->text();
    Login conn;
    conn.sqlconnOpen();
    QSqlQuery qry;
    if(reserve)
        qry.prepare("UPDATE bookdata SET reserve ='0' WHERE bookid = '"+bookid+"'");
    else
        qry.prepare("UPDATE bookdata SET reserve ='1' WHERE bookid = '"+bookid+"'");

    if(qry.exec())
        {
            msg.databasewriteOK();
            conn.sqlconnClose();
        }
        else
            msg.databasewriteFAIL();
    bookupdate();
}
void Admin::bookupdate()
{
    QPixmap pix(CURRPATH + "/img/book_" + bookid + ".jpg");
    ui->picture_book->setPixmap(pix);
    Login conn;
    conn.sqlconnOpen();
    QSqlQuery qry;
    if(qry.exec("SELECT bookname,isbn,author,loanperiod,price,currentloan,reserve,bookid result FROM bookdata WHERE bookid='"+bookid +"'"))
    {
        qry.next();
        ui->bookid->setText(qry.value(7).toString());
        ui->bookname->setText(qry.value(0).toString());
        ui->isbn->setText(qry.value(1).toString());
        ui->author->setText(qry.value(2).toString());
        ui->loan->setValue(qry.value(3).toInt());
        ui->price->setValue(qry.value(4).toInt());
        ui->loaner->setText(qry.value(5).toString());
        reserve = qry.value(6).toInt();
        if(reserve)
            ui->reserve->setText("UnReserve");
        else
            ui->reserve->setText("Reserve");
        if(qry.value(7).toString()=="")
            togglefields("booknotfound");
    }
}
void Admin::on_search_clicked()
{
    togglefields("booksearch");
    bookupdate();
}
void Admin::on_edit_clicked()
{
    togglefields("bookedit");
}
void Admin::on_changebookphoto_clicked()
{
    msg.pictureDimension();
    QString filename;
    filename = QFileDialog::getOpenFileName(this,tr("Open File"),"::{20D04FE0-3AEA-1069-A2D8-08002B30309D}","JPG Files (*.jpg)");
    QFile img;
    if(img.exists(CURRPATH + "/img/book_" + bookid + ".jpg"))
    {
        img.remove(CURRPATH + "/img/book_" + bookid + ".jpg");
    }
    img.copy(filename,CURRPATH + "/img/book_" + bookid + ".jpg");
    bookupdate();
}
void Admin::on_applyedit_clicked()
{
    if (msg.informationconfirm())
    {
        QString bookname, isbn, author, loan, price;
        int loan_int, price_int;
        bookname =  ui->bookname->text();
        isbn = ui->isbn->text();
        author = ui->author->text();
        loan_int = ui->loan->value();
        price_int = ui->price->value();
        loan = QString::number(loan_int);
        price = QString::number(price_int);
        Login conn;
        conn.sqlconnOpen();
        QSqlQuery qry;
        qry.prepare("UPDATE bookdata SET bookname ='"+bookname+"',isbn ='"+isbn+"',author='"+author+"',loanperiod='"+loan+"',price='"+price+"' WHERE bookid = '"+bookid+"'");
        if(qry.exec())
        {
            msg.databasewriteOK();
            conn.sqlconnClose();
        }
        else
            msg.databasewriteFAIL();
    }
    ui->bookname->setEnabled(false);
    ui->isbn->setEnabled(false);
    ui->author->setEnabled(false);
    ui->loan->setEnabled(false);
    ui->price->setEnabled(false);
    ui->edit->setEnabled(true);
    ui->applyedit->setEnabled(false);
    bookupdate();
}
void Admin::on_clearloan_clicked()
{
    Login conn;
    if (msg.areyousure())
    {
        conn.sqlconnOpen();
        QSqlQuery qry,qry2;
        qry.prepare("UPDATE bookdata SET currentloan ='' WHERE bookid = '"+bookid+"'");
        if(qry.exec())
            QMessageBox::information(this, tr("Data Saved"), tr("The data was saved successfully.\nPlease manually clear the user's loan records."));
        else
        {
            msg.programscram();
            this->close();
        }
        conn.sqlconnClose();
        bookupdate();
    }
}
void Admin::on_delete_2_clicked()
{
    QMessageBox::warning(this, tr("Dangerous Operation!"),tr("Dangerous Operation.\nYou are about to delete the book's data and all data associated with the book.\nThis operation cannot be undone."));

    if (QMessageBox::question(this,tr("Are you sure?"),tr("Are you sure to delete the book?\nAny user that is currently loan this book will be able to obtain the book for free\nAre you sure?"))==QMessageBox::Yes)
    {
        Login conn;
        conn.sqlconnOpen();
        QSqlQuery qry;
        qry.prepare("DELETE FROM bookdata WHERE bookid = '"+bookid+"'");
        if(qry.exec())
        {
            QMessageBox::information(this, tr("Data Deleted"), tr("The data was deleted successfully."));
            conn.sqlconnClose();
            QFile rem;
            rem.remove(CURRPATH + "/img/book_" + bookid + ".jpg");
        }
        else
        {
            QMessageBox::critical(this, tr("Database Deleting Failed"),tr("Database Error.\nPlease contact the administrator."));
        }
        bookupdate();
    }
}
void Admin::on_usrreg_toggle_clicked()
{
    QString set;
    set = QString::number(!reg);
    Login conn;
    conn.sqlconnOpen();
    QSqlQuery qry;
    qry.exec("UPDATE settings SET canregister = '"+set+"' WHERE rowid = 1");
    conn.sqlconnClose();
    update(3);
}
void Admin::on_usrinfo_toggle_clicked()
{
    QString set;
    set = QString::number(!usr_editinfo);
    Login conn;
    conn.sqlconnOpen();
    QSqlQuery qry;
    qry.exec("UPDATE settings SET caneditinfo = '"+set+"' WHERE rowid = 1");
    conn.sqlconnClose();
    update(3);
}
void Admin::on_usrphoto_toggle_clicked()
{
    QString set;
    set = QString::number(!usr_changephoto);
    Login conn;
    conn.sqlconnOpen();
    QSqlQuery qry;
    qry.exec("UPDATE settings SET canchangephoto = '"+set+"' WHERE rowid = 1");
    conn.sqlconnClose();
    update(3);
}
void Admin::togglefields(QString a)
{
    if(a=="usrnotfound")
    {
        msg.querynotfound();
        ui->editdata->setEnabled(false);
        ui->changephoto_2->setEnabled(false);
        ui->deleteusr->setEnabled(false);
        ui->advanceGrp->setEnabled(false);
    }
    if(a=="user")
    {
        ui->advanceGrp->setEnabled(true);
        ui->clear->setEnabled(true);
    }
    if(a=="admin")
    {
        ui->fine_usr->setText("N/A");
        ui->bookamt_usr->setText("N/A");
        ui->booklim_usr->setText("N/A");
        ui->advanceGrp->setEnabled(false);
    }
    if(a=="findidself")
    {
        ui->editdata->setEnabled(false);
        ui->changephoto_2->setEnabled(false);
        ui->deleteusr->setEnabled(false);
        ui->advanceGrp->setEnabled(false);
    }
    if(a=="findidnotself")
    {
        ui->editdata->setEnabled(true);
        ui->changephoto_2->setEnabled(true);
        ui->deleteusr->setEnabled(true);
        ui->advanceGrp->setEnabled(true);
    }
    if(a=="booknotfound")
    {
        msg.querynotfound();
        ui->groupBox_3->setEnabled(false);
        ui->reserve->setEnabled(false);
        ui->changebookphoto->setEnabled(false);
        ui->delete_2->setEnabled(false);
        ui->clearloan->setEnabled(false);
        ui->clear->setEnabled(false);
    }
    if(a=="booksearch")
    {
        bookid = ui->searchbook->text();
        ui->groupBox_3->setEnabled(true);
        ui->reserve->setEnabled(true);
        ui->changebookphoto->setEnabled(true);
        ui->delete_2->setEnabled(true);
        ui->edit->setEnabled(true);
        ui->clearloan->setEnabled(true);
        ui->applyedit->setEnabled(false);
        ui->bookname->setEnabled(false);
        ui->isbn->setEnabled(false);
        ui->author->setEnabled(false);
        ui->loan->setEnabled(false);
        ui->price->setEnabled(false);
        ui->clear->setEnabled(true);
    }
    if(a=="bookedit")
    {
            ui->edit->setEnabled(false);
            ui->bookname->setEnabled(true);
            ui->isbn->setEnabled(true);
            ui->author->setEnabled(true);
            ui->loan->setEnabled(true);
            ui->price->setEnabled(true);
            ui->applyedit->setEnabled(true);
    }
}

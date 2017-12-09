//--------------------------------------------------//
// Bhurinuth Wongsrisakul ID:58090030  (SY2015/2)   //
// 7th SE KMITL (Object Oriented Programing Project)//
// LIMA - LIbrary Management and Administration     //
// Filename: userarea.cpp   Type: Source File       //
//--------------------------------------------------//

#include <QMessageBox>
#include <QFileDialog>
#include "userarea.h"
#include "ui_userarea.h"
#include "login.h"
#include "dataedit.h"

//User Interface Area
userarea::userarea(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::userarea)
{
    ui->setupUi(this);

    CURRPATH = QCoreApplication::applicationDirPath();
    this->setFixedSize(455,442);

}

userarea::~userarea()
{
    delete ui;
}

void userarea::settingupdate()
{
    Login conn;
    conn.sqlconnOpen();
    QSqlQuery qry;
    qry.exec("SELECT canregister, canchangephoto, caneditinfo FROM settings WHERE rowid = 1");
    qry.first();
    reg = qry.value(0).toInt();
    usr_changephoto = qry.value(1).toInt();
    usr_editinfo = qry.value(2).toInt();
}

void userarea::update()
{
    settingupdate();
    int booklim;
    Login conn;
    conn.sqlconnOpen();
    QSqlQuery dataquery;
    if(dataquery.exec("SELECT userid,fullname,email,username,fine,bookamt,booklim result FROM userdata WHERE userid='"+id +"'"))
    {
        dataquery.next();
        ui->id->setText(dataquery.value(0).toString());
        ui->name->setText(dataquery.value(1).toString());
        ui->welcome->setText("Welcome, " + dataquery.value(1).toString() + " ID# " + id);
        ui->email->setText(dataquery.value(2).toString());
        ui->username->setText(dataquery.value(3).toString());
        ui->fine->setText(dataquery.value(4).toString() + " THB");
        fine = dataquery.value(4).toInt();
        ui->bookamt->setText(dataquery.value(5).toString() + " Books");
        book = dataquery.value(5).toInt();
        ui->booklim->setText(dataquery.value(6).toString() + " Books at any time");
        booklim = dataquery.value(6).toInt();
    }
    conn.sqlconnClose();
    QPixmap pix(CURRPATH + "/img/" + id + ".jpg");
    ui->picture->setPixmap(pix);
}

void userarea::idRec(QString oID)
{
    id = oID;
    update();
}

void userarea::on_editprofile_clicked()
{
    if(usr_editinfo)
    {
        dataedit edit;
        edit.setModal(true);
        edit.passinfo(id,"norm");
        edit.exec();
        update();
    }
    else
        msg.actionForbidden();
}

void userarea::on_logout_clicked()
{
    if (msg.logoutExit())
    {
        this->close();
    }
}

void userarea::on_changephoto_clicked()
{
    if(usr_changephoto)
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
        update();
    }
    else
        msg.actionForbidden();
}

void userarea::on_deleteme_clicked()
{
    update();
    if(fine==0 && book==0)
    {
        QMessageBox::warning(this, tr("Dangerous operation"),tr("This operation cannot be undone.\nYou are about to delete you account.\nThis will cause your data to be deleted forever."));
        if (msg.areyousure())
        {
            dataedit edit;
            edit.deleteuser(id,"user");
            update();
            msg.programscram();
            this->close();
        }
    }
    else
        QMessageBox::critical(this, tr("Fine/Book in Record"),tr("This operation cannot be done.\nYou have a Fine or a Book in Record.\nPlease contact the administrator or clear your records."));

}

//User Book Interface area//

void userarea::bookupdate()
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
        ui->loan->setText(qry.value(3).toString());
        ui->price->setText(qry.value(4).toString());
        fine_book = qry.value(4).toInt();
        ui->loaner->setText(qry.value(5).toString());

    }
    if(qry.value(5).toString() == id)
    {
        ui->lost->setEnabled(true);
        ui->loaner->setText("You");
        ui->return_2->setEnabled(true);
    }
    else
        ui->lost->setEnabled(false);
    if(!qry.value(6).toInt())
        ui->borrow->setEnabled(true);
    else
        ui->borrow->setEnabled(false);
    if(qry.value(7).toString()=="")
    {
        msg.querynotfound();
        ui->borrow->setEnabled(false);
        ui->return_2->setEnabled(false);
        ui->lost->setEnabled(false);
    }
    conn.sqlconnClose();
}

void userarea::on_search_clicked()
{
    bookid = ui->searchbook->text();
    bookupdate();
    update();
}

void userarea::on_borrow_clicked()
{
    if (QMessageBox::question(this,tr("Are you sure?"),tr("Are you sure you want to borrow this book?"))==QMessageBox::Yes)
    {
        book += 1;
        Login conn;
        conn.sqlconnOpen();
        QSqlQuery qry,qry2;
        qry.exec("UPDATE userdata SET bookamt = '"+QString::number(book)+"' WHERE userid = '"+id+"'");
        qry2.exec("UPDATE bookdata SET currentloan = '"+id+"',reserve = '1' WHERE bookid = '"+bookid+"'");
        bookupdate();
        QMessageBox::information(this,tr("Data Saved?"),tr("The book has been borrowed successfully."));
        conn.sqlconnClose();
        update();
    }
}

void userarea::on_return_2_clicked()
{
    if (QMessageBox::question(this,tr("Are you sure?"),tr("Are you sure you want to return this book?"))==QMessageBox::Yes)
    {
        book -= 1;
        Login conn;
        conn.sqlconnOpen();
        QSqlQuery qry,qry2;
        qry.exec("UPDATE userdata SET bookamt = '"+QString::number(book)+"' WHERE userid = '"+id+"'");
        qry2.exec("UPDATE bookdata SET currentloan = '',reserve = '0' WHERE bookid = '"+bookid+"'");
        bookupdate();
        QMessageBox::information(this,tr("Data Saved?"),tr("The book has been returned successfully."));
        conn.sqlconnClose();
        update();
    }
}

void userarea::on_lost_clicked()
{
    QMessageBox::warning(this,tr("You will be fined"),tr("If you report a lost book, you will be fined to the total amount of the book with an additional processing fee."));
    if (QMessageBox::question(this,tr("Are you sure?"),tr("Are you sure you want to report this book as a lost book?\nYou will be fined to the total amount of the book plus the processing fee of 500THB."))==QMessageBox::Yes)
    {
        fine = fine + fine_book+500;
        Login conn;
        conn.sqlconnOpen();
        QSqlQuery qry,qry2;
        qry.exec("UPDATE userdata SET fine = '"+QString::number(fine)+"' WHERE userid = '"+id+"'");
        qry2.exec("UPDATE bookdata SET currentloan = 'LOST',reserve = '1' WHERE bookid = '"+bookid+"'");
        bookupdate();
        QMessageBox::information(this,tr("Data Saved?"),tr("The book has been reported LOST successfully."));
        conn.sqlconnClose();
        update();
    }
}

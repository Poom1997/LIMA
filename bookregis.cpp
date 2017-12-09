//--------------------------------------------------//
// Bhurinuth Wongsrisakul ID:58090030  (SY2015/2)   //
// 7th SE KMITL (Object Oriented Programing Project)//
// LIMA - LIbrary Management and Administration     //
// Filename: bookregis.cpp   Type: Source File      //
//--------------------------------------------------//

#include "bookregis.h"
#include "ui_bookregis.h"

//Book Registration//

bookregis::bookregis(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::bookregis)
{
    ui->setupUi(this);

    CURRPATH = QCoreApplication::applicationDirPath();

    Login conn;
    if(!conn.sqlconnOpen())
        ui->dbstatus->setText("Offline");
    else
        ui->dbstatus->setText("Online");

    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    this->setFixedSize(398,277);
}

bookregis::~bookregis()
{
    delete ui;
}
void bookregis::on_editok_clicked()
{
    bool complete=true;
    QString id, name, isbn, author,loan_str,price_str;
    int loan, price;
    id = ui->id->text();
    name = ui->name->text();
    isbn = ui->isbn->text();
    author = ui->author->text();
    loan = ui->loan->value();
    price = ui->price->value();
    loan_str = QString::number(loan);
    price_str = QString::number(price);
    Login conn;
    conn.sqlconnOpen();
    QSqlQuery sameID;
    sameID.exec("SELECT bookid FROM bookdata WHERE bookid = '"+id+"'");
    while(sameID.next())
    {
        QString check;
        check = sameID.value(0).toString();
        if(id == check)
        {
            msg.duplicatebookID();
            complete = false;
            break;
        }
    }
    if((id=="")||(name=="")||(isbn=="")||(author==""))
    {
        msg.empty();
        complete = false;
    }
    if(complete)
    {
        QSqlQuery qry;
        qry.prepare("INSERT INTO bookdata (bookid,bookname,isbn,author,loanperiod,price,currentloan,reserve) VALUES('"+id+"','"+name+"','"+isbn+"','"+author+"','"+loan_str+"','"+price_str+"','','0')");
        if (msg.informationconfirm())
        {
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
void bookregis::on_cancel_clicked()
{
    if (msg.cancel())
        this->close();
}

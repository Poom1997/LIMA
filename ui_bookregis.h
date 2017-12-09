/********************************************************************************
** Form generated from reading UI file 'bookregis.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOKREGIS_H
#define UI_BOOKREGIS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_bookregis
{
public:
    QGroupBox *groupBox;
    QLabel *name_label;
    QLabel *id_label;
    QLabel *email_label;
    QLabel *usern_label;
    QLineEdit *id;
    QLineEdit *name;
    QLineEdit *isbn;
    QLineEdit *author;
    QLabel *loan_label_2;
    QLabel *loan_label;
    QLabel *price_label;
    QLabel *price_label_2;
    QSpinBox *loan;
    QSpinBox *price;
    QPushButton *editok;
    QPushButton *cancel;
    QLabel *dbstatus;

    void setupUi(QDialog *bookregis)
    {
        if (bookregis->objectName().isEmpty())
            bookregis->setObjectName(QStringLiteral("bookregis"));
        bookregis->resize(398, 277);
        bookregis->setSizeGripEnabled(false);
        groupBox = new QGroupBox(bookregis);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setEnabled(true);
        groupBox->setGeometry(QRect(20, 10, 281, 251));
        name_label = new QLabel(groupBox);
        name_label->setObjectName(QStringLiteral("name_label"));
        name_label->setGeometry(QRect(20, 50, 61, 16));
        id_label = new QLabel(groupBox);
        id_label->setObjectName(QStringLiteral("id_label"));
        id_label->setGeometry(QRect(20, 20, 21, 16));
        email_label = new QLabel(groupBox);
        email_label->setObjectName(QStringLiteral("email_label"));
        email_label->setGeometry(QRect(20, 80, 61, 16));
        usern_label = new QLabel(groupBox);
        usern_label->setObjectName(QStringLiteral("usern_label"));
        usern_label->setGeometry(QRect(20, 110, 51, 16));
        id = new QLineEdit(groupBox);
        id->setObjectName(QStringLiteral("id"));
        id->setEnabled(true);
        id->setGeometry(QRect(130, 20, 141, 20));
        name = new QLineEdit(groupBox);
        name->setObjectName(QStringLiteral("name"));
        name->setGeometry(QRect(130, 50, 141, 20));
        isbn = new QLineEdit(groupBox);
        isbn->setObjectName(QStringLiteral("isbn"));
        isbn->setGeometry(QRect(130, 80, 141, 20));
        author = new QLineEdit(groupBox);
        author->setObjectName(QStringLiteral("author"));
        author->setGeometry(QRect(130, 110, 141, 20));
        loan_label_2 = new QLabel(groupBox);
        loan_label_2->setObjectName(QStringLiteral("loan_label_2"));
        loan_label_2->setGeometry(QRect(180, 140, 61, 16));
        loan_label = new QLabel(groupBox);
        loan_label->setObjectName(QStringLiteral("loan_label"));
        loan_label->setGeometry(QRect(20, 140, 71, 16));
        price_label = new QLabel(groupBox);
        price_label->setObjectName(QStringLiteral("price_label"));
        price_label->setGeometry(QRect(20, 170, 71, 16));
        price_label_2 = new QLabel(groupBox);
        price_label_2->setObjectName(QStringLiteral("price_label_2"));
        price_label_2->setGeometry(QRect(200, 170, 51, 16));
        loan = new QSpinBox(groupBox);
        loan->setObjectName(QStringLiteral("loan"));
        loan->setGeometry(QRect(130, 140, 42, 22));
        loan->setMinimum(1);
        loan->setMaximum(731);
        price = new QSpinBox(groupBox);
        price->setObjectName(QStringLiteral("price"));
        price->setGeometry(QRect(130, 170, 61, 22));
        price->setAccelerated(false);
        price->setMinimum(10);
        price->setMaximum(10000);
        price->setSingleStep(10);
        editok = new QPushButton(bookregis);
        editok->setObjectName(QStringLiteral("editok"));
        editok->setGeometry(QRect(310, 20, 75, 23));
        cancel = new QPushButton(bookregis);
        cancel->setObjectName(QStringLiteral("cancel"));
        cancel->setGeometry(QRect(310, 50, 75, 23));
        dbstatus = new QLabel(bookregis);
        dbstatus->setObjectName(QStringLiteral("dbstatus"));
        dbstatus->setGeometry(QRect(320, 230, 51, 20));

        retranslateUi(bookregis);

        QMetaObject::connectSlotsByName(bookregis);
    } // setupUi

    void retranslateUi(QDialog *bookregis)
    {
        bookregis->setWindowTitle(QApplication::translate("bookregis", "Edit Information - LIMA V1.0", 0));
        groupBox->setTitle(QApplication::translate("bookregis", "New Book Registeration", 0));
        name_label->setText(QApplication::translate("bookregis", "Book Name", 0));
        id_label->setText(QApplication::translate("bookregis", "ID", 0));
        email_label->setText(QApplication::translate("bookregis", "Book ISBN", 0));
        usern_label->setText(QApplication::translate("bookregis", "Author", 0));
        name->setText(QString());
        loan_label_2->setText(QApplication::translate("bookregis", "Days", 0));
        loan_label->setText(QApplication::translate("bookregis", "Loan Period:", 0));
        price_label->setText(QApplication::translate("bookregis", "Book Price:", 0));
        price_label_2->setText(QApplication::translate("bookregis", "THB", 0));
        editok->setText(QApplication::translate("bookregis", "OK", 0));
        cancel->setText(QApplication::translate("bookregis", "Cancel", 0));
        dbstatus->setText(QApplication::translate("bookregis", "[+] Status", 0));
    } // retranslateUi

};

namespace Ui {
    class bookregis: public Ui_bookregis {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKREGIS_H

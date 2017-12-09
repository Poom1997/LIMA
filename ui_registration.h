/********************************************************************************
** Form generated from reading UI file 'registration.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRATION_H
#define UI_REGISTRATION_H

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

QT_BEGIN_NAMESPACE

class Ui_Registration
{
public:
    QGroupBox *groupBox;
    QLabel *fulln;
    QLabel *idnum;
    QLabel *emailaddr;
    QLabel *usern;
    QLabel *pasw;
    QLabel *confpasw;
    QLineEdit *role;
    QLabel *role_2;
    QLineEdit *id;
    QLineEdit *name;
    QLineEdit *email;
    QLineEdit *username;
    QLineEdit *password;
    QLineEdit *confirmpass;
    QPushButton *registerok;
    QPushButton *pushButton;
    QLabel *dbstatus;

    void setupUi(QDialog *registration)
    {
        if (registration->objectName().isEmpty())
            registration->setObjectName(QStringLiteral("registration"));
        registration->resize(398, 277);
        registration->setSizeGripEnabled(false);
        groupBox = new QGroupBox(registration);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 10, 261, 251));
        fulln = new QLabel(groupBox);
        fulln->setObjectName(QStringLiteral("fulln"));
        fulln->setGeometry(QRect(20, 50, 51, 16));
        idnum = new QLabel(groupBox);
        idnum->setObjectName(QStringLiteral("idnum"));
        idnum->setGeometry(QRect(20, 20, 21, 16));
        emailaddr = new QLabel(groupBox);
        emailaddr->setObjectName(QStringLiteral("emailaddr"));
        emailaddr->setGeometry(QRect(20, 80, 47, 13));
        usern = new QLabel(groupBox);
        usern->setObjectName(QStringLiteral("usern"));
        usern->setGeometry(QRect(20, 110, 51, 16));
        pasw = new QLabel(groupBox);
        pasw->setObjectName(QStringLiteral("pasw"));
        pasw->setGeometry(QRect(20, 140, 51, 16));
        confpasw = new QLabel(groupBox);
        confpasw->setObjectName(QStringLiteral("confpasw"));
        confpasw->setGeometry(QRect(20, 170, 91, 16));
        role = new QLineEdit(groupBox);
        role->setObjectName(QStringLiteral("role"));
        role->setEnabled(false);
        role->setGeometry(QRect(130, 200, 113, 20));
        role_2 = new QLabel(groupBox);
        role_2->setObjectName(QStringLiteral("role_2"));
        role_2->setGeometry(QRect(20, 200, 47, 13));
        id = new QLineEdit(groupBox);
        id->setObjectName(QStringLiteral("id"));
        id->setGeometry(QRect(130, 20, 113, 20));
        name = new QLineEdit(groupBox);
        name->setObjectName(QStringLiteral("name"));
        name->setGeometry(QRect(130, 50, 113, 20));
        email = new QLineEdit(groupBox);
        email->setObjectName(QStringLiteral("email"));
        email->setGeometry(QRect(130, 80, 113, 20));
        username = new QLineEdit(groupBox);
        username->setObjectName(QStringLiteral("username"));
        username->setGeometry(QRect(130, 110, 113, 20));
        password = new QLineEdit(groupBox);
        password->setObjectName(QStringLiteral("password"));
        password->setGeometry(QRect(130, 140, 113, 20));
        password->setEchoMode(QLineEdit::Password);
        confirmpass = new QLineEdit(groupBox);
        confirmpass->setObjectName(QStringLiteral("confirmpass"));
        confirmpass->setGeometry(QRect(130, 170, 113, 20));
        confirmpass->setEchoMode(QLineEdit::Password);
        registerok = new QPushButton(registration);
        registerok->setObjectName(QStringLiteral("registerok"));
        registerok->setGeometry(QRect(300, 20, 75, 23));
        pushButton = new QPushButton(registration);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(300, 50, 75, 23));
        dbstatus = new QLabel(registration);
        dbstatus->setObjectName(QStringLiteral("dbstatus"));
        dbstatus->setGeometry(QRect(320, 230, 51, 20));

        retranslateUi(registration);

        QMetaObject::connectSlotsByName(registration);
    } // setupUi

    void retranslateUi(QDialog *registration)
    {
        registration->setWindowTitle(QApplication::translate("Registration", "New User - LIMA V1.0", 0));
        groupBox->setTitle(QApplication::translate("Registration", "Register New User", 0));
        fulln->setText(QApplication::translate("Registration", "Full Name", 0));
        idnum->setText(QApplication::translate("Registration", "ID", 0));
        emailaddr->setText(QApplication::translate("Registration", "E-Mail", 0));
        usern->setText(QApplication::translate("Registration", "Username", 0));
        pasw->setText(QApplication::translate("Registration", "Password", 0));
        confpasw->setText(QApplication::translate("Registration", "Confirm Password", 0));
        role->setText(QApplication::translate("Registration", "user", 0));
        role_2->setText(QApplication::translate("Registration", "Role", 0));
        registerok->setText(QApplication::translate("Registration", "Register", 0));
        pushButton->setText(QApplication::translate("Registration", "Cancel", 0));
        dbstatus->setText(QApplication::translate("Registration", "[+] Status", 0));
    } // retranslateUi

};

namespace Ui {
    class Registration: public Ui_Registration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRATION_H

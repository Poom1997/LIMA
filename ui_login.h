/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QWidget *centralWidget;
    QLabel *dbstatus;
    QGroupBox *login;
    QLineEdit *username;
    QLineEdit *password;
    QLabel *label_username;
    QLabel *label_password;
    QPushButton *loginbutton;
    QPushButton *registernew;
    QLabel *loginPicture;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QStringLiteral("Login"));
        Login->resize(400, 238);
        Login->setDockNestingEnabled(false);
        centralWidget = new QWidget(Login);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        dbstatus = new QLabel(centralWidget);
        dbstatus->setObjectName(QStringLiteral("dbstatus"));
        dbstatus->setGeometry(QRect(20, 190, 331, 31));
        login = new QGroupBox(centralWidget);
        login->setObjectName(QStringLiteral("login"));
        login->setGeometry(QRect(150, 10, 231, 171));
        username = new QLineEdit(login);
        username->setObjectName(QStringLiteral("username"));
        username->setGeometry(QRect(80, 50, 113, 20));
        password = new QLineEdit(login);
        password->setObjectName(QStringLiteral("password"));
        password->setGeometry(QRect(80, 80, 113, 20));
        password->setEchoMode(QLineEdit::Password);
        label_username = new QLabel(login);
        label_username->setObjectName(QStringLiteral("label_username"));
        label_username->setGeometry(QRect(20, 50, 51, 16));
        label_password = new QLabel(login);
        label_password->setObjectName(QStringLiteral("label_password"));
        label_password->setGeometry(QRect(20, 80, 51, 16));
        loginbutton = new QPushButton(login);
        loginbutton->setObjectName(QStringLiteral("loginbutton"));
        loginbutton->setGeometry(QRect(120, 130, 75, 23));
        registernew = new QPushButton(login);
        registernew->setObjectName(QStringLiteral("registernew"));
        registernew->setGeometry(QRect(40, 130, 75, 23));
        loginPicture = new QLabel(centralWidget);
        loginPicture->setObjectName(QStringLiteral("loginPicture"));
        loginPicture->setGeometry(QRect(10, 40, 131, 131));
        loginPicture->setPixmap(QPixmap(QString::fromUtf8("debug/img/login.png")));
        loginPicture->setScaledContents(true);
        Login->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Login);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 21));
        Login->setMenuBar(menuBar);

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QMainWindow *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "Login - LIMA V1.0", 0));
        dbstatus->setText(QApplication::translate("Login", "[+]Status", 0));
        login->setTitle(QApplication::translate("Login", "User Credentials", 0));
        label_username->setText(QApplication::translate("Login", "Username", 0));
        label_password->setText(QApplication::translate("Login", "Password", 0));
        loginbutton->setText(QApplication::translate("Login", "Login", 0));
        registernew->setText(QApplication::translate("Login", "Register", 0));
        loginPicture->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H

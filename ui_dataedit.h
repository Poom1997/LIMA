/********************************************************************************
** Form generated from reading UI file 'dataedit.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATAEDIT_H
#define UI_DATAEDIT_H

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

class Ui_dataedit
{
public:
    QGroupBox *groupBox;
    QLabel *name_label;
    QLabel *id_label;
    QLabel *email_label;
    QLabel *usern_label;
    QLabel *pasw_label;
    QLabel *confpasw_label;
    QLineEdit *role;
    QLabel *role_label;
    QLineEdit *id;
    QLineEdit *name;
    QLineEdit *email;
    QLineEdit *username;
    QLineEdit *password;
    QLineEdit *confirmpass;
    QPushButton *editok;
    QPushButton *cancel;
    QLabel *dbstatus;
    QPushButton *changepasw;
    QPushButton *changerole;

    void setupUi(QDialog *dataedit)
    {
        if (dataedit->objectName().isEmpty())
            dataedit->setObjectName(QStringLiteral("dataedit"));
        dataedit->resize(398, 277);
        dataedit->setSizeGripEnabled(false);
        groupBox = new QGroupBox(dataedit);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setEnabled(true);
        groupBox->setGeometry(QRect(20, 10, 281, 251));
        name_label = new QLabel(groupBox);
        name_label->setObjectName(QStringLiteral("name_label"));
        name_label->setGeometry(QRect(20, 50, 51, 16));
        id_label = new QLabel(groupBox);
        id_label->setObjectName(QStringLiteral("id_label"));
        id_label->setGeometry(QRect(20, 20, 21, 16));
        email_label = new QLabel(groupBox);
        email_label->setObjectName(QStringLiteral("email_label"));
        email_label->setGeometry(QRect(20, 80, 47, 13));
        usern_label = new QLabel(groupBox);
        usern_label->setObjectName(QStringLiteral("usern_label"));
        usern_label->setGeometry(QRect(20, 110, 51, 16));
        pasw_label = new QLabel(groupBox);
        pasw_label->setObjectName(QStringLiteral("pasw_label"));
        pasw_label->setGeometry(QRect(20, 140, 51, 16));
        confpasw_label = new QLabel(groupBox);
        confpasw_label->setObjectName(QStringLiteral("confpasw_label"));
        confpasw_label->setGeometry(QRect(20, 170, 91, 16));
        role = new QLineEdit(groupBox);
        role->setObjectName(QStringLiteral("role"));
        role->setEnabled(false);
        role->setGeometry(QRect(130, 200, 141, 20));
        role_label = new QLabel(groupBox);
        role_label->setObjectName(QStringLiteral("role_label"));
        role_label->setGeometry(QRect(20, 200, 47, 13));
        id = new QLineEdit(groupBox);
        id->setObjectName(QStringLiteral("id"));
        id->setEnabled(false);
        id->setGeometry(QRect(130, 20, 141, 20));
        name = new QLineEdit(groupBox);
        name->setObjectName(QStringLiteral("name"));
        name->setGeometry(QRect(130, 50, 141, 20));
        email = new QLineEdit(groupBox);
        email->setObjectName(QStringLiteral("email"));
        email->setGeometry(QRect(130, 80, 141, 20));
        username = new QLineEdit(groupBox);
        username->setObjectName(QStringLiteral("username"));
        username->setGeometry(QRect(130, 110, 141, 20));
        password = new QLineEdit(groupBox);
        password->setObjectName(QStringLiteral("password"));
        password->setEnabled(false);
        password->setGeometry(QRect(130, 140, 141, 20));
        password->setEchoMode(QLineEdit::Password);
        confirmpass = new QLineEdit(groupBox);
        confirmpass->setObjectName(QStringLiteral("confirmpass"));
        confirmpass->setEnabled(false);
        confirmpass->setGeometry(QRect(130, 170, 141, 20));
        confirmpass->setEchoMode(QLineEdit::Password);
        editok = new QPushButton(dataedit);
        editok->setObjectName(QStringLiteral("editok"));
        editok->setGeometry(QRect(310, 20, 75, 23));
        cancel = new QPushButton(dataedit);
        cancel->setObjectName(QStringLiteral("cancel"));
        cancel->setGeometry(QRect(310, 50, 75, 23));
        dbstatus = new QLabel(dataedit);
        dbstatus->setObjectName(QStringLiteral("dbstatus"));
        dbstatus->setGeometry(QRect(320, 230, 51, 20));
        changepasw = new QPushButton(dataedit);
        changepasw->setObjectName(QStringLiteral("changepasw"));
        changepasw->setGeometry(QRect(310, 100, 75, 23));
        changerole = new QPushButton(dataedit);
        changerole->setObjectName(QStringLiteral("changerole"));
        changerole->setGeometry(QRect(310, 130, 75, 23));

        retranslateUi(dataedit);

        QMetaObject::connectSlotsByName(dataedit);
    } // setupUi

    void retranslateUi(QDialog *dataedit)
    {
        dataedit->setWindowTitle(QApplication::translate("dataedit", "Edit Information - LIMA V1.0", 0));
        groupBox->setTitle(QApplication::translate("dataedit", "Edit Data", 0));
        name_label->setText(QApplication::translate("dataedit", "Full Name", 0));
        id_label->setText(QApplication::translate("dataedit", "ID", 0));
        email_label->setText(QApplication::translate("dataedit", "E-Mail", 0));
        usern_label->setText(QApplication::translate("dataedit", "Username", 0));
        pasw_label->setText(QApplication::translate("dataedit", "Password", 0));
        confpasw_label->setText(QApplication::translate("dataedit", "Confirm Password", 0));
        role->setText(QString());
        role_label->setText(QApplication::translate("dataedit", "Role", 0));
        name->setText(QString());
        editok->setText(QApplication::translate("dataedit", "Apply", 0));
        cancel->setText(QApplication::translate("dataedit", "Cancel", 0));
        dbstatus->setText(QApplication::translate("dataedit", "[+] Status", 0));
        changepasw->setText(QApplication::translate("dataedit", "Password", 0));
        changerole->setText(QApplication::translate("dataedit", "Change Role", 0));
    } // retranslateUi

};

namespace Ui {
    class dataedit: public Ui_dataedit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATAEDIT_H

/********************************************************************************
** Form generated from reading UI file 'editdata.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITDATA_H
#define UI_EDITDATA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_editdata
{
public:
    QGroupBox *groupBox;
    QLabel *id_label;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *dbstatus;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;

    void setupUi(QDialog *editdata)
    {
        if (editdata->objectName().isEmpty())
            editdata->setObjectName(QStringLiteral("editdata"));
        editdata->resize(398, 277);
        groupBox = new QGroupBox(editdata);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 291, 251));
        id_label = new QLabel(groupBox);
        id_label->setObjectName(QStringLiteral("id_label"));
        id_label->setGeometry(QRect(10, 20, 61, 16));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 40, 61, 16));
        pushButton = new QPushButton(editdata);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(310, 20, 75, 23));
        pushButton_2 = new QPushButton(editdata);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(310, 50, 75, 23));
        dbstatus = new QLabel(editdata);
        dbstatus->setObjectName(QStringLiteral("dbstatus"));
        dbstatus->setGeometry(QRect(330, 240, 61, 16));
        pushButton_3 = new QPushButton(editdata);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(310, 110, 75, 23));
        pushButton_4 = new QPushButton(editdata);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(310, 140, 75, 23));
        groupBox->raise();
        pushButton->raise();
        pushButton_2->raise();
        dbstatus->raise();
        pushButton_3->raise();
        pushButton_4->raise();

        retranslateUi(editdata);

        QMetaObject::connectSlotsByName(editdata);
    } // setupUi

    void retranslateUi(QDialog *editdata)
    {
        editdata->setWindowTitle(QApplication::translate("editdata", "Dialog", 0));
        groupBox->setTitle(QApplication::translate("editdata", "Edit User Data", 0));
        id_label->setText(QApplication::translate("editdata", "ID Number:", 0));
        label->setText(QApplication::translate("editdata", "Full Name:", 0));
        pushButton->setText(QApplication::translate("editdata", "Edit Data", 0));
        pushButton_2->setText(QApplication::translate("editdata", "Cancel", 0));
        dbstatus->setText(QApplication::translate("editdata", "[+] Status", 0));
        pushButton_3->setText(QApplication::translate("editdata", "Promote", 0));
        pushButton_4->setText(QApplication::translate("editdata", "Demote", 0));
    } // retranslateUi

};

namespace Ui {
    class editdata: public Ui_editdata {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITDATA_H

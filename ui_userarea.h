/********************************************************************************
** Form generated from reading UI file 'userarea.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERAREA_H
#define UI_USERAREA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_userarea
{
public:
    QAction *actionLogout;
    QWidget *centralwidget;
    QTabWidget *usertabs;
    QWidget *UserData;
    QLabel *picture;
    QPushButton *changephoto;
    QPushButton *editprofile;
    QGroupBox *groupBox;
    QLabel *role_label;
    QLabel *role;
    QLabel *fine_label;
    QLabel *fine;
    QLabel *username_label;
    QLabel *username;
    QLabel *email;
    QLabel *id;
    QLabel *name;
    QLabel *fullname_label;
    QLabel *email_label;
    QLabel *id_label;
    QLabel *bookamt_label;
    QFrame *line;
    QLabel *bookamt;
    QLabel *booklim_label;
    QLabel *booklim;
    QPushButton *deleteme;
    QWidget *tab_2;
    QGroupBox *groupBox_3;
    QLabel *bookname_label;
    QLabel *ISBN_label;
    QLabel *bookid_labe;
    QLabel *bookid;
    QLabel *author_label;
    QLabel *loan_label;
    QLabel *loan_label_2;
    QLabel *loaner_label;
    QLabel *loaner;
    QLabel *price_label;
    QLabel *price_label_2;
    QLabel *bookname;
    QLabel *isbn;
    QLabel *author;
    QLabel *loan;
    QLabel *price;
    QLabel *label_2;
    QLineEdit *searchbook;
    QPushButton *search;
    QLabel *picture_book;
    QPushButton *borrow;
    QPushButton *return_2;
    QPushButton *lost;
    QLabel *welcome;
    QPushButton *logout;
    QMenuBar *menubar;

    void setupUi(QMainWindow *userarea)
    {
        if (userarea->objectName().isEmpty())
            userarea->setObjectName(QStringLiteral("userarea"));
        userarea->resize(455, 439);
        actionLogout = new QAction(userarea);
        actionLogout->setObjectName(QStringLiteral("actionLogout"));
        centralwidget = new QWidget(userarea);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        usertabs = new QTabWidget(centralwidget);
        usertabs->setObjectName(QStringLiteral("usertabs"));
        usertabs->setGeometry(QRect(10, 10, 431, 381));
        usertabs->setAutoFillBackground(true);
        UserData = new QWidget();
        UserData->setObjectName(QStringLiteral("UserData"));
        picture = new QLabel(UserData);
        picture->setObjectName(QStringLiteral("picture"));
        picture->setGeometry(QRect(20, 20, 161, 201));
        picture->setFrameShape(QFrame::Box);
        changephoto = new QPushButton(UserData);
        changephoto->setObjectName(QStringLiteral("changephoto"));
        changephoto->setEnabled(true);
        changephoto->setGeometry(QRect(20, 230, 81, 23));
        editprofile = new QPushButton(UserData);
        editprofile->setObjectName(QStringLiteral("editprofile"));
        editprofile->setGeometry(QRect(110, 230, 75, 23));
        groupBox = new QGroupBox(UserData);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(200, 20, 211, 201));
        role_label = new QLabel(groupBox);
        role_label->setObjectName(QStringLiteral("role_label"));
        role_label->setGeometry(QRect(10, 100, 51, 16));
        role = new QLabel(groupBox);
        role->setObjectName(QStringLiteral("role"));
        role->setGeometry(QRect(70, 100, 71, 16));
        fine_label = new QLabel(groupBox);
        fine_label->setObjectName(QStringLiteral("fine_label"));
        fine_label->setGeometry(QRect(10, 140, 47, 13));
        fine = new QLabel(groupBox);
        fine->setObjectName(QStringLiteral("fine"));
        fine->setGeometry(QRect(70, 140, 47, 13));
        username_label = new QLabel(groupBox);
        username_label->setObjectName(QStringLiteral("username_label"));
        username_label->setGeometry(QRect(10, 80, 51, 16));
        username = new QLabel(groupBox);
        username->setObjectName(QStringLiteral("username"));
        username->setGeometry(QRect(70, 80, 111, 16));
        email = new QLabel(groupBox);
        email->setObjectName(QStringLiteral("email"));
        email->setGeometry(QRect(70, 60, 131, 16));
        id = new QLabel(groupBox);
        id->setObjectName(QStringLiteral("id"));
        id->setGeometry(QRect(70, 40, 91, 16));
        name = new QLabel(groupBox);
        name->setObjectName(QStringLiteral("name"));
        name->setGeometry(QRect(70, 20, 131, 16));
        fullname_label = new QLabel(groupBox);
        fullname_label->setObjectName(QStringLiteral("fullname_label"));
        fullname_label->setGeometry(QRect(10, 20, 51, 16));
        email_label = new QLabel(groupBox);
        email_label->setObjectName(QStringLiteral("email_label"));
        email_label->setGeometry(QRect(10, 60, 47, 13));
        id_label = new QLabel(groupBox);
        id_label->setObjectName(QStringLiteral("id_label"));
        id_label->setGeometry(QRect(10, 40, 61, 16));
        bookamt_label = new QLabel(groupBox);
        bookamt_label->setObjectName(QStringLiteral("bookamt_label"));
        bookamt_label->setGeometry(QRect(10, 160, 81, 16));
        line = new QFrame(groupBox);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(10, 120, 191, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        bookamt = new QLabel(groupBox);
        bookamt->setObjectName(QStringLiteral("bookamt"));
        bookamt->setGeometry(QRect(90, 160, 101, 16));
        booklim_label = new QLabel(groupBox);
        booklim_label->setObjectName(QStringLiteral("booklim_label"));
        booklim_label->setGeometry(QRect(10, 180, 51, 16));
        booklim = new QLabel(groupBox);
        booklim->setObjectName(QStringLiteral("booklim"));
        booklim->setGeometry(QRect(70, 180, 171, 16));
        deleteme = new QPushButton(UserData);
        deleteme->setObjectName(QStringLiteral("deleteme"));
        deleteme->setGeometry(QRect(60, 260, 91, 23));
        usertabs->addTab(UserData, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        groupBox_3 = new QGroupBox(tab_2);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setEnabled(true);
        groupBox_3->setGeometry(QRect(180, 40, 241, 221));
        bookname_label = new QLabel(groupBox_3);
        bookname_label->setObjectName(QStringLiteral("bookname_label"));
        bookname_label->setGeometry(QRect(10, 40, 71, 16));
        ISBN_label = new QLabel(groupBox_3);
        ISBN_label->setObjectName(QStringLiteral("ISBN_label"));
        ISBN_label->setGeometry(QRect(10, 70, 61, 16));
        bookid_labe = new QLabel(groupBox_3);
        bookid_labe->setObjectName(QStringLiteral("bookid_labe"));
        bookid_labe->setGeometry(QRect(10, 20, 61, 16));
        bookid = new QLabel(groupBox_3);
        bookid->setObjectName(QStringLiteral("bookid"));
        bookid->setGeometry(QRect(80, 20, 131, 16));
        author_label = new QLabel(groupBox_3);
        author_label->setObjectName(QStringLiteral("author_label"));
        author_label->setGeometry(QRect(10, 100, 51, 16));
        loan_label = new QLabel(groupBox_3);
        loan_label->setObjectName(QStringLiteral("loan_label"));
        loan_label->setGeometry(QRect(10, 130, 71, 16));
        loan_label_2 = new QLabel(groupBox_3);
        loan_label_2->setObjectName(QStringLiteral("loan_label_2"));
        loan_label_2->setGeometry(QRect(130, 130, 61, 16));
        loaner_label = new QLabel(groupBox_3);
        loaner_label->setObjectName(QStringLiteral("loaner_label"));
        loaner_label->setGeometry(QRect(10, 190, 81, 16));
        loaner = new QLabel(groupBox_3);
        loaner->setObjectName(QStringLiteral("loaner"));
        loaner->setGeometry(QRect(90, 190, 111, 16));
        price_label = new QLabel(groupBox_3);
        price_label->setObjectName(QStringLiteral("price_label"));
        price_label->setGeometry(QRect(10, 160, 71, 16));
        price_label_2 = new QLabel(groupBox_3);
        price_label_2->setObjectName(QStringLiteral("price_label_2"));
        price_label_2->setGeometry(QRect(130, 160, 51, 16));
        bookname = new QLabel(groupBox_3);
        bookname->setObjectName(QStringLiteral("bookname"));
        bookname->setGeometry(QRect(80, 40, 151, 16));
        isbn = new QLabel(groupBox_3);
        isbn->setObjectName(QStringLiteral("isbn"));
        isbn->setGeometry(QRect(80, 70, 121, 16));
        author = new QLabel(groupBox_3);
        author->setObjectName(QStringLiteral("author"));
        author->setGeometry(QRect(80, 100, 151, 16));
        loan = new QLabel(groupBox_3);
        loan->setObjectName(QStringLiteral("loan"));
        loan->setGeometry(QRect(80, 130, 51, 16));
        price = new QLabel(groupBox_3);
        price->setObjectName(QStringLiteral("price"));
        price->setGeometry(QRect(80, 160, 71, 16));
        label_2 = new QLabel(tab_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 10, 81, 16));
        searchbook = new QLineEdit(tab_2);
        searchbook->setObjectName(QStringLiteral("searchbook"));
        searchbook->setGeometry(QRect(100, 10, 151, 20));
        search = new QPushButton(tab_2);
        search->setObjectName(QStringLiteral("search"));
        search->setGeometry(QRect(260, 10, 75, 23));
        picture_book = new QLabel(tab_2);
        picture_book->setObjectName(QStringLiteral("picture_book"));
        picture_book->setGeometry(QRect(10, 50, 161, 201));
        picture_book->setFrameShape(QFrame::Box);
        borrow = new QPushButton(tab_2);
        borrow->setObjectName(QStringLiteral("borrow"));
        borrow->setEnabled(false);
        borrow->setGeometry(QRect(180, 270, 75, 23));
        return_2 = new QPushButton(tab_2);
        return_2->setObjectName(QStringLiteral("return_2"));
        return_2->setEnabled(false);
        return_2->setGeometry(QRect(260, 270, 75, 23));
        lost = new QPushButton(tab_2);
        lost->setObjectName(QStringLiteral("lost"));
        lost->setEnabled(false);
        lost->setGeometry(QRect(340, 270, 75, 23));
        usertabs->addTab(tab_2, QString());
        welcome = new QLabel(centralwidget);
        welcome->setObjectName(QStringLiteral("welcome"));
        welcome->setGeometry(QRect(20, 400, 241, 20));
        logout = new QPushButton(centralwidget);
        logout->setObjectName(QStringLiteral("logout"));
        logout->setGeometry(QRect(360, 400, 75, 23));
        logout->setContextMenuPolicy(Qt::DefaultContextMenu);
        userarea->setCentralWidget(centralwidget);
        menubar = new QMenuBar(userarea);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 455, 21));
        userarea->setMenuBar(menubar);

        retranslateUi(userarea);

        usertabs->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(userarea);
    } // setupUi

    void retranslateUi(QMainWindow *userarea)
    {
        userarea->setWindowTitle(QApplication::translate("userarea", "User Area - LIMA V1.0", 0));
        actionLogout->setText(QApplication::translate("userarea", "Logout", 0));
        picture->setText(QString());
        changephoto->setText(QApplication::translate("userarea", "Change Photo", 0));
        editprofile->setText(QApplication::translate("userarea", "Edit Profile", 0));
        groupBox->setTitle(QApplication::translate("userarea", "User Information", 0));
        role_label->setText(QApplication::translate("userarea", "User Role:", 0));
        role->setText(QApplication::translate("userarea", "Normal User", 0));
        fine_label->setText(QApplication::translate("userarea", "Fine:", 0));
        fine->setText(QApplication::translate("userarea", "0 \340\270\277", 0));
        username_label->setText(QApplication::translate("userarea", "Username:", 0));
        username->setText(QApplication::translate("userarea", "TextLabel", 0));
        email->setText(QApplication::translate("userarea", "TextLabel", 0));
        id->setText(QApplication::translate("userarea", "TextLabel", 0));
        name->setText(QApplication::translate("userarea", "TextLabel", 0));
        fullname_label->setText(QApplication::translate("userarea", "Full Name:", 0));
        email_label->setText(QApplication::translate("userarea", "E-mail:", 0));
        id_label->setText(QApplication::translate("userarea", "ID Number:", 0));
        bookamt_label->setText(QApplication::translate("userarea", "Book Borrowed:", 0));
        bookamt->setText(QApplication::translate("userarea", "TextLabel", 0));
        booklim_label->setText(QApplication::translate("userarea", "Book Limit:", 0));
        booklim->setText(QApplication::translate("userarea", "TextLabel", 0));
        deleteme->setText(QApplication::translate("userarea", "Delete Account", 0));
        usertabs->setTabText(usertabs->indexOf(UserData), QApplication::translate("userarea", "User Data", 0));
        groupBox_3->setTitle(QApplication::translate("userarea", "Book Details", 0));
        bookname_label->setText(QApplication::translate("userarea", "Book Name:", 0));
        ISBN_label->setText(QApplication::translate("userarea", "Book ISBN:", 0));
        bookid_labe->setText(QApplication::translate("userarea", "Book ID:", 0));
        bookid->setText(QApplication::translate("userarea", "Please search for a book.", 0));
        author_label->setText(QApplication::translate("userarea", "Author:", 0));
        loan_label->setText(QApplication::translate("userarea", "Loan Period:", 0));
        loan_label_2->setText(QApplication::translate("userarea", "Days", 0));
        loaner_label->setText(QApplication::translate("userarea", "Current Loaner:", 0));
        loaner->setText(QString());
        price_label->setText(QApplication::translate("userarea", "Book Price:", 0));
        price_label_2->setText(QApplication::translate("userarea", "THB", 0));
        bookname->setText(QString());
        isbn->setText(QString());
        author->setText(QString());
        loan->setText(QString());
        price->setText(QString());
        label_2->setText(QApplication::translate("userarea", "Enter Book ID:", 0));
        search->setText(QApplication::translate("userarea", "Search", 0));
        picture_book->setText(QString());
        borrow->setText(QApplication::translate("userarea", "Borrow", 0));
        return_2->setText(QApplication::translate("userarea", "Return", 0));
        lost->setText(QApplication::translate("userarea", "Report Lost", 0));
        usertabs->setTabText(usertabs->indexOf(tab_2), QApplication::translate("userarea", "Borrow/Return Book", 0));
        welcome->setText(QApplication::translate("userarea", "Welcome, message", 0));
        logout->setText(QApplication::translate("userarea", "Log Out", 0));
    } // retranslateUi

};

namespace Ui {
    class userarea: public Ui_userarea {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERAREA_H

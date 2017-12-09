//--------------------------------------------------//
// Bhurinuth Wongsrisakul ID:58090030  (SY2015/2)   //
// 7th SE KMITL (Object Oriented Programing Project)//
// LIMA - LIbrary Management and Administration     //
// Filename: message.cpp   Type: Source File        //
//--------------------------------------------------//

#include <QMessageBox>
#include "message.h"

//This is for all the message popups and message for user response.//

message::message(){}
void message::invalidLogin()
{
    QMessageBox msg(QMessageBox::Critical,"Invalid Username or Password.", "Error - The username or password is incorrect.\nIf you forget your password, please contact the administrator.");
    msg.setStandardButtons(QMessageBox::Ok);
    msg.exec();
}
void message::duplicateUsername()
{
    QMessageBox msg(QMessageBox::Critical,"Username and Password Duplication Detected", "Error - The username and password was both duplicated by another user.\nPlease contact the administrator.");
    msg.setStandardButtons(QMessageBox::Ok);
    msg.exec();
}
void message::actionForbidden()
{
    QMessageBox msg(QMessageBox::Warning,"Operation Disabled by Administrator", "This action has been disabled by the administrator.\nPlease contact the administrator.");
    msg.setStandardButtons(QMessageBox::Ok);
    msg.exec();
}
void message::pictureDimension()
{
    QMessageBox msg(QMessageBox::Information,"Picture Information", "Picture Format: JPG\nMaximum Picture Dimensions:161x201 px");
    msg.setStandardButtons(QMessageBox::Ok);
    msg.exec();
}
void message::databasewriteOK()
{
    QMessageBox msg(QMessageBox::Information,"Query successful.", "The query was carried out successfully.");
    msg.setStandardButtons(QMessageBox::Ok);
    msg.exec();
}
void message::databasewriteFAIL()
{
    QMessageBox msg(QMessageBox::Critical,"Data was not saved successfully.", "The data was not saved in the database.\nPlease contact the administrator.");
    msg.setStandardButtons(QMessageBox::Ok);
    msg.exec();
}
void message::dangerousoperation()
{
    QMessageBox msg(QMessageBox::Warning,"Dangerous Operation", "This operation is a dangerous operation.\nPlease be warned that the following operation could render the software unstable.");
    msg.setStandardButtons(QMessageBox::Ok);
    msg.exec();
}
void message::onlyadminalert()
{
    QMessageBox msg(QMessageBox::Critical,"Forbidden - Dangerous Operation", "You are the only admin of this software. \nThe following operation could render the software unstable.");
    msg.setStandardButtons(QMessageBox::Ok);
    msg.exec();
}
void message::programscram()
{
    QMessageBox msg(QMessageBox::Critical,"Program Breakpoint Triggered", "The program has triggered a breakpoint.\nThe program will now close.\nPlease restart the program to continue operation.");
    msg.setStandardButtons(QMessageBox::Ok);
    msg.exec();
}
void message::passwordmismatch()
{
    QMessageBox msg(QMessageBox::Critical,"Password Mismatch", "Error - The password are not identical.\nPlease Try Again.");
    msg.setStandardButtons(QMessageBox::Ok);
    msg.exec();
}
void message::empty()
{
    QMessageBox msg(QMessageBox::Warning,"Field Empty", "Error - Please fill all fields and Try Again.");
    msg.setStandardButtons(QMessageBox::Ok);
    msg.exec();
}
void message::querynotfound()
{
    QMessageBox msg(QMessageBox::Warning,"Error", "The Query you submitted do not exist. Please try again");
    msg.setStandardButtons(QMessageBox::Ok);
    msg.exec();
}
void message::duplicateusrregis()
{
    QMessageBox msg(QMessageBox::Warning,"Username Exists", "Error - The Username already exists. Please Try Again.");
    msg.setStandardButtons(QMessageBox::Ok);
    msg.exec();
}
void message::duplicateusrID()
{
    QMessageBox msg(QMessageBox::Warning,"User ID Exists", "Error - The User ID already exists. Please Try Again.");
    msg.setStandardButtons(QMessageBox::Ok);
    msg.exec();
}
void message::duplicatebookID()
{
    QMessageBox msg(QMessageBox::Warning,"Book ID Exists", "Error - The Book ID already exists. Please Try Again.");
    msg.setStandardButtons(QMessageBox::Ok);
    msg.exec();
}
bool message::informationconfirm()
{
    QMessageBox msg(QMessageBox::Question,"Are you sure?" , "Are you sure to edit the information?\nPlease confirm the information you provided.");
    msg.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    if(msg.exec()==QMessageBox::Yes)
        return true;
    return false;
}
bool message::logoutExit()
{
    QMessageBox msg(QMessageBox::Question,"Are you sure?", "Are you sure to Logout and Exit?");
    msg.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    if(msg.exec()==QMessageBox::Yes)
        return true;
    return false;
}
bool message::areyousure()
{
    QMessageBox msg(QMessageBox::Question,"Are you sure?", "Are you sure continue with the operation?");
    msg.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    if(msg.exec()==QMessageBox::Yes)
        return true;
    return false;
}
bool message::cancel()
{
    QMessageBox msg(QMessageBox::Question,"Are you sure?", "Your previous information will not be saved.\nAre you sure to cancel the operation?");
    msg.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    if(msg.exec()==QMessageBox::Yes)
        return true;
    return false;
}

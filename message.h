//--------------------------------------------------//
// Bhurinuth Wongsrisakul ID:58090030  (SY2015/2)   //
// 7th SE KMITL (Object Oriented Programing Project)//
// LIMA - LIbrary Management and Administration     //
// Filename: message.h   Type: Header File          //
//--------------------------------------------------//

//--------------------------------------------------//
// This class serves to function the windows popup  //
// of the program It handles all the windows pop    //
// and user responses.                              //
//--------------------------------------------------//


#ifndef MESSAGE_H
#define MESSAGE_H

#include <QWidget>

class message
{
public: //This part holds most of the redundant message popup of the programs.
    message();
    void invalidLogin();
    void duplicateUsername();
    void duplicateusrregis();
    void duplicateusrID();
    void duplicatebookID();
    void querynotfound();
    void actionForbidden();
    void pictureDimension();
    void databasewriteOK();
    void databasewriteFAIL();
    void dangerousoperation();
    void programscram();
    void passwordmismatch();
    void onlyadminalert();
    void empty();
    bool cancel();
    bool informationconfirm();
    bool areyousure();
    bool logoutExit();
private:
    bool YES = true;
    bool NO = false;
};

#endif // MESSAGE_H

#ifndef LOGINHANDLER_H
#define LOGINHANDLER_H
#include "datamanager.h"

class LoginHandler {
public:
    LoginHandler(DataManager* mgr);
    User* tryLogin(QString username);
private:
    DataManager* mgr;
};
#endif

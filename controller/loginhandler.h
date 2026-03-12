#ifndef LOGINHANDLER_H
#define LOGINHANDLER_H
#include "datamanager.h"

class LoginHandler {
public:
    LoginHandler(DataManager* dm);
    User* tryLogin(QString username);
private:
    DataManager* dm;
};
#endif

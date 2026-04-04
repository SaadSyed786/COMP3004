#include "loginhandler.h"

LoginHandler::LoginHandler(DataManager* mgr) : mgr(mgr) {}

User* LoginHandler::tryLogin(QString username)
{
    return mgr->findUser(username.trimmed());
}

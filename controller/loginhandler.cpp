#include "loginhandler.h"

LoginHandler::LoginHandler(DataManager* dm) : dm(dm) {}
User* LoginHandler::tryLogin(QString username) {
    return dm->lookupUser(username.trimmed());
}

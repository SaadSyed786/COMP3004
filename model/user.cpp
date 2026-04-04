#include "user.h"

User::User(QString uname, QString name, Role r)
    : username(uname), fullName(name), role(r) {}

User::~User() {}

QString User::getUsername()   { return username; }
QString User::getFullName()   { return fullName; }
User::Role User::getRole()   { return role; }

QString User::getRoleString()
{
    switch (role) {
        case VendorRole:   return "Vendor";
        case OperatorRole: return "Market Operator";
        case AdminRole:    return "System Administrator";
    }
    return "Unknown";
}

#include "user.h"

User::User(QString uname, QString fullName, Role r)
    : username(uname), fullName(fullName), role(r) {}

User::~User() {}

QString User::getUsername() { return username; }
QString User::getFullName() { return fullName; }
User::Role User::getRole() { return role; }
QString User::getRoleString() {
    if (role == VendorRole) return "Vendor";
    else if (role == OperatorRole) return "Market Operator";
    else return "System Administrator";
}

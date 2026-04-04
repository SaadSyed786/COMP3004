#ifndef USER_H
#define USER_H

#include <QString>

class User
{
public:
    enum Role { VendorRole, OperatorRole, AdminRole };

    User(QString uname, QString name, Role r);
    virtual ~User();

    QString getUsername();
    QString getFullName();
    Role    getRole();
    QString getRoleString();

protected:
    QString username;
    QString fullName;
    Role    role;
};

#endif

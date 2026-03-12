#ifndef SYSADMIN_H
#define SYSADMIN_H
#include "user.h"

class SysAdmin : public User {
public:
    SysAdmin(QString uname, QString name);
    ~SysAdmin();
};
#endif

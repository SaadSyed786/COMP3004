#include "sysadmin.h"
SysAdmin::SysAdmin(QString uname, QString name)
    : User(uname, name, AdminRole) {}
SysAdmin::~SysAdmin() {}

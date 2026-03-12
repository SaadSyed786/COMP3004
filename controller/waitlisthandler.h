#ifndef WAITLISTHANDLER_H
#define WAITLISTHANDLER_H
#include "datamanager.h"

class WaitlistHandler {
public:
    WaitlistHandler(DataManager* dm);
    QString joinWaitlist(QString vendorUser, QDate date);
    QString leaveWaitlist(QString vendorUser, QDate date);
private:
    DataManager* dm;
};
#endif

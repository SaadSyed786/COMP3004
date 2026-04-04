#ifndef WAITLISTHANDLER_H
#define WAITLISTHANDLER_H
#include "datamanager.h"

class WaitlistHandler {
public:
    WaitlistHandler(DataManager* mgr);
    QString joinWaitlist(QString vendorUsername, QDate date);
    QString leaveWaitlist(QString vendorUsername, QDate date);
private:
    DataManager* mgr;
};
#endif

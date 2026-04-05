#ifndef DASHBOARDHANDLER_H
#define DASHBOARDHANDLER_H
#include "datamanager.h"

class DashboardHandler {
public:
    DashboardHandler(DataManager* mgr);
    Vendor* getVendorInfo(QString username);
    QVector<StallBooking> getBookings(QString username);
    QVector<Waitlist*>   getWaitlists(QString username);
    QVector<Notification> getNotifications(QString username);
private:
    DataManager* mgr;
};
#endif

#ifndef DASHBOARDHANDLER_H
#define DASHBOARDHANDLER_H
#include "datamanager.h"

class DashboardHandler {
public:
    DashboardHandler(DataManager* dm);
    Vendor* getVendorInfo(QString user);
    QVector<StallBooking> getBookings(QString user);
    QVector<Waitlist*> getWaitlists(QString user);
    QVector<Notification> getNotifs(QString user);
private:
    DataManager* dm;
};
#endif

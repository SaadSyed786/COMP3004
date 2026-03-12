#include "dashboardhandler.h"

DashboardHandler::DashboardHandler(DataManager* dm) : dm(dm) {}

Vendor* DashboardHandler::getVendorInfo(QString user) { return dm->lookupVendor(user); }
QVector<StallBooking> DashboardHandler::getBookings(QString user) { return dm->vendorBookings(user); }
QVector<Waitlist*> DashboardHandler::getWaitlists(QString user) { return dm->vendorWaitlists(user); }
QVector<Notification> DashboardHandler::getNotifs(QString user) { return dm->getNotifications(user); }

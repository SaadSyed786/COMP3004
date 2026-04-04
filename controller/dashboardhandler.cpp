#include "dashboardhandler.h"

DashboardHandler::DashboardHandler(DataManager* mgr) : mgr(mgr) {}

Vendor* DashboardHandler::getVendorInfo(QString username)
{
    return mgr->findVendor(username);
}

QVector<StallBooking> DashboardHandler::getBookings(QString username)
{
    return mgr->getVendorBookings(username);
}

QVector<Waitlist*> DashboardHandler::getWaitlists(QString username)
{
    return mgr->getVendorWaitlists(username);
}

QVector<Notification> DashboardHandler::getNotifications(QString username)
{
    return mgr->getNotifications(username);
}

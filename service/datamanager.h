#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include "user.h"
#include "vendor.h"
#include "foodvendor.h"
#include "artisanvendor.h"
#include "marketoperator.h"
#include "sysadmin.h"
#include "marketschedule.h"
#include "stallbooking.h"
#include "waitlist.h"
#include "notification.h"
#include <QVector>
#include <QMap>

// holds all in-memory data
class DataManager {
public:
    DataManager();
    ~DataManager();
    User* lookupUser(QString username);
    Vendor* lookupVendor(QString username);
    MarketSchedule* getSchedule();
    void addBooking(StallBooking b);
    void removeBooking(QString vendorUser, QDate date);
    bool hasBooking(QString vendorUser, QDate date);
    bool hasAnyBooking(QString vendorUser);
    QVector<StallBooking> vendorBookings(QString vendorUser);
    Waitlist* getWaitlist(QString category, QDate date);
    QVector<Waitlist*> vendorWaitlists(QString vendorUser);
    void notify(QString vendorUser, Notification n);
    QVector<Notification> getNotifications(QString vendorUser);
    
private:
    void loadUsers();
    void loadMarketDates();

    QVector<User*> users;
    MarketSchedule schedule;
    QVector<StallBooking> bookings;
    QVector<Waitlist*> waitlists;
    QMap<QString, QVector<Notification>> notifications;
};

#endif

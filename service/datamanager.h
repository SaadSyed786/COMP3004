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
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QCoreApplication>
#include <QDebug>

class DataManager
{
public:
    DataManager();
    ~DataManager();

    // lookups
    User*   findUser(QString username);
    Vendor* findVendor(QString username);
    QVector<Vendor*> getAllVendors();
    MarketSchedule* getSchedule();

    // booking operations (update memory + db)
    void addBooking(StallBooking booking);
    void removeBooking(QString vendorUsername, QDate date);
    bool hasBooking(QString vendorUsername, QDate date);
    bool hasAnyBooking(QString vendorUsername);
    QVector<StallBooking> getVendorBookings(QString vendorUsername);

    // waitlist operations
    Waitlist* getWaitlist(QString category, QDate date);
    QVector<Waitlist*> getVendorWaitlists(QString vendorUsername);

    // notifications
    void sendNotification(QString vendorUsername, Notification n);
    QVector<Notification> getNotifications(QString vendorUsername);

    // db sync helpers (called by controllers after waitlist/date changes)
    void persistWaitlist(Waitlist* wl);
    void persistMarketDate(MarketDate* md);

private:
    bool connectToDatabase();
    void loadAllUsers();
    void loadMarketSchedule();
    void loadBookings();
    void loadWaitlists();
    void loadNotifications();
    void writeBookingToDb(StallBooking& b);
    void deleteBookingFromDb(QString vendorUsername, QDate date);
    void writeNotificationToDb(QString vendorUsername, Notification& n);

    QSqlDatabase database;
    QVector<User*> userList;
    MarketSchedule schedule;
    QVector<StallBooking> bookingList;
    QVector<Waitlist*> waitlistList;
    QMap<QString, QVector<Notification>> notificationMap;
};

#endif

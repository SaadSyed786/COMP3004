#include "stallbooking.h"

StallBooking::StallBooking(QString vendorUser, QDate mktDate, QString category)
    : vendorUser(vendorUser), mktDate(mktDate), category(category),
      timestamp(QDateTime::currentDateTime()) {}

QString StallBooking::getVendorUser() { return vendorUser; }
QDate StallBooking::getMarketDate() { return mktDate; }
QString StallBooking::getMarketDateStr() { return mktDate.toString("yyyy-MM-dd"); }
QString StallBooking::getCategory() { return category; }
QDateTime StallBooking::getTimestamp() { return timestamp; }

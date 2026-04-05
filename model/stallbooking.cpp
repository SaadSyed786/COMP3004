#include "stallbooking.h"

StallBooking::StallBooking(QString vendorUsername, QDate marketDate, QString vendorCategory)
    : vendorUsername(vendorUsername), marketDate(marketDate),
      vendorCategory(vendorCategory), createdAt(QDateTime::currentDateTime()) {}

QString StallBooking::getVendorUser() { return vendorUsername; }
QDate StallBooking::getMarketDate() { return marketDate; }
QString StallBooking::getMarketDateStr() { return marketDate.toString("yyyy-MM-dd"); }
QString StallBooking::getCategory() { return vendorCategory; }
QDateTime StallBooking::getTimestamp() { return createdAt; }

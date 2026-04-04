#ifndef STALLBOOKING_H
#define STALLBOOKING_H

#include <QString>
#include <QDate>
#include <QDateTime>

class StallBooking
{
public:
    StallBooking(QString vendorUsername, QDate marketDate, QString vendorCategory);

    QString   getVendorUser();
    QDate     getMarketDate();
    QString   getMarketDateStr();
    QString   getCategory();
    QDateTime getTimestamp();

private:
    QString   vendorUsername;
    QDate     marketDate;
    QString   vendorCategory;
    QDateTime createdAt;
};

#endif

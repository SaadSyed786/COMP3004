#ifndef STALLBOOKING_H
#define STALLBOOKING_H
#include <QString>
#include <QDate>
#include <QDateTime>

class StallBooking {
public:
    StallBooking(QString vendorUser, QDate mktDate, QString category);
    QString getVendorUser();
    QDate getMarketDate();
    QString getMarketDateStr();
    QString getCategory();
    QDateTime getTimestamp();

private:
    QString vendorUser;
    QDate mktDate;
    QString category;
    QDateTime timestamp;
};

#endif

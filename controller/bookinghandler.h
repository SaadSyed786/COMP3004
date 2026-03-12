#ifndef BOOKINGHANDLER_H
#define BOOKINGHANDLER_H
#include "datamanager.h"

class BookingHandler {
public:
    BookingHandler(DataManager* dm);
    QString bookStall(QString vendorUser, QDate date);
    QString cancelStall(QString vendorUser, QDate date);

private:
    DataManager* dm;
};
#endif

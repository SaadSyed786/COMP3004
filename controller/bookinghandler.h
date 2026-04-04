#ifndef BOOKINGHANDLER_H
#define BOOKINGHANDLER_H
#include "datamanager.h"

class BookingHandler {
public:
    BookingHandler(DataManager* mgr);

    // returns empty string on success, error msg on failure, "FULL" if no stalls
    QString bookStall(QString vendorUsername, QDate date);
    QString cancelStall(QString vendorUsername, QDate date);

private:
    DataManager* mgr;
};
#endif

#ifndef SCHEDULEHANDLER_H
#define SCHEDULEHANDLER_H
#include "datamanager.h"

class ScheduleHandler {
public:
    ScheduleHandler(DataManager* dm);
    QVector<MarketDate*> getAvailableDates();
private:
    DataManager* dm;
};
#endif

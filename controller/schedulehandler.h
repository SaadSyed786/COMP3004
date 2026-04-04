#ifndef SCHEDULEHANDLER_H
#define SCHEDULEHANDLER_H
#include "datamanager.h"

class ScheduleHandler {
public:
    ScheduleHandler(DataManager* mgr);
    QVector<MarketDate*> getAvailableDates();
private:
    DataManager* mgr;
};
#endif

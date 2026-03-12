#include "schedulehandler.h"

ScheduleHandler::ScheduleHandler(DataManager* dm) : dm(dm) {}
QVector<MarketDate*> ScheduleHandler::getAvailableDates() {
    return dm->getSchedule()->getDates();
}

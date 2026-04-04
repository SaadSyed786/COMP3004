#include "schedulehandler.h"

ScheduleHandler::ScheduleHandler(DataManager* mgr) : mgr(mgr) {}

QVector<MarketDate*> ScheduleHandler::getAvailableDates()
{
    return mgr->getSchedule()->getDates();
}

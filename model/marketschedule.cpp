#include "marketschedule.h"

MarketSchedule::MarketSchedule() {}

void MarketSchedule::addDate(MarketDate* md) { allDates.append(md); }

QVector<MarketDate*> MarketSchedule::getDates() { return allDates; }

int MarketSchedule::count() { return allDates.size(); }

MarketDate* MarketSchedule::findByDate(QDate d){
    for (int i = 0; i < allDates.size(); i++) {
        if (allDates[i]->getDate() == d){
            return allDates[i];
        }
    }
    return nullptr;
}

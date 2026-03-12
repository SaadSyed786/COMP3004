#include "marketschedule.h"

MarketSchedule::MarketSchedule() {}
void MarketSchedule::addDate(MarketDate* md) { dates.push_back(md); }
QVector<MarketDate*> MarketSchedule::getDates() { return dates; }
int MarketSchedule::count() { return dates.size(); }
MarketDate* MarketSchedule::findByDate(QDate d) {
    for (int i = 0; i < dates.size(); i++) {
        if (dates[i]->getDate() == d) return dates[i];
    }
    return nullptr;
}

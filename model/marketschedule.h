#ifndef MARKETSCHEDULE_H
#define MARKETSCHEDULE_H
#include "marketdate.h"
#include <QVector>

class MarketSchedule {
public:
    MarketSchedule();
    void addDate(MarketDate* md);
    QVector<MarketDate*> getDates();
    MarketDate* findByDate(QDate d);
    int count();

private:
    QVector<MarketDate*> dates;
};

#endif

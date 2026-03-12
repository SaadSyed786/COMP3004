#ifndef MARKETDATE_H
#define MARKETDATE_H

#include <QDate>
#include <QString>

// tracks stall availability 
class MarketDate {
public:
    MarketDate(QDate date, int maxFood, int maxArtisan);

    QDate getDate();
    QString getDateStr();  
    int maxFoodStalls();
    int maxArtisanStalls();
    int availableFood();
    int availableArtisan();
    int bookedFood();
    int bookedArtisan();
    bool foodFull();
    bool artisanFull();

    bool bookFood();
    bool bookArtisan();
    void releaseFood();
    void releaseArtisan();

private:
    QDate date;
    int maxFood;
    int maxArtisan;
    int numFoodBooked;
    int numArtisanBooked;
};

#endif

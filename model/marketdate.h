#ifndef MARKETDATE_H
#define MARKETDATE_H

#include <QDate>
#include <QString>

// represents a single market sunday and tracks how many stalls are booked
class MarketDate
{
public:
    MarketDate(QDate date, int maxFoodStalls, int maxArtisanStalls);

    QDate   getDate();
    QString getDateStr();

    int  maxFoodStalls();
    int  maxArtisanStalls();
    int  availableFood();
    int  availableArtisan();
    int  bookedFood();
    int  bookedArtisan();
    bool foodFull();
    bool artisanFull();

    bool bookFood();        // returns false if full
    bool bookArtisan();
    void releaseFood();
    void releaseArtisan();

private:
    QDate date;
    int   foodMax;
    int   artisanMax;
    int   foodBooked;
    int   artisanBooked;
};

#endif

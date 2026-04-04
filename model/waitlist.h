#ifndef WAITLIST_H
#define WAITLIST_H

#include <QString>
#include <QDate>
#include <QList>

// FIFO queue for vendors waiting for a stall on a given market date
class Waitlist
{
public:
    Waitlist(QString vendorCategory, QDate marketDate);

    QString getCategory();
    QDate   getMarketDate();
    QString getMarketDateStr();

    void    enqueue(QString vendorUsername);
    bool    remove(QString vendorUsername);
    QString peekNext();
    QString dequeueNext();
    int     positionOf(QString vendorUsername);
    bool    contains(QString vendorUsername);
    int     size();

private:
    QString vendorCategory;
    QDate   marketDate;
    QList<QString> queue;
};

#endif

#ifndef WAITLIST_H
#define WAITLIST_H

#include <QString>
#include <QDate>
#include <QList>

// FIFO waitlist queue
class Waitlist {
public:
    Waitlist(QString category, QDate mktDate);

    QString getCategory();
    QDate getMarketDate();
    QString getMarketDateStr();
    void enqueue(QString vendorUser);
    bool remove(QString vendorUser);
    QString peekNext();
    QString dequeueNext();
    int positionOf(QString vendorUser);
    bool contains(QString vendorUser);
    int size();

private:
    QString category;
    QDate mktDate;
    QList<QString> queue;
};

#endif

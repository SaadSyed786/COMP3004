#include "waitlist.h"

Waitlist::Waitlist(QString vendorCategory, QDate marketDate)
    : vendorCategory(vendorCategory), marketDate(marketDate) {}
QString Waitlist::getCategory() { return vendorCategory; }
QDate   Waitlist::getMarketDate() { return marketDate; }
QString Waitlist::getMarketDateStr() { return marketDate.toString("yyyy-MM-dd"); }
void Waitlist::enqueue(QString vendorUsername){
    if (!queue.contains(vendorUsername))queue.append(vendorUsername);
}
bool Waitlist::remove(QString vendorUsername){return queue.removeOne(vendorUsername);}
QString Waitlist::peekNext(){
    if (queue.isEmpty()) {return "";}
    return queue.first();
}

QString Waitlist::dequeueNext(){
    if (queue.isEmpty()) {return "";}
    return queue.takeFirst();
}

int Waitlist::positionOf(QString vendorUsername){
    int idx = queue.indexOf(vendorUsername);
    return (idx < 0) ? -1 : idx + 1;
}
bool Waitlist::contains(QString vendorUsername){ return queue.contains(vendorUsername); }
int  Waitlist::size(){ return queue.size(); }
QList<QString> Waitlist::getQueue(){ return queue; }
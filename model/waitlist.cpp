#include "waitlist.h"

Waitlist::Waitlist(QString category, QDate mktDate)
    : category(category), mktDate(mktDate) {}

QString Waitlist::getCategory() { return category; }
QDate Waitlist::getMarketDate() { return mktDate; }
QString Waitlist::getMarketDateStr() { return mktDate.toString("yyyy-MM-dd"); }

void Waitlist::enqueue(QString vendorUser) {
    if (!queue.contains(vendorUser))
        queue.append(vendorUser);
}
bool Waitlist::remove(QString vendorUser) { return queue.removeOne(vendorUser);}

QString Waitlist::peekNext() {
    if (queue.isEmpty()) return "";
    return queue.first();
}

QString Waitlist::dequeueNext() {
    if (queue.isEmpty()) return "";
    return queue.takeFirst();
}

int Waitlist::positionOf(QString vendorUser) {
    int idx = queue.indexOf(vendorUser);
    if (idx < 0) return -1;
    return idx + 1;  
}

bool Waitlist::contains(QString vendorUser) { return queue.contains(vendorUser); }
int Waitlist::size() { return queue.size(); }

#include "waitlisthandler.h"

WaitlistHandler::WaitlistHandler(DataManager* dm) : dm(dm) {}

QString WaitlistHandler::joinWaitlist(QString vendorUser, QDate date) {
    Vendor* v = dm->lookupVendor(vendorUser);
    if (v == nullptr) return "Vendor not found.";

    QString cat = v->getCategoryStr();
    Waitlist* wl = dm->getWaitlist(cat, date);

    if (wl->contains(vendorUser))
        return "Already on the waitlist for this date.";
    wl->enqueue(vendorUser);
    int pos = wl->positionOf(vendorUser);

    dm->notify(vendorUser, Notification(
        "Joined " + cat + " waitlist for " + date.toString("yyyy-MM-dd") +
        " (position " + QString::number(pos) + ")", Notification::Info));

    return "";
}

QString WaitlistHandler::leaveWaitlist(QString vendorUser, QDate date) {
    Vendor* v = dm->lookupVendor(vendorUser);
    if (v == nullptr) return "Vendor not found.";
    QString cat = v->getCategoryStr();
    Waitlist* wl = dm->getWaitlist(cat, date);
    if (!wl->contains(vendorUser))
        return "You are not on the waitlist for this date.";
    wl->remove(vendorUser);
    return "";
}

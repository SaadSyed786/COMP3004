#include "waitlisthandler.h"

WaitlistHandler::WaitlistHandler(DataManager* mgr) : mgr(mgr) {}

QString WaitlistHandler::joinWaitlist(QString vendorUsername, QDate date){
    Vendor* vendor = mgr->findVendor(vendorUsername);
    if (!vendor) {return "Vendor not found.";}

    QString cat = vendor->getCategoryStr();
    Waitlist* wl = mgr->getWaitlist(cat, date);

    if (wl->contains(vendorUsername)){return "Already on the waitlist for this date.";}

    wl->enqueue(vendorUsername);
    int pos = wl->positionOf(vendorUsername);

    mgr->sendNotification(vendorUsername,
        Notification("Joined " + cat + " waitlist for " + date.toString("yyyy-MM-dd")
                     + " (position " + QString::number(pos) + ")", Notification::Info));

    mgr->persistWaitlist(wl);
    return "";
}

QString WaitlistHandler::leaveWaitlist(QString vendorUsername, QDate date){
    Vendor* vendor = mgr->findVendor(vendorUsername);
    if (!vendor) {return "Vendor not found.";}

    QString cat = vendor->getCategoryStr();
    Waitlist* wl = mgr->getWaitlist(cat, date);

    if (!wl->contains(vendorUsername)){
        return "You are not on the waitlist for this date.";
    }
    wl->remove(vendorUsername);
    mgr->persistWaitlist(wl);
    return "";
}

#include "bookinghandler.h"

BookingHandler::BookingHandler(DataManager* mgr) : mgr(mgr) {}

QString BookingHandler::bookStall(QString vendorUsername, QDate date)
{
    Vendor* vendor = mgr->findVendor(vendorUsername);
    if (!vendor) return "Vendor not found.";

    if (!vendor->isCompliant())
        return "Compliance documents are incomplete or expired. Cannot book.";

    if (mgr->hasAnyBooking(vendorUsername))
        return "You already have an active booking. Only one stall booking allowed at a time.";

    MarketDate* mktDate = mgr->getSchedule()->findByDate(date);
    if (!mktDate) return "Market date not found.";

    bool booked = false;
    if (vendor->getCategory() == Vendor::Food)
        booked = mktDate->bookFood();
    else
        booked = mktDate->bookArtisan();

    if (!booked) return "FULL";

    mgr->addBooking(StallBooking(vendorUsername, date, vendor->getCategoryStr()));
    mgr->sendNotification(vendorUsername,
        Notification("Booking confirmed for " + date.toString("yyyy-MM-dd"),
                     Notification::BookingConfirmed));
    return "";
}

QString BookingHandler::cancelStall(QString vendorUsername, QDate date)
{
    Vendor* vendor = mgr->findVendor(vendorUsername);
    if (!vendor) return "Vendor not found.";

    if (!mgr->hasBooking(vendorUsername, date))
        return "No booking found for this date.";

    // free the stall
    MarketDate* mktDate = mgr->getSchedule()->findByDate(date);
    if (mktDate) {
        if (vendor->getCategory() == Vendor::Food) mktDate->releaseFood();
        else                                       mktDate->releaseArtisan();
    }

    mgr->removeBooking(vendorUsername, date);
    mgr->sendNotification(vendorUsername,
        Notification("Booking cancelled for " + date.toString("yyyy-MM-dd"),
                     Notification::BookingCancelled));

    // try to auto-book the next person on the waitlist
    if (mktDate) {
        QString cat = vendor->getCategoryStr();
        Waitlist* wl = mgr->getWaitlist(cat, date);

        while (wl->size() > 0) {
            QString nextVendor = wl->dequeueNext();
            Vendor* nv = mgr->findVendor(nextVendor);

            // skip if vendor doesnt exist or already has a booking
            if (!nv || mgr->hasAnyBooking(nextVendor)) {
                mgr->sendNotification(nextVendor,
                    Notification("A " + cat + " stall opened for " + date.toString("yyyy-MM-dd")
                                 + " but you already have a booking.", Notification::Info));
                continue;
            }

            bool ok = false;
            if (nv->getCategory() == Vendor::Food) ok = mktDate->bookFood();
            else                                   ok = mktDate->bookArtisan();

            if (ok) {
                mgr->addBooking(StallBooking(nextVendor, date, cat));
                mgr->sendNotification(nextVendor,
                    Notification("A " + cat + " stall for " + date.toString("yyyy-MM-dd")
                                 + " was auto-booked for you from the waitlist!",
                                 Notification::BookingConfirmed));
            }
            break;
        }

        mgr->persistWaitlist(wl);
        mgr->persistMarketDate(mktDate);
    }

    return "";
}

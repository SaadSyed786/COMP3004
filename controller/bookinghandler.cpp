#include "bookinghandler.h"

BookingHandler::BookingHandler(DataManager* dm) : dm(dm) {}

QString BookingHandler::bookStall(QString vendorUser, QDate date) {
    Vendor* v = dm->lookupVendor(vendorUser);
    if (v == nullptr) return "Vendor not found.";

    if (!v->isCompliant())
        return "Your compliance documents are incomplete or expired. Cannot book.";

    if (dm->hasAnyBooking(vendorUser))
        return "You already have an active booking.  one stall booking allowed at a time.";

    if (dm->hasBooking(vendorUser, date))
        return "You already booked this date.";

    MarketDate* md = dm->getSchedule()->findByDate(date);
    if (md == nullptr) return "Market date not found.";

    bool ok = false;
    if (v->getCategory() == Vendor::Food)
        ok = md->bookFood();
    else
        ok = md->bookArtisan();

    if (!ok) return "FULL";

    dm->addBooking(StallBooking(vendorUser, date, v->getCategoryStr()));
    dm->notify(vendorUser, Notification(
        "Booking confirmed for " + date.toString("yyyy-MM-dd"), Notification::BookingConfirmed));

    return "";
}

QString BookingHandler::cancelStall(QString vendorUser, QDate date) {
    Vendor* v = dm->lookupVendor(vendorUser);
    if (v == nullptr) return "Vendor not found.";

    if (!dm->hasBooking(vendorUser, date))
        return "No booking found for this date.";

    // release the stall back
    MarketDate* md = dm->getSchedule()->findByDate(date);
    if (md != nullptr) {
        if (v->getCategory() == Vendor::Food) md->releaseFood();
        else md->releaseArtisan();
    }

    dm->removeBooking(vendorUser, date);
    dm->notify(vendorUser, Notification(
        "Booking cancelled for " + date.toString("yyyy-MM-dd"), Notification::BookingCancelled));

    if (md != nullptr) {
        QString cat = v->getCategoryStr();
        Waitlist* wl = dm->getWaitlist(cat, date);

        while (wl->size() > 0) {
            QString nextUser = wl->dequeueNext();
            Vendor* nextV = dm->lookupVendor(nextUser);
            if (nextV == nullptr || dm->hasAnyBooking(nextUser)) {
                dm->notify(nextUser, Notification(
                    "A " + cat + " stall opened up for " + date.toString("yyyy-MM-dd") +
                    " but you already have an active booking.", Notification::Info));
                continue;
            }

            // book the stall automatically for waitlist #1
            bool booked = false;
            if (nextV->getCategory() == Vendor::Food)
                booked = md->bookFood();
            else
                booked = md->bookArtisan();

            if (booked) {
                dm->addBooking(StallBooking(nextUser, date, cat));
                dm->notify(nextUser, Notification(
                    "A " + cat + " stall for " + date.toString("yyyy-MM-dd") +
                    " has been automatically booked for you from the waitlist!",
                    Notification::BookingConfirmed));
            }
            break;  
        }
    }

    return "";
}

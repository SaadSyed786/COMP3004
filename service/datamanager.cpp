#include "datamanager.h"

DataManager::DataManager() {
    loadUsers();
    loadMarketDates();
}

DataManager::~DataManager() {
    // cleaning up the heap-allocated objects 
    for (int i = 0; i < users.size(); i++) delete users[i];

    QVector<MarketDate*> dates = schedule.getDates();
    for (int i = 0; i < dates.size(); i++) {
    delete dates[i];
    }
    for (int i = 0; i < waitlists.size(); i++) delete waitlists[i];
}

void DataManager::loadUsers() {
    FoodVendor* f1 = new FoodVendor("haashir", "Haashir Tanveer", "Haashir's Bakery",
        "haashir@bakery.ca", "613-010-1101", "88 Bank St, Ottawa ON K1P 5N2");
    f1->addDocument(ComplianceDoc("Business Licence", "BL-2026-4401", QDate(2026, 12, 31)));
    f1->addDocument(ComplianceDoc("Liability Insurance", "LI-8801", QDate(2026, 12, 31), "Intact Insurance"));
    f1->addDocument(ComplianceDoc("Food Handler Certification", "FHC-2201", QDate(2026, 12, 31)));

    FoodVendor* f2 = new FoodVendor("ali", "Ali Sohail", "Ali's royal sweets",
        "ali@royalsweets.ca", "613-010-1102", "42 Rideau St, Ottawa ON K1N 5X6");
    f2->addDocument(ComplianceDoc("Business Licence", "BL-2026-4402", QDate(2026, 12, 31)));
    f2->addDocument(ComplianceDoc("Liability Insurance", "LI-8802", QDate(2026, 12, 31), "Aviva Canada"));
    f2->addDocument(ComplianceDoc("Food Handler Certification", "FHC-2202", QDate(2026, 12, 31)));

    FoodVendor* f3 = new FoodVendor("saad", "Saad Syed", "Saad's Spice Pizza",
        "saad@spice.ca", "613-010-1103", "120 Murray St, Ottawa ON K1N 5M6");
    f3->addDocument(ComplianceDoc("Business Licence", "BL-2026-4403", QDate(2026, 12, 31)));
    f3->addDocument(ComplianceDoc("Liability Insurance", "LI-8803", QDate(2026, 12, 31), "Desjardins"));
    f3->addDocument(ComplianceDoc("Food Handler Certification", "FHC-2203", QDate(2026, 12, 31)));

    FoodVendor* f4 = new FoodVendor("max", "Max Holloway", "Max's Fruit Preserves Co.",
        "max@fruitpreserves.ca", "613-010-1104", "55 Elgin St, Ottawa ON K2P 1L5");
    f4->addDocument(ComplianceDoc("Business Licence", "BL-2026-4404", QDate(2026, 12, 31)));
    f4->addDocument(ComplianceDoc("Liability Insurance", "LI-8804", QDate(2026, 12, 31), "TD Insurance"));
    f4->addDocument(ComplianceDoc("Food Handler Certification", "FHC-2204", QDate(2026, 12, 31)));


    ArtisanVendor* a1 = new ArtisanVendor("jon", "Jon Jones", "Jon's Divine Pottery",
        "jon@divinepottery.ca", "613-010-2201", "15 Sparks St, Ottawa ON K1P 5A5");
    a1->addDocument(ComplianceDoc("Business Licence", "BL-2026-5501", QDate(2026, 12, 31)));
    a1->addDocument(ComplianceDoc("Liability Insurance", "LI-9901", QDate(2026, 12, 31), "Co-operators"));

    ArtisanVendor* a2 = new ArtisanVendor("shamil", "Shamil Gaziev", "Shamil's Wood Work",
        "shamil@woodwork.ca", "613-010-2202", "33 Clarence St, Ottawa ON K1N 9K1");
    a2->addDocument(ComplianceDoc("Business Licence", "BL-2026-5502", QDate(2026, 12, 31)));
    a2->addDocument(ComplianceDoc("Liability Insurance", "LI-9902", QDate(2026, 12, 31), "Wawanesa"));

    ArtisanVendor* a3 = new ArtisanVendor("merab", "Merab Dvalishvili", "Merab's Jewels",
        "merab@jewels.ca", "613-010-2203", "78 George St, Ottawa ON K1N 5W1");
    a3->addDocument(ComplianceDoc("Business Licence", "BL-2026-5503", QDate(2026, 12, 31)));
    a3->addDocument(ComplianceDoc("Liability Insurance", "LI-9903", QDate(2026, 12, 31), "Economical"));

    ArtisanVendor* a4 = new ArtisanVendor("ilia", "Ilia Topuria", "Ilia's Candle art",
        "ilia@candles.ca", "613-010-2204", "22 York St, Ottawa ON K1N 5S7");
    a4->addDocument(ComplianceDoc("Business Licence", "BL-2026-5504", QDate(2026, 12, 31)));
    a4->addDocument(ComplianceDoc("Liability Insurance", "LI-9904", QDate(2026, 12, 31), "RSA Canada"));

    MarketOperator* op = new MarketOperator("dana", "Dana White");
    SysAdmin* sa = new SysAdmin("admin", "Admin User");

    users.push_back(f1); users.push_back(f2);
    users.push_back(f3); users.push_back(f4);
    users.push_back(a1); users.push_back(a2);
    users.push_back(a3); users.push_back(a4);
    users.push_back(op); users.push_back(sa);
}

void DataManager::loadMarketDates() {
    QDate sun = QDate(2026, 5, 3);
    for (int w = 0; w < 4; w++) {
        // ensuring max 2 vendors for each category
        MarketDate* md = new MarketDate(sun.addDays(w * 7), 2, 2);
        schedule.addDate(md);
    }
}

User* DataManager::lookupUser(QString username) {
    QString lower = username.toLower().trimmed();
    for (int i = 0; i < users.size(); i++) {
        if (users[i]->getUsername().toLower() == lower)
            return users[i];
    }
    return nullptr;
}

Vendor* DataManager::lookupVendor(QString username) {
    User* u = lookupUser(username);
    if (u != nullptr && u->getRole() == User::VendorRole)
        return dynamic_cast<Vendor*>(u);
    return nullptr;
}

MarketSchedule* DataManager::getSchedule() { return &schedule; }

void DataManager::addBooking(StallBooking b) { bookings.push_back(b); }

void DataManager::removeBooking(QString vendorUser, QDate date) {
    for (int i = bookings.size() - 1; i >= 0; i--) {
        if (bookings[i].getVendorUser() == vendorUser && bookings[i].getMarketDate() == date) {
            bookings.removeAt(i);
            return;
        }
    }
}

bool DataManager::hasBooking(QString vendorUser, QDate date) {
    for (int i = 0; i < bookings.size(); i++) {
        if (bookings[i].getVendorUser() == vendorUser && bookings[i].getMarketDate() == date)
            return true;
    }
    return false;
}

bool DataManager::hasAnyBooking(QString vendorUser) {
    for (int i = 0; i < bookings.size(); i++) {
        if (bookings[i].getVendorUser() == vendorUser) return true;
    }
    return false;
}

QVector<StallBooking> DataManager::vendorBookings(QString vendorUser) {
    QVector<StallBooking> result;
    for (int i = 0; i < bookings.size(); i++) {
        if (bookings[i].getVendorUser() == vendorUser)
            result.push_back(bookings[i]);
    }
    return result;
}

Waitlist* DataManager::getWaitlist(QString category, QDate date) {
    // find existing or create new
    for (int i = 0; i < waitlists.size(); i++) {
        if (waitlists[i]->getCategory() == category && waitlists[i]->getMarketDate() == date)
            return waitlists[i];
    }
    Waitlist* wl = new Waitlist(category, date);
    waitlists.push_back(wl);
    return wl;
}

QVector<Waitlist*> DataManager::vendorWaitlists(QString vendorUser) {
    QVector<Waitlist*> result;
    for (int i = 0; i < waitlists.size(); i++) {
        if (waitlists[i]->contains(vendorUser))
            result.push_back(waitlists[i]);
    }
    return result;
}

void DataManager::notify(QString vendorUser, Notification n) {notifications[vendorUser].push_back(n);}
QVector<Notification> DataManager::getNotifications(QString vendorUser) {return notifications.value(vendorUser);}

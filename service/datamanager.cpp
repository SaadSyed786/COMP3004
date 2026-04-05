#include "datamanager.h"

DataManager::DataManager()
{
    if (connectToDatabase()) {
        loadAllUsers();
        loadMarketSchedule();
        loadBookings();
        loadWaitlists();
        loadNotifications();
    }
}

DataManager::~DataManager()
{
    for (int i = 0; i < userList.size(); i++)
        delete userList[i];

    QVector<MarketDate*> dates = schedule.getDates();
    for (int i = 0; i < dates.size(); i++)
        delete dates[i];

    for (int i = 0; i < waitlistList.size(); i++)
        delete waitlistList[i];

    if (database.isOpen())
        database.close();
}

bool DataManager::connectToDatabase()
{
    database = QSqlDatabase::addDatabase("QSQLITE");
    QString path = QCoreApplication::applicationDirPath() + "/hintonMarket.db";
    database.setDatabaseName(path);

    if (!database.open()) {
        qDebug() << "DB Error:" << database.lastError().text();
        return false;
    }
    return true;
}

void DataManager::loadAllUsers()
{
    QSqlQuery qry;

    qry.exec("SELECT username, full_name, role FROM users WHERE role != 'Vendor'");
    while (qry.next()) {
        QString name = qry.value(0).toString();
        QString full = qry.value(1).toString();
        QString role = qry.value(2).toString();

        if (role == "Operator")
            userList.append(new MarketOperator(name, full));
        else
            userList.append(new SysAdmin(name, full));
    }

    qry.exec("SELECT u.username, u.full_name, v.biz_name, v.category, "
             "v.email, v.phone, v.mailing_addr "
             "FROM users u INNER JOIN vendors v ON u.username = v.username "
             "WHERE u.role = 'Vendor'");

    while (qry.next()) {
        QString uname = qry.value(0).toString();
        QString full  = qry.value(1).toString();
        QString biz   = qry.value(2).toString();
        QString cat   = qry.value(3).toString();
        QString em    = qry.value(4).toString();
        QString ph    = qry.value(5).toString();
        QString addr  = qry.value(6).toString();

        Vendor* vendor;
        if (cat == "Food")
            vendor = new FoodVendor(uname, full, biz, em, ph, addr);
        else
            vendor = new ArtisanVendor(uname, full, biz, em, ph, addr);

        QSqlQuery docQry;
        docQry.prepare("SELECT doc_type, doc_number, expiry, provider "
                       "FROM compliance_docs WHERE vendor_username = ?");
        docQry.addBindValue(uname);
        docQry.exec();

        while (docQry.next()) {
            vendor->addDocument(ComplianceDoc(
                docQry.value(0).toString(),
                docQry.value(1).toString(),
                QDate::fromString(docQry.value(2).toString(), "yyyy-MM-dd"),
                docQry.value(3).toString()
            ));
        }
        userList.append(vendor);
    }
}

void DataManager::loadMarketSchedule()
{
    QSqlQuery qry;
    qry.exec("SELECT date, max_food, max_artisan, num_food_booked, num_artisan_booked "
             "FROM market_dates ORDER BY date");

    while (qry.next()) {
        QDate d   = QDate::fromString(qry.value(0).toString(), "yyyy-MM-dd");
        int maxF  = qry.value(1).toInt();
        int maxA  = qry.value(2).toInt();
        int bkdF  = qry.value(3).toInt();
        int bkdA  = qry.value(4).toInt();

        MarketDate* md = new MarketDate(d, maxF, maxA);
        for (int j = 0; j < bkdF; j++) md->bookFood();
        for (int j = 0; j < bkdA; j++) md->bookArtisan();
        schedule.addDate(md);
    }
}

void DataManager::loadBookings()
{
    QSqlQuery qry;
    qry.exec("SELECT vendor_username, market_date, category FROM stall_bookings");
    while (qry.next()) {
        bookingList.append(StallBooking(
            qry.value(0).toString(),
            QDate::fromString(qry.value(1).toString(), "yyyy-MM-dd"),
            qry.value(2).toString()
        ));
    }
}

void DataManager::loadWaitlists()
{
    QSqlQuery qry;
    qry.exec("SELECT DISTINCT category, market_date FROM waitlists");

    while (qry.next()) {
        QString cat = qry.value(0).toString();
        QDate   dt  = QDate::fromString(qry.value(1).toString(), "yyyy-MM-dd");

        Waitlist* wl = new Waitlist(cat, dt);

        // load vendors in FIFO order by position
        QSqlQuery inner;
        inner.prepare("SELECT vendor_username FROM waitlists "
                      "WHERE category=? AND market_date=? ORDER BY position");
        inner.addBindValue(cat);
        inner.addBindValue(dt.toString("yyyy-MM-dd"));
        inner.exec();
        while (inner.next())
            wl->enqueue(inner.value(0).toString());

        waitlistList.append(wl);
    }
}

void DataManager::loadNotifications()
{
    QSqlQuery qry;
    qry.exec("SELECT vendor_username, message, type FROM notifications ORDER BY id");
    while (qry.next()) {
        QString who = qry.value(0).toString();
        QString msg = qry.value(1).toString();
        QString ts  = qry.value(2).toString();

        Notification::Type t = Notification::Info;
        if (ts == "BookingConfirmed")  t = Notification::BookingConfirmed;
        if (ts == "BookingCancelled")  t = Notification::BookingCancelled;
        if (ts == "WaitlistAlert")     t = Notification::WaitlistAlert;

        notificationMap[who].append(Notification(msg, t));
    }
}

User* DataManager::findUser(QString username)
{
    QString lower = username.toLower().trimmed();
    for (int i = 0; i < userList.size(); i++) {
        if (userList[i]->getUsername().toLower() == lower)
            return userList[i];
    }
    return nullptr;
}

Vendor* DataManager::findVendor(QString username)
{
    User* u = findUser(username);
    if (u && u->getRole() == User::VendorRole)
        return dynamic_cast<Vendor*>(u);
    return nullptr;
}

QVector<Vendor*> DataManager::getAllVendors()
{
    QVector<Vendor*> result;
    for (int i = 0; i < userList.size(); i++) {
        Vendor* v = dynamic_cast<Vendor*>(userList[i]);
        if (v) result.append(v);
    }
    return result;
}

MarketSchedule* DataManager::getSchedule() { return &schedule; }

void DataManager::addBooking(StallBooking booking)
{
    bookingList.append(booking);
    writeBookingToDb(booking);
    MarketDate* md = schedule.findByDate(booking.getMarketDate());
    if (md) persistMarketDate(md);
}

void DataManager::removeBooking(QString vendorUsername, QDate date)
{
    for (int i = bookingList.size() - 1; i >= 0; i--) {
        if (bookingList[i].getVendorUser() == vendorUsername &&
            bookingList[i].getMarketDate() == date) {
            bookingList.removeAt(i);
            deleteBookingFromDb(vendorUsername, date);
            MarketDate* md = schedule.findByDate(date);
            if (md) persistMarketDate(md);
            return;
        }
    }
}

bool DataManager::hasBooking(QString vendorUsername, QDate date)
{
    for (int i = 0; i < bookingList.size(); i++)
        if (bookingList[i].getVendorUser() == vendorUsername &&
            bookingList[i].getMarketDate() == date)
            return true;
    return false;
}

bool DataManager::hasAnyBooking(QString vendorUsername)
{
    for (int i = 0; i < bookingList.size(); i++)
        if (bookingList[i].getVendorUser() == vendorUsername)
            return true;
    return false;
}

QVector<StallBooking> DataManager::getVendorBookings(QString vendorUsername)
{
    QVector<StallBooking> res;
    for (int i = 0; i < bookingList.size(); i++)
        if (bookingList[i].getVendorUser() == vendorUsername)
            res.append(bookingList[i]);
    return res;
}

Waitlist* DataManager::getWaitlist(QString category, QDate date)
{
    for (int i = 0; i < waitlistList.size(); i++)
        if (waitlistList[i]->getCategory() == category &&
            waitlistList[i]->getMarketDate() == date)
            return waitlistList[i];

    Waitlist* wl = new Waitlist(category, date);
    waitlistList.append(wl);
    return wl;
}

QVector<Waitlist*> DataManager::getVendorWaitlists(QString vendorUsername)
{
    QVector<Waitlist*> res;
    for (int i = 0; i < waitlistList.size(); i++)
        if (waitlistList[i]->contains(vendorUsername))
            res.append(waitlistList[i]);
    return res;
}

void DataManager::sendNotification(QString vendorUsername, Notification n)
{
    notificationMap[vendorUsername].append(n);
    writeNotificationToDb(vendorUsername, n);
}

QVector<Notification> DataManager::getNotifications(QString vendorUsername)
{
    return notificationMap.value(vendorUsername);
}

void DataManager::writeBookingToDb(StallBooking& b)
{
    QSqlQuery q;
    q.prepare("INSERT INTO stall_bookings (vendor_username, market_date, category, timestamp) "
              "VALUES (?, ?, ?, ?)");
    q.addBindValue(b.getVendorUser());
    q.addBindValue(b.getMarketDateStr());
    q.addBindValue(b.getCategory());
    q.addBindValue(b.getTimestamp().toString("yyyy-MM-dd hh:mm:ss"));
    q.exec();
}

void DataManager::deleteBookingFromDb(QString vendorUsername, QDate date)
{
    QSqlQuery q;
    q.prepare("DELETE FROM stall_bookings WHERE vendor_username=? AND market_date=?");
    q.addBindValue(vendorUsername);
    q.addBindValue(date.toString("yyyy-MM-dd"));
    q.exec();
}

void DataManager::persistMarketDate(MarketDate* md)
{
    QSqlQuery q;
    q.prepare("UPDATE market_dates SET num_food_booked=?, num_artisan_booked=? WHERE date=?");
    q.addBindValue(md->bookedFood());
    q.addBindValue(md->bookedArtisan());
    q.addBindValue(md->getDateStr());
    q.exec();
}

void DataManager::persistWaitlist(Waitlist* wl)
{
    QSqlQuery q;
    q.prepare("DELETE FROM waitlists WHERE category=? AND market_date=?");
    q.addBindValue(wl->getCategory());
    q.addBindValue(wl->getMarketDateStr());
    q.exec();

    // rewrite queue in exact FIFO order
    QList<QString> queue = wl->getQueue();
    for (int i = 0; i < queue.size(); i++) {
        QSqlQuery ins;
        ins.prepare("INSERT INTO waitlists (category, market_date, vendor_username, position) "
                    "VALUES (?,?,?,?)");
        ins.addBindValue(wl->getCategory());
        ins.addBindValue(wl->getMarketDateStr());
        ins.addBindValue(queue[i]);
        ins.addBindValue(i + 1);
        ins.exec();
    }
}

void DataManager::writeNotificationToDb(QString vendorUsername, Notification& n)
{
    QSqlQuery q;
    q.prepare("INSERT INTO notifications (vendor_username, message, type, timestamp) "
              "VALUES (?,?,?,?)");
    q.addBindValue(vendorUsername);
    q.addBindValue(n.getMessage());

    QString typeStr = "Info";
    if (n.getType() == Notification::BookingConfirmed)  typeStr = "BookingConfirmed";
    if (n.getType() == Notification::BookingCancelled)  typeStr = "BookingCancelled";
    if (n.getType() == Notification::WaitlistAlert)     typeStr = "WaitlistAlert";

    q.addBindValue(typeStr);
    q.addBindValue(n.getTime().toString("yyyy-MM-dd hh:mm:ss"));
    q.exec();
}
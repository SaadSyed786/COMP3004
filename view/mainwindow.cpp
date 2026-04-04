#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    dataMgr       = new DataManager();
    loginCtrl     = new LoginHandler(dataMgr);
    bookingCtrl   = new BookingHandler(dataMgr);
    waitlistCtrl  = new WaitlistHandler(dataMgr);
    scheduleCtrl  = new ScheduleHandler(dataMgr);
    dashboardCtrl = new DashboardHandler(dataMgr);

    connect(ui->opLogout, &QPushButton::clicked, this, &MainWindow::on_logoutBtn_clicked);
    connect(ui->adminLogout, &QPushButton::clicked, this, &MainWindow::on_logoutBtn_clicked);

    // when a row is selected in the schedule, update waitlist button
    connect(ui->schedTable, &QTableWidget::currentCellChanged,
            this, [this](int row, int, int, int){ onScheduleRowSelected(row); });

    showLoginPage();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete dataMgr;
    delete loginCtrl;
    delete bookingCtrl;
    delete waitlistCtrl;
    delete scheduleCtrl;
    delete dashboardCtrl;
}

/* ---------- page navigation ---------- */

void MainWindow::showLoginPage()
{
    activeUser = "";
    ui->usernameField->clear();
    ui->loginError->setText("");
    ui->pages->setCurrentIndex(0);
    ui->statusbar->showMessage("Enter a username to log in");
}

void MainWindow::showVendorMenu()
{
    Vendor* v = dataMgr->findVendor(activeUser);
    if (!v) return;
    ui->welcomeMsg->setText("Welcome, " + v->getFullName());
    ui->vendorTypeLabel->setText(v->getBusinessName() + "  |  " + v->getCategoryStr() + " Vendor");
    ui->pages->setCurrentIndex(1);
    ui->statusbar->showMessage("Logged in as " + v->getFullName());
}

void MainWindow::showSchedulePage()
{
    populateScheduleTable();
    ui->schedMsg->setText("");
    ui->waitlistBtn->setEnabled(false);
    ui->pages->setCurrentIndex(2);
}

void MainWindow::showDashboard()
{
    populateDashboard();
    ui->pages->setCurrentIndex(3);
}

/* ---------- login ---------- */

void MainWindow::on_loginBtn_clicked()
{
    QString typed = ui->usernameField->text().trimmed();
    if (typed.isEmpty()) {
        ui->loginError->setText("Please enter a username.");
        return;
    }

    User* found = loginCtrl->tryLogin(typed);
    if (!found) {
        ui->loginError->setText("User not found. Try again.");
        return;
    }

    activeUser = found->getUsername();
    ui->loginError->setText("");

    if (found->getRole() == User::VendorRole) {
        showVendorMenu();
    }
    else if (found->getRole() == User::OperatorRole) {
        setupOperatorPage();
        ui->pages->setCurrentIndex(4);
        ui->statusbar->showMessage("Logged in as " + found->getFullName() + " (Operator)");
    }
    else {
        ui->pages->setCurrentIndex(5);
        ui->statusbar->showMessage("Logged in as " + found->getFullName() + " (Admin)");
    }
}

void MainWindow::on_logoutBtn_clicked()       { showLoginPage(); }
void MainWindow::on_browseBtn_clicked()       { showSchedulePage(); }
void MainWindow::on_dashBtn_clicked()         { showDashboard(); }
void MainWindow::on_backScheduleBtn_clicked() { showVendorMenu(); }
void MainWindow::on_backDashBtn_clicked()     { showVendorMenu(); }

/* ---------- schedule table ---------- */

void MainWindow::populateScheduleTable()
{
    QVector<MarketDate*> dates = scheduleCtrl->getAvailableDates();
    ui->schedTable->setRowCount(dates.size());

    for (int r = 0; r < dates.size(); r++) {
        MarketDate* md = dates[r];

        ui->schedTable->setItem(r, 0, new QTableWidgetItem(md->getDateStr()));

        QString fAvail = QString::number(md->availableFood()) + " / " + QString::number(md->maxFoodStalls());
        ui->schedTable->setItem(r, 1, new QTableWidgetItem(fAvail));

        QString aAvail = QString::number(md->availableArtisan()) + " / " + QString::number(md->maxArtisanStalls());
        ui->schedTable->setItem(r, 2, new QTableWidgetItem(aAvail));

        QTableWidgetItem* fStatus = new QTableWidgetItem(md->foodFull() ? "FULL" : "Open");
        fStatus->setForeground(md->foodFull() ? QColor("red") : QColor("green"));
        ui->schedTable->setItem(r, 3, fStatus);

        QTableWidgetItem* aStatus = new QTableWidgetItem(md->artisanFull() ? "FULL" : "Open");
        aStatus->setForeground(md->artisanFull() ? QColor("red") : QColor("green"));
        ui->schedTable->setItem(r, 4, aStatus);
    }
    ui->schedTable->resizeColumnsToContents();
}

void MainWindow::onScheduleRowSelected(int row)
{
    // the waitlist button should only be clickable when stalls are full
    if (row < 0) { ui->waitlistBtn->setEnabled(false); return; }

    Vendor* v = dataMgr->findVendor(activeUser);
    if (!v) { ui->waitlistBtn->setEnabled(false); return; }

    QString ds = ui->schedTable->item(row, 0)->text();
    MarketDate* md = dataMgr->getSchedule()->findByDate(QDate::fromString(ds, "yyyy-MM-dd"));
    if (!md) { ui->waitlistBtn->setEnabled(false); return; }

    bool full = (v->getCategory() == Vendor::Food) ? md->foodFull() : md->artisanFull();
    ui->waitlistBtn->setEnabled(full);
}

/* ---------- vendor booking ---------- */

void MainWindow::on_bookBtn_clicked()
{
    int row = ui->schedTable->currentRow();
    if (row < 0) {
        ui->schedMsg->setStyleSheet("color: red;");
        ui->schedMsg->setText("Pick a market date first.");
        return;
    }

    QString ds = ui->schedTable->item(row, 0)->text();
    QDate dt = QDate::fromString(ds, "yyyy-MM-dd");
    QString err = bookingCtrl->bookStall(activeUser, dt);

    if (err.isEmpty()) {
        ui->schedMsg->setStyleSheet("color: green;");
        ui->schedMsg->setText("Booked for " + ds + "!");
        QMessageBox::information(this, "Booking Confirmed",
                                 "Stall booked for " + ds + ".\nSee your dashboard for details.");
        populateScheduleTable();
        onScheduleRowSelected(ui->schedTable->currentRow());
    }
    else if (err == "FULL") {
        Vendor* v = dataMgr->findVendor(activeUser);
        ui->schedMsg->setStyleSheet("color: orange;");
        ui->schedMsg->setText("No " + v->getCategoryStr() + " stalls left for " + ds
                              + ". Join the waitlist instead.");
    }
    else {
        ui->schedMsg->setStyleSheet("color: red;");
        ui->schedMsg->setText(err);
        QMessageBox::warning(this, "Cannot Book", err);
    }
}

void MainWindow::on_waitlistBtn_clicked()
{
    int row = ui->schedTable->currentRow();
    if (row < 0) {
        ui->schedMsg->setStyleSheet("color: red;");
        ui->schedMsg->setText("Pick a market date first.");
        return;
    }

    // double check stalls are actually full before allowing waitlist
    Vendor* v = dataMgr->findVendor(activeUser);
    if (!v) return;
    QString ds = ui->schedTable->item(row, 0)->text();
    QDate dt = QDate::fromString(ds, "yyyy-MM-dd");
    MarketDate* md = dataMgr->getSchedule()->findByDate(dt);
    if (md) {
        bool full = (v->getCategory() == Vendor::Food) ? md->foodFull() : md->artisanFull();
        if (!full) {
            ui->schedMsg->setStyleSheet("color: red;");
            ui->schedMsg->setText("Stalls still available — book directly instead.");
            return;
        }
    }

    QString err = waitlistCtrl->joinWaitlist(activeUser, dt);
    if (err.isEmpty()) {
        Waitlist* wl = dataMgr->getWaitlist(v->getCategoryStr(), dt);
        int pos = wl->positionOf(activeUser);
        ui->schedMsg->setStyleSheet("color: green;");
        ui->schedMsg->setText("Joined waitlist for " + ds + " (position " + QString::number(pos) + ")");
        QMessageBox::information(this, "Waitlist",
            "You are #" + QString::number(pos) + " on the "
            + v->getCategoryStr() + " waitlist for " + ds);
    } else {
        ui->schedMsg->setStyleSheet("color: red;");
        ui->schedMsg->setText(err);
    }
}

/* ---------- vendor dashboard ---------- */

void MainWindow::populateDashboard()
{
    Vendor* v = dashboardCtrl->getVendorInfo(activeUser);
    if (!v) return;

    // business info
    ui->bizInfo->setText(
        "<b>Business:</b> " + v->getBusinessName()
        + " &nbsp;|&nbsp; <b>Owner:</b> " + v->getFullName()
        + " &nbsp;|&nbsp; <b>Email:</b> " + v->getEmail()
        + " &nbsp;|&nbsp; <b>Phone:</b> " + v->getPhone()
        + "<br><b>Address:</b> " + v->getMailingAddress()
        + " &nbsp;|&nbsp; <b>Category:</b> " + v->getCategoryStr());

    // compliance
    QVector<ComplianceDoc>& docs = v->getDocuments();
    QString compHtml;
    for (int i = 0; i < docs.size(); i++) {
        QString status = docs[i].validForSeason()
                         ? "<span style='color:green'>Valid</span>"
                         : "<span style='color:red'>Expired</span>";
        compHtml += "<b>" + docs[i].getType() + ":</b> " + docs[i].getNumber();
        if (!docs[i].getProvider().isEmpty())
            compHtml += " (" + docs[i].getProvider() + ")";
        compHtml += " | Exp: " + docs[i].getExpiry().toString("yyyy-MM-dd") + " | " + status + "<br>";
    }
    compHtml += v->isCompliant()
                ? "<b>Status:</b> <span style='color:green'>Compliant</span>"
                : "<b>Status:</b> <span style='color:red'>Not Compliant</span>";
    ui->compInfo->setText(compHtml);

    // bookings table
    QVector<StallBooking> bk = dashboardCtrl->getBookings(activeUser);
    ui->bookTable->setRowCount(bk.size());
    for (int i = 0; i < bk.size(); i++) {
        ui->bookTable->setItem(i, 0, new QTableWidgetItem(bk[i].getMarketDateStr()));
        ui->bookTable->setItem(i, 1, new QTableWidgetItem(bk[i].getCategory()));
        ui->bookTable->setItem(i, 2, new QTableWidgetItem(
            bk[i].getTimestamp().toString("yyyy-MM-dd hh:mm")));
    }
    ui->bookTable->resizeColumnsToContents();

    // waitlists table
    QVector<Waitlist*> wls = dashboardCtrl->getWaitlists(activeUser);
    ui->waitTable->setRowCount(wls.size());
    for (int i = 0; i < wls.size(); i++) {
        ui->waitTable->setItem(i, 0, new QTableWidgetItem(wls[i]->getMarketDateStr()));
        ui->waitTable->setItem(i, 1, new QTableWidgetItem(wls[i]->getCategory()));
        ui->waitTable->setItem(i, 2, new QTableWidgetItem(
            QString::number(wls[i]->positionOf(activeUser))));
    }
    ui->waitTable->resizeColumnsToContents();

    // notifications
    QVector<Notification> notes = dashboardCtrl->getNotifications(activeUser);
    ui->notifList->clear();
    for (int i = 0; i < notes.size(); i++) {
        QString prefix;
        switch (notes[i].getType()) {
            case Notification::BookingConfirmed: prefix = "[Booked] "; break;
            case Notification::BookingCancelled: prefix = "[Cancelled] "; break;
            case Notification::WaitlistAlert:    prefix = "[Waitlist] "; break;
            default:                             prefix = "[Info] "; break;
        }
        ui->notifList->addItem(notes[i].getTime().toString("hh:mm") + " " + prefix + notes[i].getMessage());
    }
}

void MainWindow::on_cancelBookBtn_clicked()
{
    int row = ui->bookTable->currentRow();
    if (row < 0) { QMessageBox::warning(this, "No Selection", "Select a booking to cancel."); return; }

    QString ds = ui->bookTable->item(row, 0)->text();
    QDate dt = QDate::fromString(ds, "yyyy-MM-dd");

    if (QMessageBox::question(this, "Cancel Booking", "Cancel your booking for " + ds + "?",
                              QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes) {
        QString err = bookingCtrl->cancelStall(activeUser, dt);
        if (err.isEmpty()) {
            QMessageBox::information(this, "Cancelled", "Booking for " + ds + " cancelled.");
            populateDashboard();
        } else {
            QMessageBox::warning(this, "Error", err);
        }
    }
}

void MainWindow::on_leaveWaitBtn_clicked()
{
    int row = ui->waitTable->currentRow();
    if (row < 0) { QMessageBox::warning(this, "No Selection", "Select a waitlist entry."); return; }

    QString ds = ui->waitTable->item(row, 0)->text();
    QDate dt = QDate::fromString(ds, "yyyy-MM-dd");

    if (QMessageBox::question(this, "Leave Waitlist", "Leave waitlist for " + ds + "?",
                              QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes) {
        QString err = waitlistCtrl->leaveWaitlist(activeUser, dt);
        if (err.isEmpty()) {
            QMessageBox::information(this, "Done", "Removed from waitlist for " + ds + ".");
            populateDashboard();
        } else {
            QMessageBox::warning(this, "Error", err);
        }
    }
}

/* ---------- operator page ---------- */

void MainWindow::setupOperatorPage()
{
    ui->opVendorCombo->clear();
    QVector<Vendor*> vendors = dataMgr->getAllVendors();
    for (int i = 0; i < vendors.size(); i++) {
        QString lbl = vendors[i]->getUsername() + " - " + vendors[i]->getBusinessName()
                      + " (" + vendors[i]->getCategoryStr() + ")";
        ui->opVendorCombo->addItem(lbl, vendors[i]->getUsername());
    }
    fillOpScheduleTable();
    ui->opMsg->setText("Select a vendor and market date to manage bookings.");
    if (vendors.size() > 0) { fillOpBookingTable(); fillOpWaitlistTable(); }
}

void MainWindow::fillOpScheduleTable()
{
    QVector<MarketDate*> dates = scheduleCtrl->getAvailableDates();
    ui->opSchedTable->setRowCount(dates.size());
    for (int r = 0; r < dates.size(); r++) {
        MarketDate* md = dates[r];
        ui->opSchedTable->setItem(r, 0, new QTableWidgetItem(md->getDateStr()));

        ui->opSchedTable->setItem(r, 1, new QTableWidgetItem(
            QString::number(md->availableFood()) + " / " + QString::number(md->maxFoodStalls())));
        ui->opSchedTable->setItem(r, 2, new QTableWidgetItem(
            QString::number(md->availableArtisan()) + " / " + QString::number(md->maxArtisanStalls())));

        QTableWidgetItem* fs = new QTableWidgetItem(md->foodFull() ? "FULL" : "Open");
        fs->setForeground(md->foodFull() ? QColor("red") : QColor("green"));
        ui->opSchedTable->setItem(r, 3, fs);

        QTableWidgetItem* as = new QTableWidgetItem(md->artisanFull() ? "FULL" : "Open");
        as->setForeground(md->artisanFull() ? QColor("red") : QColor("green"));
        ui->opSchedTable->setItem(r, 4, as);
    }
    ui->opSchedTable->resizeColumnsToContents();
}

void MainWindow::on_opVendorCombo_currentIndexChanged(int idx)
{
    if (idx < 0) return;
    fillOpBookingTable();
    fillOpWaitlistTable();
}

void MainWindow::fillOpBookingTable()
{
    QString vu = ui->opVendorCombo->currentData().toString();
    QVector<StallBooking> bks = dataMgr->getVendorBookings(vu);
    ui->opBookTable->setRowCount(bks.size());
    for (int i = 0; i < bks.size(); i++) {
        ui->opBookTable->setItem(i, 0, new QTableWidgetItem(bks[i].getMarketDateStr()));
        ui->opBookTable->setItem(i, 1, new QTableWidgetItem(bks[i].getCategory()));
        ui->opBookTable->setItem(i, 2, new QTableWidgetItem(
            bks[i].getTimestamp().toString("yyyy-MM-dd hh:mm")));
    }
    ui->opBookTable->resizeColumnsToContents();
}

void MainWindow::fillOpWaitlistTable()
{
    QString vu = ui->opVendorCombo->currentData().toString();
    QVector<Waitlist*> wls = dataMgr->getVendorWaitlists(vu);
    ui->opWaitTable->setRowCount(wls.size());
    for (int i = 0; i < wls.size(); i++) {
        ui->opWaitTable->setItem(i, 0, new QTableWidgetItem(wls[i]->getMarketDateStr()));
        ui->opWaitTable->setItem(i, 1, new QTableWidgetItem(wls[i]->getCategory()));
        ui->opWaitTable->setItem(i, 2, new QTableWidgetItem(QString::number(wls[i]->positionOf(vu))));
    }
    ui->opWaitTable->resizeColumnsToContents();
}

void MainWindow::on_opBookBtn_clicked()
{
    int row = ui->opSchedTable->currentRow();
    if (row < 0) { ui->opMsg->setStyleSheet("color:red;"); ui->opMsg->setText("Select a date first."); return; }

    QString vu = ui->opVendorCombo->currentData().toString();
    QString ds = ui->opSchedTable->item(row, 0)->text();
    QDate dt = QDate::fromString(ds, "yyyy-MM-dd");

    QString err = bookingCtrl->bookStall(vu, dt);
    if (err.isEmpty()) {
        ui->opMsg->setStyleSheet("color:green;");
        ui->opMsg->setText("Booked stall for " + vu + " on " + ds);
        QMessageBox::information(this, "Booked", "Stall booked for '" + vu + "' on " + ds);
        fillOpScheduleTable(); fillOpBookingTable(); fillOpWaitlistTable();
    } else if (err == "FULL") {
        ui->opMsg->setStyleSheet("color:orange;");
        ui->opMsg->setText("No stalls left for " + ds);
    } else {
        ui->opMsg->setStyleSheet("color:red;"); ui->opMsg->setText(err);
        QMessageBox::warning(this, "Error", err);
    }
}

void MainWindow::on_opCancelBtn_clicked()
{
    int row = ui->opBookTable->currentRow();
    if (row < 0) { QMessageBox::warning(this, "Error", "Select a booking first."); return; }

    QString vu = ui->opVendorCombo->currentData().toString();
    QString ds = ui->opBookTable->item(row, 0)->text();
    QDate dt = QDate::fromString(ds, "yyyy-MM-dd");

    if (QMessageBox::question(this, "Cancel", "Cancel booking for '" + vu + "' on " + ds + "?",
                              QMessageBox::Yes|QMessageBox::No) == QMessageBox::Yes) {
        QString err = bookingCtrl->cancelStall(vu, dt);
        if (err.isEmpty()) {
            ui->opMsg->setStyleSheet("color:green;");
            ui->opMsg->setText("Cancelled " + vu + " for " + ds);
            fillOpScheduleTable(); fillOpBookingTable(); fillOpWaitlistTable();
        } else { QMessageBox::warning(this, "Error", err); }
    }
}

void MainWindow::on_opRemoveWaitBtn_clicked()
{
    int row = ui->opWaitTable->currentRow();
    if (row < 0) { QMessageBox::warning(this, "Error", "Select a waitlist entry first."); return; }

    QString vu = ui->opVendorCombo->currentData().toString();
    QString ds = ui->opWaitTable->item(row, 0)->text();
    QDate dt = QDate::fromString(ds, "yyyy-MM-dd");

    if (QMessageBox::question(this, "Remove", "Remove '" + vu + "' from waitlist for " + ds + "?",
                              QMessageBox::Yes|QMessageBox::No) == QMessageBox::Yes) {
        QString err = waitlistCtrl->leaveWaitlist(vu, dt);
        if (err.isEmpty()) {
            ui->opMsg->setStyleSheet("color:green;");
            ui->opMsg->setText("Removed " + vu + " from waitlist for " + ds);
            fillOpWaitlistTable();
        } else { QMessageBox::warning(this, "Error", err); }
    }
}

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    data = new DataManager();
    loginHandler = new LoginHandler(data);
    bookingHandler = new BookingHandler(data);
    waitlistHandler = new WaitlistHandler(data);
    scheduleHandler = new ScheduleHandler(data);
    dashHandler = new DashboardHandler(data);

    connect(ui->opLogout, &QPushButton::clicked, this, &MainWindow::on_logoutBtn_clicked);
    connect(ui->adminLogout, &QPushButton::clicked, this, &MainWindow::on_logoutBtn_clicked);

    goToLogin();
}

MainWindow::~MainWindow() {
    delete ui;
    delete data;
    delete loginHandler;
    delete bookingHandler;
    delete waitlistHandler;
    delete scheduleHandler;
    delete dashHandler;
}



void MainWindow::goToLogin() {
    currentUser = "";
    ui->usernameField->clear();
    ui->loginError->setText("");
    ui->pages->setCurrentIndex(0);
    ui->statusbar->showMessage("Enter a username to log in");
}

void MainWindow::goToVendorMenu() {
    Vendor* v = data->lookupVendor(currentUser);
    if (!v) return;
    ui->welcomeMsg->setText("Welcome, " + v->getFullName());
    ui->vendorTypeLabel->setText(v->getBusinessName() + " | " + v->getCategoryStr() + " Vendor");
    ui->pages->setCurrentIndex(1);
    ui->statusbar->showMessage("Logged in as " + v->getFullName());
}

void MainWindow::goToSchedule() {
    loadScheduleTable();
    ui->schedMsg->setText("");
    ui->pages->setCurrentIndex(2);
}

void MainWindow::goToDashboard() {
    loadDashboardData();
    ui->pages->setCurrentIndex(3);
}


void MainWindow::on_loginBtn_clicked() {
    QString uname = ui->usernameField->text().trimmed();
    if (uname.isEmpty()) {
        ui->loginError->setText("Please enter a username.");
        return;
    }

    User* u = loginHandler->tryLogin(uname);
    if (u == nullptr) {
        ui->loginError->setText("User not found. Check the username and try again.");
        return;
    }

    currentUser = u->getUsername();
    ui->loginError->setText("");

    if (u->getRole() == User::VendorRole) {
        goToVendorMenu();
    } else if (u->getRole() == User::OperatorRole) {
        ui->pages->setCurrentIndex(4);
        ui->statusbar->showMessage("Logged in as " + u->getFullName() + " (Operator)");
    } else {
        ui->pages->setCurrentIndex(5);
        ui->statusbar->showMessage("Logged in as " + u->getFullName() + " (Admin)");
    }
}

void MainWindow::on_logoutBtn_clicked() { goToLogin(); }
void MainWindow::on_browseBtn_clicked() { goToSchedule(); }
void MainWindow::on_dashBtn_clicked() { goToDashboard(); }
void MainWindow::on_backScheduleBtn_clicked() { goToVendorMenu(); }
void MainWindow::on_backDashBtn_clicked() { goToVendorMenu(); }


void MainWindow::loadScheduleTable() {
    QVector<MarketDate*> dates = scheduleHandler->getAvailableDates();
    ui->schedTable->setRowCount(dates.size());

    for (int i = 0; i < dates.size(); i++) {
        MarketDate* md = dates[i];
        ui->schedTable->setItem(i, 0, new QTableWidgetItem(md->getDateStr()));

        QString foodStr = QString::number(md->availableFood()) + " / " + QString::number(md->maxFoodStalls());
        ui->schedTable->setItem(i, 1, new QTableWidgetItem(foodStr));

        QString artStr = QString::number(md->availableArtisan()) + " / " + QString::number(md->maxArtisanStalls());
        ui->schedTable->setItem(i, 2, new QTableWidgetItem(artStr));

        // colour the stall status text
        QTableWidgetItem* foodStatus = new QTableWidgetItem(md->foodFull() ? "FULL" : "Open");
        foodStatus->setForeground(md->foodFull() ? QColor("red") : QColor("green"));
        ui->schedTable->setItem(i, 3, foodStatus);

        QTableWidgetItem* artStatus = new QTableWidgetItem(md->artisanFull() ? "FULL" : "Open");
        artStatus->setForeground(md->artisanFull() ? QColor("red") : QColor("green"));
        ui->schedTable->setItem(i, 4, artStatus);
    }
    ui->schedTable->resizeColumnsToContents();
}



void MainWindow::on_bookBtn_clicked() {
    int row = ui->schedTable->currentRow();
    if (row < 0) {
        ui->schedMsg->setStyleSheet("color: red;");
        ui->schedMsg->setText("Select a market date first.");
        return;
    }

    QString dateStr = ui->schedTable->item(row, 0)->text();
    QDate date = QDate::fromString(dateStr, "yyyy-MM-dd");
    QString result = bookingHandler->bookStall(currentUser, date);

    if (result.isEmpty()) {
        ui->schedMsg->setStyleSheet("color: green;");
        ui->schedMsg->setText("Booked successfully for " + dateStr + "!");
        QMessageBox::information(this, "Booking Confirmed",
            "Stall booked for " + dateStr + ".\nCheck your dashboard for details.");
        loadScheduleTable();
    } else if (result == "FULL") {
        Vendor* v = data->lookupVendor(currentUser);
        ui->schedMsg->setStyleSheet("color: orange;");
        ui->schedMsg->setText("No " + v->getCategoryStr() + " stalls left for " + dateStr + ". Try joining the waitlist.");
    } else {
        ui->schedMsg->setStyleSheet("color: red;");
        ui->schedMsg->setText(result);
        QMessageBox::warning(this, "Cannot Book", result);
    }
}

void MainWindow::on_waitlistBtn_clicked() {
    int row = ui->schedTable->currentRow();
    if (row < 0) {
        ui->schedMsg->setStyleSheet("color: red;");
        ui->schedMsg->setText("Select a market date first.");
        return;
    }

    QString dateStr = ui->schedTable->item(row, 0)->text();
    QDate date = QDate::fromString(dateStr, "yyyy-MM-dd");
    QString result = waitlistHandler->joinWaitlist(currentUser, date);

    if (result.isEmpty()) {
        Vendor* v = data->lookupVendor(currentUser);
        Waitlist* wl = data->getWaitlist(v->getCategoryStr(), date);
        int pos = wl->positionOf(currentUser);
        ui->schedMsg->setStyleSheet("color: green;");
        ui->schedMsg->setText("Joined waitlist for " + dateStr + " (position " + QString::number(pos) + ")");
        QMessageBox::information(this, "Waitlist", "You are #" + QString::number(pos) +
            " on the " + v->getCategoryStr() + " waitlist for " + dateStr);
    } else {
        ui->schedMsg->setStyleSheet("color: red;");
        ui->schedMsg->setText(result);
    }
}


void MainWindow::loadDashboardData() {
    Vendor* v = dashHandler->getVendorInfo(currentUser);
    if (!v) return;

    // business info
    ui->bizInfo->setText(
        "<b>Business:</b> " + v->getBusinessName() +
        " &nbsp;|&nbsp; <b>Owner:</b> " + v->getFullName() +
        " &nbsp;|&nbsp; <b>Email:</b> " + v->getEmail() +
        " &nbsp;|&nbsp; <b>Phone:</b> " + v->getPhone() +
        "<br><b>Address:</b> " + v->getMailingAddress() +
        " &nbsp;|&nbsp; <b>Category:</b> " + v->getCategoryStr());

    // compliance documents
    QString compStr;
    QVector<ComplianceDoc>& docs = v->getDocuments();
    for (int i = 0; i < docs.size(); i++) {
        QString valid = docs[i].validForSeason() ? "<span style='color:green'>Valid</span>"
                                                  : "<span style='color:red'>Expired</span>";
        compStr += "<b>" + docs[i].getType() + ":</b> " + docs[i].getNumber();
        if (!docs[i].getProvider().isEmpty()) compStr += " (" + docs[i].getProvider() + ")";
        compStr += " | Exp: " + docs[i].getExpiry().toString("yyyy-MM-dd") + " | " + valid + "<br>";
    }
    compStr += v->isCompliant() ? "<b>Status:</b> <span style='color:green'>Compliant</span>"
                                : "<b>Status:</b> <span style='color:red'>Not Compliant</span>";
    ui->compInfo->setText(compStr);

    // booking table
    QVector<StallBooking> bk = dashHandler->getBookings(currentUser);
    ui->bookTable->setRowCount(bk.size());
    for (int i = 0; i < bk.size(); i++) {
        ui->bookTable->setItem(i, 0, new QTableWidgetItem(bk[i].getMarketDateStr()));
        ui->bookTable->setItem(i, 1, new QTableWidgetItem(bk[i].getCategory()));
        ui->bookTable->setItem(i, 2, new QTableWidgetItem(bk[i].getTimestamp().toString("yyyy-MM-dd hh:mm")));
    }
    ui->bookTable->resizeColumnsToContents();

    // waitlist table
    QVector<Waitlist*> wls = dashHandler->getWaitlists(currentUser);
    ui->waitTable->setRowCount(wls.size());
    for (int i = 0; i < wls.size(); i++) {
        ui->waitTable->setItem(i, 0, new QTableWidgetItem(wls[i]->getMarketDateStr()));
        ui->waitTable->setItem(i, 1, new QTableWidgetItem(wls[i]->getCategory()));
        ui->waitTable->setItem(i, 2, new QTableWidgetItem(QString::number(wls[i]->positionOf(currentUser))));
    }
    ui->waitTable->resizeColumnsToContents();

    // notifications 
    QVector<Notification> notifs = dashHandler->getNotifs(currentUser);
    ui->notifList->clear();
    for (int i = 0; i < notifs.size(); i++) {
        QString tag = "";
        if (notifs[i].getType() == Notification::BookingConfirmed) tag = "[Booked] ";
        else if (notifs[i].getType() == Notification::BookingCancelled) tag = "[Cancelled] ";
        else if (notifs[i].getType() == Notification::WaitlistAlert) tag = "[Waitlist] ";
        else tag = "[Info] ";
        ui->notifList->addItem(notifs[i].getTime().toString("hh:mm") + " " + tag + notifs[i].getMessage());
    }
}


void MainWindow::on_cancelBookBtn_clicked() {
    int row = ui->bookTable->currentRow();
    if (row < 0) {
        QMessageBox::warning(this, "No Selection", "Select a booking to cancel.");
        return;
    }

    QString dateStr = ui->bookTable->item(row, 0)->text();
    QDate date = QDate::fromString(dateStr, "yyyy-MM-dd");

    int reply = QMessageBox::question(this, "Cancel Booking",
        "Cancel your booking for " + dateStr + "?", QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        QString res = bookingHandler->cancelStall(currentUser, date);
        if (res.isEmpty()) {
            QMessageBox::information(this, "Cancelled", "Booking for " + dateStr + " cancelled.");
            loadDashboardData();
        } else {
            QMessageBox::warning(this, "Error", res);
        }
    }
}


void MainWindow::on_leaveWaitBtn_clicked() {
    int row = ui->waitTable->currentRow();
    if (row < 0) {
        QMessageBox::warning(this, "No Selection", "Select a waitlist entry to leave.");
        return;
    }

    QString dateStr = ui->waitTable->item(row, 0)->text();
    QDate date = QDate::fromString(dateStr, "yyyy-MM-dd");

    int reply = QMessageBox::question(this, "Leave Waitlist",
        "Leave the waitlist for " + dateStr + "?", QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        QString res = waitlistHandler->leaveWaitlist(currentUser, date);
        if (res.isEmpty()) {
            QMessageBox::information(this, "Done", "Removed from waitlist for " + dateStr + ".");
            loadDashboardData();
        } else {
            QMessageBox::warning(this, "Error", res);
        }
    }
}

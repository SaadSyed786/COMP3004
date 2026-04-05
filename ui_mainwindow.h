/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *pages;
    QWidget *loginPage;
    QLabel *appTitle;
    QLabel *appSubtitle;
    QLabel *loginLabel;
    QLineEdit *usernameField;
    QPushButton *loginBtn;
    QLabel *loginError;
    QLabel *accHeader;
    QLabel *accFood;
    QLabel *accArtisan;
    QLabel *accOther;
    QWidget *vendorMenuPage;
    QLabel *menuTitle;
    QLabel *welcomeMsg;
    QLabel *vendorTypeLabel;
    QPushButton *logoutBtn;
    QPushButton *browseBtn;
    QPushButton *dashBtn;
    QWidget *schedulePage;
    QLabel *schedTitle;
    QLabel *schedHint;
    QPushButton *backScheduleBtn;
    QTableWidget *schedTable;
    QPushButton *bookBtn;
    QPushButton *waitlistBtn;
    QLabel *schedMsg;
    QWidget *dashPage;
    QLabel *dashTitle;
    QPushButton *backDashBtn;
    QLabel *bizHeader;
    QLabel *bizInfo;
    QLabel *compHeader;
    QLabel *compInfo;
    QLabel *bookHeader;
    QTableWidget *bookTable;
    QPushButton *cancelBookBtn;
    QLabel *waitHeader;
    QTableWidget *waitTable;
    QPushButton *leaveWaitBtn;
    QLabel *notifHeader;
    QListWidget *notifList;
    QWidget *operatorPage;
    QLabel *opTitle;
    QPushButton *opLogout;
    QLabel *opVendorLabel;
    QComboBox *opVendorCombo;
    QLabel *opSchedHeader;
    QTableWidget *opSchedTable;
    QPushButton *opBookBtn;
    QLabel *opBookHeader;
    QTableWidget *opBookTable;
    QPushButton *opCancelBtn;
    QLabel *opWaitHeader;
    QTableWidget *opWaitTable;
    QPushButton *opRemoveWaitBtn;
    QLabel *opMsg;
    QWidget *adminPage;
    QLabel *adminTitle;
    QPushButton *adminLogout;
    QLabel *adminMsg;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(960, 700);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pages = new QStackedWidget(centralwidget);
        pages->setObjectName(QString::fromUtf8("pages"));
        pages->setGeometry(QRect(0, 0, 960, 670));
        loginPage = new QWidget();
        loginPage->setObjectName(QString::fromUtf8("loginPage"));
        appTitle = new QLabel(loginPage);
        appTitle->setObjectName(QString::fromUtf8("appTitle"));
        appTitle->setGeometry(QRect(280, 80, 400, 40));
        appTitle->setAlignment(Qt::AlignCenter);
        appSubtitle = new QLabel(loginPage);
        appSubtitle->setObjectName(QString::fromUtf8("appSubtitle"));
        appSubtitle->setGeometry(QRect(230, 120, 500, 20));
        appSubtitle->setAlignment(Qt::AlignCenter);
        loginLabel = new QLabel(loginPage);
        loginLabel->setObjectName(QString::fromUtf8("loginLabel"));
        loginLabel->setGeometry(QRect(370, 195, 220, 20));
        loginLabel->setAlignment(Qt::AlignCenter);
        usernameField = new QLineEdit(loginPage);
        usernameField->setObjectName(QString::fromUtf8("usernameField"));
        usernameField->setGeometry(QRect(355, 220, 250, 30));
        usernameField->setAlignment(Qt::AlignCenter);
        loginBtn = new QPushButton(loginPage);
        loginBtn->setObjectName(QString::fromUtf8("loginBtn"));
        loginBtn->setGeometry(QRect(405, 260, 150, 32));
        loginError = new QLabel(loginPage);
        loginError->setObjectName(QString::fromUtf8("loginError"));
        loginError->setGeometry(QRect(305, 300, 350, 20));
        loginError->setAlignment(Qt::AlignCenter);
        accHeader = new QLabel(loginPage);
        accHeader->setObjectName(QString::fromUtf8("accHeader"));
        accHeader->setGeometry(QRect(330, 355, 300, 18));
        accHeader->setAlignment(Qt::AlignCenter);
        accFood = new QLabel(loginPage);
        accFood->setObjectName(QString::fromUtf8("accFood"));
        accFood->setGeometry(QRect(280, 378, 400, 16));
        accFood->setAlignment(Qt::AlignCenter);
        accArtisan = new QLabel(loginPage);
        accArtisan->setObjectName(QString::fromUtf8("accArtisan"));
        accArtisan->setGeometry(QRect(280, 396, 400, 16));
        accArtisan->setAlignment(Qt::AlignCenter);
        accOther = new QLabel(loginPage);
        accOther->setObjectName(QString::fromUtf8("accOther"));
        accOther->setGeometry(QRect(280, 414, 400, 16));
        accOther->setAlignment(Qt::AlignCenter);
        pages->addWidget(loginPage);
        vendorMenuPage = new QWidget();
        vendorMenuPage->setObjectName(QString::fromUtf8("vendorMenuPage"));
        menuTitle = new QLabel(vendorMenuPage);
        menuTitle->setObjectName(QString::fromUtf8("menuTitle"));
        menuTitle->setGeometry(QRect(30, 20, 300, 28));
        welcomeMsg = new QLabel(vendorMenuPage);
        welcomeMsg->setObjectName(QString::fromUtf8("welcomeMsg"));
        welcomeMsg->setGeometry(QRect(30, 55, 500, 20));
        vendorTypeLabel = new QLabel(vendorMenuPage);
        vendorTypeLabel->setObjectName(QString::fromUtf8("vendorTypeLabel"));
        vendorTypeLabel->setGeometry(QRect(30, 78, 500, 18));
        logoutBtn = new QPushButton(vendorMenuPage);
        logoutBtn->setObjectName(QString::fromUtf8("logoutBtn"));
        logoutBtn->setGeometry(QRect(810, 25, 110, 30));
        browseBtn = new QPushButton(vendorMenuPage);
        browseBtn->setObjectName(QString::fromUtf8("browseBtn"));
        browseBtn->setGeometry(QRect(310, 190, 340, 50));
        dashBtn = new QPushButton(vendorMenuPage);
        dashBtn->setObjectName(QString::fromUtf8("dashBtn"));
        dashBtn->setGeometry(QRect(310, 260, 340, 50));
        pages->addWidget(vendorMenuPage);
        schedulePage = new QWidget();
        schedulePage->setObjectName(QString::fromUtf8("schedulePage"));
        schedTitle = new QLabel(schedulePage);
        schedTitle->setObjectName(QString::fromUtf8("schedTitle"));
        schedTitle->setGeometry(QRect(30, 12, 300, 28));
        schedHint = new QLabel(schedulePage);
        schedHint->setObjectName(QString::fromUtf8("schedHint"));
        schedHint->setGeometry(QRect(30, 45, 600, 18));
        backScheduleBtn = new QPushButton(schedulePage);
        backScheduleBtn->setObjectName(QString::fromUtf8("backScheduleBtn"));
        backScheduleBtn->setGeometry(QRect(810, 15, 110, 30));
        schedTable = new QTableWidget(schedulePage);
        if (schedTable->columnCount() < 5)
            schedTable->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        schedTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        schedTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        schedTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        schedTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        schedTable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        schedTable->setObjectName(QString::fromUtf8("schedTable"));
        schedTable->setGeometry(QRect(30, 72, 895, 400));
        schedTable->setSelectionMode(QAbstractItemView::SingleSelection);
        schedTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        schedTable->setAlternatingRowColors(true);
        schedTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        schedTable->setColumnCount(5);
        bookBtn = new QPushButton(schedulePage);
        bookBtn->setObjectName(QString::fromUtf8("bookBtn"));
        bookBtn->setGeometry(QRect(30, 490, 160, 34));
        waitlistBtn = new QPushButton(schedulePage);
        waitlistBtn->setObjectName(QString::fromUtf8("waitlistBtn"));
        waitlistBtn->setGeometry(QRect(210, 490, 160, 34));
        schedMsg = new QLabel(schedulePage);
        schedMsg->setObjectName(QString::fromUtf8("schedMsg"));
        schedMsg->setGeometry(QRect(30, 540, 895, 40));
        schedMsg->setWordWrap(true);
        pages->addWidget(schedulePage);
        dashPage = new QWidget();
        dashPage->setObjectName(QString::fromUtf8("dashPage"));
        dashTitle = new QLabel(dashPage);
        dashTitle->setObjectName(QString::fromUtf8("dashTitle"));
        dashTitle->setGeometry(QRect(30, 8, 300, 28));
        backDashBtn = new QPushButton(dashPage);
        backDashBtn->setObjectName(QString::fromUtf8("backDashBtn"));
        backDashBtn->setGeometry(QRect(810, 10, 110, 30));
        bizHeader = new QLabel(dashPage);
        bizHeader->setObjectName(QString::fromUtf8("bizHeader"));
        bizHeader->setGeometry(QRect(30, 45, 200, 16));
        bizInfo = new QLabel(dashPage);
        bizInfo->setObjectName(QString::fromUtf8("bizInfo"));
        bizInfo->setGeometry(QRect(30, 63, 890, 55));
        bizInfo->setWordWrap(true);
        compHeader = new QLabel(dashPage);
        compHeader->setObjectName(QString::fromUtf8("compHeader"));
        compHeader->setGeometry(QRect(30, 125, 300, 16));
        compInfo = new QLabel(dashPage);
        compInfo->setObjectName(QString::fromUtf8("compInfo"));
        compInfo->setGeometry(QRect(30, 143, 890, 65));
        compInfo->setWordWrap(true);
        bookHeader = new QLabel(dashPage);
        bookHeader->setObjectName(QString::fromUtf8("bookHeader"));
        bookHeader->setGeometry(QRect(30, 218, 200, 16));
        bookTable = new QTableWidget(dashPage);
        if (bookTable->columnCount() < 3)
            bookTable->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        bookTable->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        bookTable->setHorizontalHeaderItem(1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        bookTable->setHorizontalHeaderItem(2, __qtablewidgetitem7);
        bookTable->setObjectName(QString::fromUtf8("bookTable"));
        bookTable->setGeometry(QRect(30, 238, 580, 95));
        bookTable->setSelectionMode(QAbstractItemView::SingleSelection);
        bookTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        bookTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        bookTable->setColumnCount(3);
        cancelBookBtn = new QPushButton(dashPage);
        cancelBookBtn->setObjectName(QString::fromUtf8("cancelBookBtn"));
        cancelBookBtn->setGeometry(QRect(630, 260, 190, 30));
        waitHeader = new QLabel(dashPage);
        waitHeader->setObjectName(QString::fromUtf8("waitHeader"));
        waitHeader->setGeometry(QRect(30, 345, 200, 16));
        waitTable = new QTableWidget(dashPage);
        if (waitTable->columnCount() < 3)
            waitTable->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        waitTable->setHorizontalHeaderItem(0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        waitTable->setHorizontalHeaderItem(1, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        waitTable->setHorizontalHeaderItem(2, __qtablewidgetitem10);
        waitTable->setObjectName(QString::fromUtf8("waitTable"));
        waitTable->setGeometry(QRect(30, 365, 580, 95));
        waitTable->setSelectionMode(QAbstractItemView::SingleSelection);
        waitTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        waitTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        waitTable->setColumnCount(3);
        leaveWaitBtn = new QPushButton(dashPage);
        leaveWaitBtn->setObjectName(QString::fromUtf8("leaveWaitBtn"));
        leaveWaitBtn->setGeometry(QRect(630, 387, 190, 30));
        notifHeader = new QLabel(dashPage);
        notifHeader->setObjectName(QString::fromUtf8("notifHeader"));
        notifHeader->setGeometry(QRect(30, 475, 200, 16));
        notifList = new QListWidget(dashPage);
        notifList->setObjectName(QString::fromUtf8("notifList"));
        notifList->setGeometry(QRect(30, 495, 890, 130));
        pages->addWidget(dashPage);
        operatorPage = new QWidget();
        operatorPage->setObjectName(QString::fromUtf8("operatorPage"));
        opTitle = new QLabel(operatorPage);
        opTitle->setObjectName(QString::fromUtf8("opTitle"));
        opTitle->setGeometry(QRect(30, 10, 400, 28));
        opLogout = new QPushButton(operatorPage);
        opLogout->setObjectName(QString::fromUtf8("opLogout"));
        opLogout->setGeometry(QRect(810, 12, 110, 30));
        opVendorLabel = new QLabel(operatorPage);
        opVendorLabel->setObjectName(QString::fromUtf8("opVendorLabel"));
        opVendorLabel->setGeometry(QRect(30, 48, 100, 20));
        opVendorCombo = new QComboBox(operatorPage);
        opVendorCombo->setObjectName(QString::fromUtf8("opVendorCombo"));
        opVendorCombo->setGeometry(QRect(135, 45, 400, 28));
        opSchedHeader = new QLabel(operatorPage);
        opSchedHeader->setObjectName(QString::fromUtf8("opSchedHeader"));
        opSchedHeader->setGeometry(QRect(30, 82, 300, 16));
        opSchedTable = new QTableWidget(operatorPage);
        if (opSchedTable->columnCount() < 5)
            opSchedTable->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        opSchedTable->setHorizontalHeaderItem(0, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        opSchedTable->setHorizontalHeaderItem(1, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        opSchedTable->setHorizontalHeaderItem(2, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        opSchedTable->setHorizontalHeaderItem(3, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        opSchedTable->setHorizontalHeaderItem(4, __qtablewidgetitem15);
        opSchedTable->setObjectName(QString::fromUtf8("opSchedTable"));
        opSchedTable->setGeometry(QRect(30, 100, 895, 140));
        opSchedTable->setSelectionMode(QAbstractItemView::SingleSelection);
        opSchedTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        opSchedTable->setAlternatingRowColors(true);
        opSchedTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        opSchedTable->setColumnCount(5);
        opBookBtn = new QPushButton(operatorPage);
        opBookBtn->setObjectName(QString::fromUtf8("opBookBtn"));
        opBookBtn->setGeometry(QRect(30, 248, 200, 32));
        opBookHeader = new QLabel(operatorPage);
        opBookHeader->setObjectName(QString::fromUtf8("opBookHeader"));
        opBookHeader->setGeometry(QRect(30, 295, 300, 16));
        opBookTable = new QTableWidget(operatorPage);
        if (opBookTable->columnCount() < 3)
            opBookTable->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        opBookTable->setHorizontalHeaderItem(0, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        opBookTable->setHorizontalHeaderItem(1, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        opBookTable->setHorizontalHeaderItem(2, __qtablewidgetitem18);
        opBookTable->setObjectName(QString::fromUtf8("opBookTable"));
        opBookTable->setGeometry(QRect(30, 314, 580, 95));
        opBookTable->setSelectionMode(QAbstractItemView::SingleSelection);
        opBookTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        opBookTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        opBookTable->setColumnCount(3);
        opCancelBtn = new QPushButton(operatorPage);
        opCancelBtn->setObjectName(QString::fromUtf8("opCancelBtn"));
        opCancelBtn->setGeometry(QRect(630, 340, 200, 32));
        opWaitHeader = new QLabel(operatorPage);
        opWaitHeader->setObjectName(QString::fromUtf8("opWaitHeader"));
        opWaitHeader->setGeometry(QRect(30, 422, 300, 16));
        opWaitTable = new QTableWidget(operatorPage);
        if (opWaitTable->columnCount() < 3)
            opWaitTable->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        opWaitTable->setHorizontalHeaderItem(0, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        opWaitTable->setHorizontalHeaderItem(1, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        opWaitTable->setHorizontalHeaderItem(2, __qtablewidgetitem21);
        opWaitTable->setObjectName(QString::fromUtf8("opWaitTable"));
        opWaitTable->setGeometry(QRect(30, 441, 580, 95));
        opWaitTable->setSelectionMode(QAbstractItemView::SingleSelection);
        opWaitTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        opWaitTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        opWaitTable->setColumnCount(3);
        opRemoveWaitBtn = new QPushButton(operatorPage);
        opRemoveWaitBtn->setObjectName(QString::fromUtf8("opRemoveWaitBtn"));
        opRemoveWaitBtn->setGeometry(QRect(630, 467, 200, 32));
        opMsg = new QLabel(operatorPage);
        opMsg->setObjectName(QString::fromUtf8("opMsg"));
        opMsg->setGeometry(QRect(30, 555, 890, 40));
        opMsg->setWordWrap(true);
        pages->addWidget(operatorPage);
        adminPage = new QWidget();
        adminPage->setObjectName(QString::fromUtf8("adminPage"));
        adminTitle = new QLabel(adminPage);
        adminTitle->setObjectName(QString::fromUtf8("adminTitle"));
        adminTitle->setGeometry(QRect(30, 20, 400, 28));
        adminLogout = new QPushButton(adminPage);
        adminLogout->setObjectName(QString::fromUtf8("adminLogout"));
        adminLogout->setGeometry(QRect(810, 25, 110, 30));
        adminMsg = new QLabel(adminPage);
        adminMsg->setObjectName(QString::fromUtf8("adminMsg"));
        adminMsg->setGeometry(QRect(30, 70, 500, 20));
        pages->addWidget(adminPage);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 960, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        pages->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "HintonMarket - Farmers Market Management System", nullptr));
        appTitle->setText(QCoreApplication::translate("MainWindow", "HintonMarket", nullptr));
        appTitle->setStyleSheet(QCoreApplication::translate("MainWindow", "font-size: 26px; font-weight: bold;", nullptr));
        appSubtitle->setText(QCoreApplication::translate("MainWindow", "Hintonville Farmers Market Management System", nullptr));
        appSubtitle->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #666;", nullptr));
        loginLabel->setText(QCoreApplication::translate("MainWindow", "Enter username to log in:", nullptr));
        usernameField->setPlaceholderText(QCoreApplication::translate("MainWindow", "username", nullptr));
        loginBtn->setText(QCoreApplication::translate("MainWindow", "Log In", nullptr));
        loginError->setText(QString());
        loginError->setStyleSheet(QCoreApplication::translate("MainWindow", "color: red;", nullptr));
        accHeader->setText(QCoreApplication::translate("MainWindow", "Available Accounts", nullptr));
        accHeader->setStyleSheet(QCoreApplication::translate("MainWindow", "font-weight: bold; color: #555;", nullptr));
        accFood->setText(QCoreApplication::translate("MainWindow", "Food Vendors: haashir, ali, saad, syed", nullptr));
        accFood->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #777; font-size: 11px;", nullptr));
        accArtisan->setText(QCoreApplication::translate("MainWindow", "Artisan Vendors: tanveer, sohail, ahmed, dana", nullptr));
        accArtisan->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #777; font-size: 11px;", nullptr));
        accOther->setText(QCoreApplication::translate("MainWindow", "Operator: operator  |  Admin: admin", nullptr));
        accOther->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #777; font-size: 11px;", nullptr));
        menuTitle->setText(QCoreApplication::translate("MainWindow", "Vendor Menu", nullptr));
        menuTitle->setStyleSheet(QCoreApplication::translate("MainWindow", "font-size: 20px; font-weight: bold;", nullptr));
        welcomeMsg->setStyleSheet(QCoreApplication::translate("MainWindow", "font-size: 13px; color: #444;", nullptr));
        vendorTypeLabel->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #666;", nullptr));
        logoutBtn->setText(QCoreApplication::translate("MainWindow", "Log Out", nullptr));
        browseBtn->setText(QCoreApplication::translate("MainWindow", "Browse Market Schedule", nullptr));
        browseBtn->setStyleSheet(QCoreApplication::translate("MainWindow", "font-size: 15px; font-weight: bold;", nullptr));
        dashBtn->setText(QCoreApplication::translate("MainWindow", "View Vendor Dashboard", nullptr));
        dashBtn->setStyleSheet(QCoreApplication::translate("MainWindow", "font-size: 15px; font-weight: bold;", nullptr));
        schedTitle->setText(QCoreApplication::translate("MainWindow", "Market Schedule", nullptr));
        schedTitle->setStyleSheet(QCoreApplication::translate("MainWindow", "font-size: 20px; font-weight: bold;", nullptr));
        schedHint->setText(QCoreApplication::translate("MainWindow", "Select a date to book a stall or join the waitlist.", nullptr));
        schedHint->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #555;", nullptr));
        backScheduleBtn->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        QTableWidgetItem *___qtablewidgetitem = schedTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Market Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = schedTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Food Available", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = schedTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Artisan Available", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = schedTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Food Status", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = schedTable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Artisan Status", nullptr));
        bookBtn->setText(QCoreApplication::translate("MainWindow", "Book Stall", nullptr));
        bookBtn->setStyleSheet(QCoreApplication::translate("MainWindow", "font-weight: bold;", nullptr));
        waitlistBtn->setText(QCoreApplication::translate("MainWindow", "Join Waitlist", nullptr));
        waitlistBtn->setStyleSheet(QCoreApplication::translate("MainWindow", "font-weight: bold;", nullptr));
        dashTitle->setText(QCoreApplication::translate("MainWindow", "Vendor Dashboard", nullptr));
        dashTitle->setStyleSheet(QCoreApplication::translate("MainWindow", "font-size: 20px; font-weight: bold;", nullptr));
        backDashBtn->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        bizHeader->setText(QCoreApplication::translate("MainWindow", "Business Information", nullptr));
        bizHeader->setStyleSheet(QCoreApplication::translate("MainWindow", "font-weight: bold; font-size: 12px;", nullptr));
        bizInfo->setStyleSheet(QCoreApplication::translate("MainWindow", "font-size: 11px; color: #333;", nullptr));
        compHeader->setText(QCoreApplication::translate("MainWindow", "Compliance Documentation", nullptr));
        compHeader->setStyleSheet(QCoreApplication::translate("MainWindow", "font-weight: bold; font-size: 12px;", nullptr));
        compInfo->setStyleSheet(QCoreApplication::translate("MainWindow", "font-size: 11px; color: #333;", nullptr));
        bookHeader->setText(QCoreApplication::translate("MainWindow", "Active Stall Bookings", nullptr));
        bookHeader->setStyleSheet(QCoreApplication::translate("MainWindow", "font-weight: bold; font-size: 12px;", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = bookTable->horizontalHeaderItem(0);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = bookTable->horizontalHeaderItem(1);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "Category", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = bookTable->horizontalHeaderItem(2);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "Booked At", nullptr));
        cancelBookBtn->setText(QCoreApplication::translate("MainWindow", "Cancel Booking", nullptr));
        waitHeader->setText(QCoreApplication::translate("MainWindow", "Waitlist Positions", nullptr));
        waitHeader->setStyleSheet(QCoreApplication::translate("MainWindow", "font-weight: bold; font-size: 12px;", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = waitTable->horizontalHeaderItem(0);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = waitTable->horizontalHeaderItem(1);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "Category", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = waitTable->horizontalHeaderItem(2);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "Position", nullptr));
        leaveWaitBtn->setText(QCoreApplication::translate("MainWindow", "Leave Waitlist", nullptr));
        notifHeader->setText(QCoreApplication::translate("MainWindow", "Notifications", nullptr));
        notifHeader->setStyleSheet(QCoreApplication::translate("MainWindow", "font-weight: bold; font-size: 12px;", nullptr));
        notifList->setStyleSheet(QCoreApplication::translate("MainWindow", "font-size: 11px;", nullptr));
        opTitle->setText(QCoreApplication::translate("MainWindow", "Market Operator Dashboard", nullptr));
        opTitle->setStyleSheet(QCoreApplication::translate("MainWindow", "font-size: 20px; font-weight: bold;", nullptr));
        opLogout->setText(QCoreApplication::translate("MainWindow", "Log Out", nullptr));
        opVendorLabel->setText(QCoreApplication::translate("MainWindow", "Select Vendor:", nullptr));
        opVendorLabel->setStyleSheet(QCoreApplication::translate("MainWindow", "font-weight: bold;", nullptr));
        opSchedHeader->setText(QCoreApplication::translate("MainWindow", "Market Schedule", nullptr));
        opSchedHeader->setStyleSheet(QCoreApplication::translate("MainWindow", "font-weight: bold; font-size: 12px;", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = opSchedTable->horizontalHeaderItem(0);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("MainWindow", "Market Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = opSchedTable->horizontalHeaderItem(1);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("MainWindow", "Food Available", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = opSchedTable->horizontalHeaderItem(2);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("MainWindow", "Artisan Available", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = opSchedTable->horizontalHeaderItem(3);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("MainWindow", "Food Status", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = opSchedTable->horizontalHeaderItem(4);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("MainWindow", "Artisan Status", nullptr));
        opBookBtn->setText(QCoreApplication::translate("MainWindow", "Book Stall for Vendor", nullptr));
        opBookBtn->setStyleSheet(QCoreApplication::translate("MainWindow", "font-weight: bold;", nullptr));
        opBookHeader->setText(QCoreApplication::translate("MainWindow", "Vendor's Active Bookings", nullptr));
        opBookHeader->setStyleSheet(QCoreApplication::translate("MainWindow", "font-weight: bold; font-size: 12px;", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = opBookTable->horizontalHeaderItem(0);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("MainWindow", "Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = opBookTable->horizontalHeaderItem(1);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("MainWindow", "Category", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = opBookTable->horizontalHeaderItem(2);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("MainWindow", "Booked At", nullptr));
        opCancelBtn->setText(QCoreApplication::translate("MainWindow", "Cancel Booking", nullptr));
        opCancelBtn->setStyleSheet(QCoreApplication::translate("MainWindow", "font-weight: bold;", nullptr));
        opWaitHeader->setText(QCoreApplication::translate("MainWindow", "Vendor's Waitlist Positions", nullptr));
        opWaitHeader->setStyleSheet(QCoreApplication::translate("MainWindow", "font-weight: bold; font-size: 12px;", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = opWaitTable->horizontalHeaderItem(0);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("MainWindow", "Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = opWaitTable->horizontalHeaderItem(1);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("MainWindow", "Category", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = opWaitTable->horizontalHeaderItem(2);
        ___qtablewidgetitem21->setText(QCoreApplication::translate("MainWindow", "Position", nullptr));
        opRemoveWaitBtn->setText(QCoreApplication::translate("MainWindow", "Remove from Waitlist", nullptr));
        opRemoveWaitBtn->setStyleSheet(QCoreApplication::translate("MainWindow", "font-weight: bold;", nullptr));
        opMsg->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #555;", nullptr));
        adminTitle->setText(QCoreApplication::translate("MainWindow", "System Administrator", nullptr));
        adminTitle->setStyleSheet(QCoreApplication::translate("MainWindow", "font-size: 20px; font-weight: bold;", nullptr));
        adminLogout->setText(QCoreApplication::translate("MainWindow", "Log Out", nullptr));
        adminMsg->setText(QCoreApplication::translate("MainWindow", "Admin features coming in a future deliverable.", nullptr));
        adminMsg->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #666;", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

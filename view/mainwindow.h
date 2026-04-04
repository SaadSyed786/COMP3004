#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "datamanager.h"
#include "loginhandler.h"
#include "bookinghandler.h"
#include "waitlisthandler.h"
#include "schedulehandler.h"
#include "dashboardhandler.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_loginBtn_clicked();
    void on_logoutBtn_clicked();
    void on_browseBtn_clicked();
    void on_dashBtn_clicked();
    void on_backScheduleBtn_clicked();
    void on_backDashBtn_clicked();
    void on_bookBtn_clicked();
    void on_waitlistBtn_clicked();
    void on_cancelBookBtn_clicked();
    void on_leaveWaitBtn_clicked();

    void onScheduleRowSelected(int row);

    // market operator actions
    void on_opBookBtn_clicked();
    void on_opCancelBtn_clicked();
    void on_opRemoveWaitBtn_clicked();
    void on_opVendorCombo_currentIndexChanged(int idx);

private:
    Ui::MainWindow *ui;
    DataManager*      dataMgr;
    LoginHandler*     loginCtrl;
    BookingHandler*   bookingCtrl;
    WaitlistHandler*  waitlistCtrl;
    ScheduleHandler*  scheduleCtrl;
    DashboardHandler* dashboardCtrl;
    QString activeUser;

    void showLoginPage();
    void showVendorMenu();
    void showSchedulePage();
    void showDashboard();
    void populateScheduleTable();
    void populateDashboard();

    void setupOperatorPage();
    void fillOpScheduleTable();
    void fillOpBookingTable();
    void fillOpWaitlistTable();
};

#endif

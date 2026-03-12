QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

TARGET = HintonMarket

INCLUDEPATH += model controller view service

SOURCES += \
    main.cpp \
    model/user.cpp \
    model/vendor.cpp \
    model/foodvendor.cpp \
    model/artisanvendor.cpp \
    model/marketoperator.cpp \
    model/sysadmin.cpp \
    model/compliancedoc.cpp \
    model/marketdate.cpp \
    model/marketschedule.cpp \
    model/stallbooking.cpp \
    model/waitlist.cpp \
    model/notification.cpp \
    service/datamanager.cpp \
    controller/loginhandler.cpp \
    controller/bookinghandler.cpp \
    controller/waitlisthandler.cpp \
    controller/schedulehandler.cpp \
    controller/dashboardhandler.cpp \
    view/mainwindow.cpp

HEADERS += \
    model/user.h \
    model/vendor.h \
    model/foodvendor.h \
    model/artisanvendor.h \
    model/marketoperator.h \
    model/sysadmin.h \
    model/compliancedoc.h \
    model/marketdate.h \
    model/marketschedule.h \
    model/stallbooking.h \
    model/waitlist.h \
    model/notification.h \
    service/datamanager.h \
    controller/loginhandler.h \
    controller/bookinghandler.h \
    controller/waitlisthandler.h \
    controller/schedulehandler.h \
    controller/dashboardhandler.h \
    view/mainwindow.h

FORMS += \
    view/mainwindow.ui

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

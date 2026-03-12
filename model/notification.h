#ifndef NOTIFICATION_H
#define NOTIFICATION_H
#include <QString>
#include <QDateTime>

class Notification {
public:
    enum Type { BookingConfirmed, BookingCancelled, WaitlistAlert, Info };
    Notification(QString msg, Type t = Info);
    QString getMessage();
    Type getType();
    QDateTime getTime();

private:
    QString msg;
    Type type;
    QDateTime time;
};

#endif

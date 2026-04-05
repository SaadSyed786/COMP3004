#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <QString>
#include <QDateTime>

class Notification
{
public:
    enum Type { BookingConfirmed, BookingCancelled, WaitlistAlert, Info };
    Notification(QString message, Type type = Info);
    QString getMessage();
    Type getType();
    QDateTime getTime();

private:
    QString message;
    Type type;
    QDateTime createdAt;
};

#endif

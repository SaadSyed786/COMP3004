#include "notification.h"

Notification::Notification(QString msg, Type t)
    : msg(msg), type(t), time(QDateTime::currentDateTime()) {}

QString Notification::getMessage() { return msg; }
Notification::Type Notification::getType() { return type; }
QDateTime Notification::getTime() { return time; }

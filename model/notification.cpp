#include "notification.h"

Notification::Notification(QString message, Type type)
    : message(message), type(type), createdAt(QDateTime::currentDateTime()) {}

QString   Notification::getMessage() { return message; }
Notification::Type Notification::getType() { return type; }
QDateTime Notification::getTime()    { return createdAt; }

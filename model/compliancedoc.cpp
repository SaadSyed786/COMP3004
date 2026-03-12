#include "compliancedoc.h"

ComplianceDoc::ComplianceDoc(QString type, QString number, QDate expiry, QString provider)
    : type(type), number(number), expiry(expiry), provider(provider) {}

QString ComplianceDoc::getType() { return type; }
QString ComplianceDoc::getNumber() { return number; }
QDate ComplianceDoc::getExpiry() { return expiry; }
QString ComplianceDoc::getProvider() { return provider; }

bool ComplianceDoc::validForSeason() {
    QDate endOfSeason(2026, 9, 27);
    return expiry > endOfSeason;
}

#include "compliancedoc.h"

ComplianceDoc::ComplianceDoc(QString docType, QString docNum, QDate expiryDate, QString insuranceProvider)
    : docType(docType), docNum(docNum), expiryDate(expiryDate), insuranceProvider(insuranceProvider) {}

QString ComplianceDoc::getType()     { return docType; }
QString ComplianceDoc::getNumber()   { return docNum; }
QDate   ComplianceDoc::getExpiry()   { return expiryDate; }
QString ComplianceDoc::getProvider() { return insuranceProvider; }

bool ComplianceDoc::validForSeason()
{
    // last market day of the season is the last sunday of September 2026
    QDate seasonEnd(2026, 9, 27);
    return (expiryDate > seasonEnd);
}

#include "compliancedoc.h"

ComplianceDoc::ComplianceDoc(QString docType, QString docNum, QDate expiryDate, QString insuranceProvider)
    : docType(docType), docNum(docNum), expiryDate(expiryDate), insuranceProvider(insuranceProvider) {}

QString ComplianceDoc::getType()  { return docType; }
QString ComplianceDoc::getNumber() { return docNum; }
QDate   ComplianceDoc::getExpiry() { return expiryDate; }
QString ComplianceDoc::getProvider() { return insuranceProvider; }

bool ComplianceDoc::validForSeason()
{
    QDate seasonEnd(2026, 9, 27);
    return (expiryDate > seasonEnd);
}

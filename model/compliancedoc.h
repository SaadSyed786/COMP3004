#ifndef COMPLIANCEDOC_H
#define COMPLIANCEDOC_H

#include <QString>
#include <QDate>

class ComplianceDoc
{
public:
    ComplianceDoc(QString docType, QString docNum, QDate expiryDate, QString insuranceProvider = "");

    QString getType();
    QString getNumber();
    QDate   getExpiry();
    QString getProvider();

    // checks whether the doc expires after the last market sunday (Sep 27, 2026)
    bool validForSeason();

private:
    QString docType;
    QString docNum;
    QDate   expiryDate;
    QString insuranceProvider;
};

#endif

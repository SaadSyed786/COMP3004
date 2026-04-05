#ifndef COMPLIANCEDOC_H
#define COMPLIANCEDOC_H
#include <QString>
#include <QDate>

class ComplianceDoc{
public:
    ComplianceDoc(QString docType, QString docNum, QDate expiryDate, QString insuranceProvider = "");
    QString getType();
    QString getNumber();
    QDate getExpiry();
    QString getProvider();

    // checking expiry 
    bool validForSeason();

private:
    QString docType;
    QString docNum;
    QDate expiryDate;
    QString insuranceProvider;
};

#endif

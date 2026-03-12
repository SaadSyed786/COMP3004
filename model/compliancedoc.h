#ifndef COMPLIANCEDOC_H
#define COMPLIANCEDOC_H
#include <QString>
#include <QDate>


class ComplianceDoc {
public:
    ComplianceDoc(QString type, QString number, QDate expiry, QString provider = "");

    QString getType();
    QString getNumber();
    QDate getExpiry();
    QString getProvider();
    bool validForSeason();  

private:
    QString type;
    QString number;
    QDate expiry;
    QString provider;
};

#endif

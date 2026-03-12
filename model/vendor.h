#ifndef VENDOR_H
#define VENDOR_H

#include "user.h"
#include "compliancedoc.h"
#include <QVector>


class Vendor : public User {
public:
    enum Category { Food, Artisan };

    Vendor(QString uname, QString ownerName, QString bizName,
           Category cat, QString email, QString phone, QString addr);
           
    virtual ~Vendor();

    QString getBusinessName();
    Category getCategory();
    QString getCategoryStr();
    QString getEmail();
    QString getPhone();
    QString getMailingAddress();
    void addDocument(ComplianceDoc doc);
    QVector<ComplianceDoc>& getDocuments();
    virtual bool hasRequiredDocs() = 0;
    virtual bool isCompliant() = 0;

protected:
    QString bizName;
    Category category;
    QString email;
    QString phone;
    QString mailingAddr;
    QVector<ComplianceDoc> documents;
};

#endif

#ifndef VENDOR_H
#define VENDOR_H

#include "user.h"
#include "compliancedoc.h"
#include <QVector>

class Vendor : public User
{
public:
    enum Category { Food, Artisan };

    Vendor(QString uname, QString ownerName, QString businessName,
           Category cat, QString email, QString phone, QString mailingAddress);
    virtual ~Vendor();

    QString  getBusinessName();
    Category getCategory();
    QString  getCategoryStr();
    QString  getEmail();
    QString  getPhone();
    QString  getMailingAddress();

    void addDocument(ComplianceDoc doc);
    QVector<ComplianceDoc>& getDocuments();

    virtual bool hasRequiredDocs() = 0;
    virtual bool isCompliant()     = 0;

protected:
    QString  businessName;
    Category category;
    QString  email;
    QString  phone;
    QString  mailingAddress;
    QVector<ComplianceDoc> documents;
};

#endif

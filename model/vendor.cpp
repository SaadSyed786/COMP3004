#include "vendor.h"

Vendor::Vendor(QString uname, QString ownerName, QString businessName,
               Category cat, QString email, QString phone, QString mailingAddress)
    : User(uname, ownerName, User::VendorRole),
      businessName(businessName), category(cat),
      email(email), phone(phone), mailingAddress(mailingAddress) {}

Vendor::~Vendor() {}

QString  Vendor::getBusinessName()    { return businessName; }
Vendor::Category Vendor::getCategory(){ return category; }
QString  Vendor::getCategoryStr()     { return (category == Food) ? "Food" : "Artisan"; }
QString  Vendor::getEmail()           { return email; }
QString  Vendor::getPhone()           { return phone; }
QString  Vendor::getMailingAddress()  { return mailingAddress; }

void Vendor::addDocument(ComplianceDoc doc) { documents.append(doc); }
QVector<ComplianceDoc>& Vendor::getDocuments() { return documents; }

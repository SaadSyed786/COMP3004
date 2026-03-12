#include "vendor.h"

Vendor::Vendor(QString uname, QString ownerName, QString bizName,
               Category cat, QString email, QString phone, QString addr)
    : User(uname, ownerName, User::VendorRole),
      bizName(bizName), category(cat), email(email),
      phone(phone), mailingAddr(addr) {}

Vendor::~Vendor() {}

QString Vendor::getBusinessName() { return bizName; }
Vendor::Category Vendor::getCategory() { return category; }
QString Vendor::getCategoryStr() { return category == Food ? "Food" : "Artisan"; }
QString Vendor::getEmail() { return email; }
QString Vendor::getPhone() { return phone; }
QString Vendor::getMailingAddress() { return mailingAddr; }
void Vendor::addDocument(ComplianceDoc doc) { documents.push_back(doc); }
QVector<ComplianceDoc>& Vendor::getDocuments() { return documents; }

#ifndef FOODVENDOR_H
#define FOODVENDOR_H

#include "vendor.h"

class FoodVendor : public Vendor
{
public:
    FoodVendor(QString uname, QString ownerName, QString businessName,
               QString email, QString phone, QString mailingAddress);
    ~FoodVendor();
    bool hasRequiredDocs() override;
    bool isCompliant() override;
};

#endif

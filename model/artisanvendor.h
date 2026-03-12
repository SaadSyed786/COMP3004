#ifndef ARTISANVENDOR_H
#define ARTISANVENDOR_H
#include "vendor.h"

class ArtisanVendor : public Vendor {
public:
    ArtisanVendor(QString uname, QString ownerName, QString bizName,QString email, QString phone, QString addr);
    ~ArtisanVendor();
    bool hasRequiredDocs() override;
    bool isCompliant() override;
};

#endif

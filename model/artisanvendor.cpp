#include "artisanvendor.h"

ArtisanVendor::ArtisanVendor(QString uname, QString ownerName, QString bizName,QString email, QString phone, QString addr)
    : Vendor(uname, ownerName, bizName, Vendor::Artisan, email, phone, addr) {}

ArtisanVendor::~ArtisanVendor() {}

bool ArtisanVendor::hasRequiredDocs() {
    // two requried docs only
    bool licence = false, insurance = false;
    for (int i = 0; i < documents.size(); i++) {
        QString t = documents[i].getType();
        if (t == "Business Licence") licence = true;
        if (t == "Liability Insurance") insurance = true;
    }
    return licence && insurance;
}

bool ArtisanVendor::isCompliant() {
    if (!hasRequiredDocs()) return false;
    for (int i = 0; i < documents.size(); i++) {
        if (!documents[i].validForSeason()) return false;
    }
    return true;
}

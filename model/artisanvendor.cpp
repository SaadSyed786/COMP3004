#include "artisanvendor.h"

ArtisanVendor::ArtisanVendor(QString uname, QString ownerName, QString businessName,QString email, QString phone, QString mailingAddress): Vendor(uname, ownerName, businessName, Vendor::Artisan, email, phone, mailingAddress) {}
ArtisanVendor::~ArtisanVendor() {}
bool ArtisanVendor::hasRequiredDocs(){
    // artisan vendors 2 docs only
    bool hasLicence = false;
    bool hasInsurance = false;
    for (int i = 0; i < documents.size(); i++) {
        if (documents[i].getType() == "Business Licence"){ hasLicence = true;}
        if (documents[i].getType() == "Liability Insurance") {hasInsurance = true;}
    }
    return (hasLicence && hasInsurance);
}

bool ArtisanVendor::isCompliant(){
    if (!hasRequiredDocs()){return false;}
    for (int i = 0; i < documents.size(); i++) {
        if (!documents[i].validForSeason()) {return false;}
    }
    return true;
}

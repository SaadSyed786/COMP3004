#include "foodvendor.h"

FoodVendor::FoodVendor(QString uname, QString ownerName, QString businessName, QString email, QString phone, QString mailingAddress)
    : Vendor(uname, ownerName, businessName, Vendor::Food, email, phone, mailingAddress) {}

FoodVendor::~FoodVendor() {}

bool FoodVendor::hasRequiredDocs()
{
    // food vendors require 3 docs
    bool hasLicence = false;
    bool hasInsurance = false;
    bool hasFoodHandler = false;
    for (int i = 0; i < documents.size(); i++) {
        if (documents[i].getType() == "Business Licence") hasLicence = true;
        if (documents[i].getType() == "Liability Insurance") hasInsurance = true;
        if (documents[i].getType() == "Food Handler Certification") hasFoodHandler = true;
    }
    return (hasLicence && hasInsurance && hasFoodHandler);
}

bool FoodVendor::isCompliant(){
    if (!hasRequiredDocs()) return false;
    // all docs need  be valid for the entire season
    for (int i = 0; i < documents.size(); i++) {
        if (!documents[i].validForSeason())
            return false;
    }
    return true;
}

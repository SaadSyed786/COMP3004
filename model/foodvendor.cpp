#include "foodvendor.h"

FoodVendor::FoodVendor(QString uname, QString ownerName, QString bizName,
                       QString email, QString phone, QString addr)
    : Vendor(uname, ownerName, bizName, Vendor::Food, email, phone, addr) {}

FoodVendor::~FoodVendor() {}

bool FoodVendor::hasRequiredDocs() {
    // validated if food vendor has requried documents
    bool licence = false, insurance = false, foodHandler = false;
    for (int i = 0; i < documents.size(); i++) {
        QString t = documents[i].getType();
        if (t == "Business Licence") licence = true;
        if (t == "Liability Insurance") insurance = true;
        if (t == "Food Handler Certification") foodHandler = true;
    }
    return licence && insurance && foodHandler;
}

bool FoodVendor::isCompliant() {
    if (!hasRequiredDocs()) return false;
    for (int i = 0; i < documents.size(); i++) {
        if (!documents[i].validForSeason()) return false;
    }
    return true;
}

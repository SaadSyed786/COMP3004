#include "marketdate.h"

MarketDate::MarketDate(QDate date, int maxFood, int maxArtisan)
    : date(date), maxFood(maxFood), maxArtisan(maxArtisan),
      numFoodBooked(0), numArtisanBooked(0) {}

QDate MarketDate::getDate() { return date; }
QString MarketDate::getDateStr() { return date.toString("yyyy-MM-dd"); }
int MarketDate::maxFoodStalls() { return maxFood; }
int MarketDate::maxArtisanStalls() { return maxArtisan; }
int MarketDate::availableFood() { return maxFood - numFoodBooked; }
int MarketDate::availableArtisan() { return maxArtisan - numArtisanBooked; }
int MarketDate::bookedFood() { return numFoodBooked; }
int MarketDate::bookedArtisan() { return numArtisanBooked; }
bool MarketDate::foodFull() { return numFoodBooked >= maxFood; }
bool MarketDate::artisanFull() { return numArtisanBooked >= maxArtisan; }
bool MarketDate::bookFood() {
    if (numFoodBooked < maxFood) { numFoodBooked++; return true; }
    return false;
}
bool MarketDate::bookArtisan() {
    if (numArtisanBooked < maxArtisan) { numArtisanBooked++; return true; }
    return false;
}

void MarketDate::releaseFood() { if (numFoodBooked > 0) numFoodBooked--; }
void MarketDate::releaseArtisan() { if (numArtisanBooked > 0) numArtisanBooked--; }

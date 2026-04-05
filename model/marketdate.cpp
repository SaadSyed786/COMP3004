#include "marketdate.h"

MarketDate::MarketDate(QDate date, int maxFoodStalls, int maxArtisanStalls)
    : date(date), foodMax(maxFoodStalls), artisanMax(maxArtisanStalls),
      foodBooked(0), artisanBooked(0) {}

QDate MarketDate::getDate() { return date; }
QString MarketDate::getDateStr() { return date.toString("yyyy-MM-dd"); }
int MarketDate::maxFoodStalls() { return foodMax; }
int MarketDate::maxArtisanStalls(){ return artisanMax; }
int MarketDate::availableFood() { return foodMax - foodBooked; }
int MarketDate::availableArtisan(){ return artisanMax - artisanBooked; }
int MarketDate::bookedFood() { return foodBooked; }
int MarketDate::bookedArtisan() { return artisanBooked; }
bool MarketDate::foodFull() { return foodBooked >= foodMax; }
bool MarketDate::artisanFull() { return artisanBooked >= artisanMax; }

bool MarketDate::bookFood(){
    if (foodBooked < foodMax) {
        foodBooked++;
        return true;
    }
    return false;
}

bool MarketDate::bookArtisan(){
    if (artisanBooked < artisanMax) {
        artisanBooked++;
        return true;
    }
    return false;
}

void MarketDate::releaseFood() { if (foodBooked > 0) foodBooked--; }
void MarketDate::releaseArtisan() { if (artisanBooked > 0) artisanBooked--; }

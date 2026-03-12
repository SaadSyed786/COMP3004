#ifndef MARKETOPERATOR_H
#define MARKETOPERATOR_H
#include "user.h"

class MarketOperator : public User {
public:
    MarketOperator(QString uname, QString name);
    ~MarketOperator();
};
#endif

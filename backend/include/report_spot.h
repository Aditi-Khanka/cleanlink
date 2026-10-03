#ifndef REPORT_SPOT_H
#define REPORT_SPOT_H

#include "waste_spot.h"
#include "city_hash.h"

class ReportSpot
{
private:
    CityHashTable cityTable;

public:
    void reportSpot();
};

#endif
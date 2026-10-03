#ifndef REVERSE_GEOCODE_H
#define REVERSE_GEOCODE_H

#include <string>

struct Location
{
    std::string cityName;
    std::string localityName;
};

Location reverseGeocode(double latitude, double longitude);

#endif
#ifndef CITY_HASH_H
#define CITY_HASH_H

#include <string>
using namespace std;

const int SIZE = 10;

struct City
{
    int id;
    string name;
};

class CityHashTable
{
private:
    City table[SIZE];
    int nextCityID;

public:
    CityHashTable();

    int hashFunction(string name);

    void insertCity(string name);

    int searchCity(string name);

    int getCityID(string name);

    void display();
};

#endif
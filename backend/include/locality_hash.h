#ifndef LOCALITY_HASH_H
#define LOCALITY_HASH_H

const int SIZE = 10;

// WasteSpot should be defined in your existing project
struct WasteSpot;

// Structure for one locality
struct Locality
{
    int id;
    char name[10];

    double minLat;
    double maxLat;
    double minLon;
    double maxLon;

    int localityScore;

    WasteSpot* spotHead;
};

// Locality Hash Table
class LocalityHashTable
{
private:
    Locality table[SIZE];
    int nextLocalityID;

    int hashFunction(const char name[]);

public:
    LocalityHashTable();

    int searchLocality(const char name[]);

    int insertLocality(
        const char name[],
        double minLat,
        double maxLat,
        double minLon,
        double maxLon
    );

    void displayLocalities();
};

#endif
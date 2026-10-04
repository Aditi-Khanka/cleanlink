#ifndef LOCALITY_HASH_H
#define LOCALITY_HASH_H

#include <string>
using namespace std;

const int SIZE = 10;

struct Locality
{
    int id;
    string name;
};

class LocalityHashTable
{
private:
    Locality table[SIZE];

public:
    int hashFunction(string name);
    void insertLocality(int id, string name);
    int searchLocality(string name);
    void display();
};

#endif
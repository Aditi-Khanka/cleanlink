#include <iostream>
#include "city_hash.h"

using namespace std;

CityHashTable::CityHashTable()
{
    nextCityID = 1;

    for(int i = 0; i < SIZE; i++)
    {
        table[i].id = 0;
        table[i].name = "";
    }
}

int CityHashTable::hashFunction(string name)
{
    int sum = 0;

    for(int i = 0; i < name.length(); i++)
        sum += name[i];

    return sum % SIZE;
}

void CityHashTable::insertCity(string name)
{
    // Check if city already exists
    if(searchCity(name) != -1)
    {
        cout << "City already exists: "
             << name << endl;
        return;
    }

    int index = hashFunction(name);

    while(table[index].id != 0)
    {
        index = (index + 1) % SIZE;
    }

    table[index].id = nextCityID;
    table[index].name = name;

    cout << "City added: "
         << name
         << " | ID: "
         << nextCityID
         << endl;

    nextCityID++;
}

int CityHashTable::searchCity(string name)
{
    int index = hashFunction(name);
    int startIndex = index;

    while(table[index].id != 0)
    {
        if(table[index].name == name)
            return index;

        index = (index + 1) % SIZE;

        // Prevent infinite loop if table is full
        if(index == startIndex)
            break;
    }

    return -1;
}

int CityHashTable::getCityID(string name)
{
    int index = searchCity(name);

    if(index != -1)
        return table[index].id;

    return -1;
}

void CityHashTable::display()
{
    cout << "\nCITY HASH TABLE\n";

    for(int i = 0; i < SIZE; i++)
    {
        if(table[i].id != 0)
        {
            cout << i << " : "
                 << table[i].id
                 << " - "
                 << table[i].name
                 << endl;
        }
    }
}
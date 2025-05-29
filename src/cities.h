#ifndef CITIES_H
#define CITIES_H

#include <stddef.h>

// Struct containing data for a city.
typedef struct {
    char *name;
    size_t population;
    double area;
    struct {
        size_t publicTransportation;
        size_t personalTransportation;
    } transportation;
} City;

// Struct containing a dynamic array of cities.
typedef struct {
    City *array;
    size_t count;
    size_t capacity;
} Cities;

// Adds a city to the given cities array.
void addCity(Cities *cities, City city);
// Deletes a city at a given index in the cities array.
void deleteCity(Cities *cities, size_t index);
// Renames a city given a new name and length.
void renameCity(City *city, char* newName, size_t length);

#endif
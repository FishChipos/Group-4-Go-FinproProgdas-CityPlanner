#ifndef CITIES_H
#define CITIES_H

#include <stddef.h>

// Struct containing data for a city.
typedef struct {
    // Pointer to city name.
    // Use renameCity() instead of editing this directly.
    char *name;

    // In people.
    size_t population;
    // In km^2.
    double area;
    // In L/day.
    double waterSupply;
    // In number of schools.
    size_t schools;
    // In number of hospitals.
    size_t hospitals;
    // Struct containing transportation data.
    struct {
        // In "units".
        size_t publicTransportation;

        // In "units".
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
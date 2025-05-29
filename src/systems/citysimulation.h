#ifndef CITYSIMULATION_H
#define CITYSIMULATION_H

#include <stddef.h>

#include "cities.h"

// Struct to store simulation results for each year
typedef struct {
    int year;
    size_t population;
} CitySimulationResult;

// Simulates a city and returns a pointer to the array of results.
// Rate of growth is growthRate%.
CitySimulationResult* simulateCity(const City *city, int years, int *resultCount, double growthRate);

#endif
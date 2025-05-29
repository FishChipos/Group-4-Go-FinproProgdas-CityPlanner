#include "citysimulation.h"

#include <stdlib.h>

CitySimulationResult* simulateCity(const City *city, int years, int *resultCount, double growthRate) {
    // If input is invalid then return null pointer.
    if (!city || years <= 0) {
        *resultCount = 0;
        return NULL;
    }

    // Allocate the array of results.
    CitySimulationResult *results = malloc(sizeof(CitySimulationResult) * years);
    
    // If allocation failed then return null pointer.
    if (!results) {
        *resultCount = 0;
        return NULL;
    }

    // Calculate the new population every year.
    double population = (double)city->population;
    for (int i = 0; i < years; i++) {
        population = population * (1.0 + growthRate / 100.0);
        results[i].year = i + 1;
        results[i].population = (size_t)population;
    }

    // Also set the user given result count pointer.
    if (resultCount != NULL) *resultCount = years;

    // Return the array of results.
    return results;
}
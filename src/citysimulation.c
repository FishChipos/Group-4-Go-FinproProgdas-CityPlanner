#include "citysimulation.h"
#include <stdlib.h>

CitySimulationResult* simulateCity(const City *city, int years, int *resultCount, double growthRate) {
    if (!city || years <= 0) {
        *resultCount = 0;
        return NULL;
    }

    CitySimulationResult *results = malloc(sizeof(CitySimulationResult) * years);
    if (!results) {
        *resultCount = 0;
        return NULL;
    }

    size_t population = city->population;
    for (int i = 0; i < years; i++) {
        population = (size_t)(population * (1.0 + growthRate / 100.0));
        results[i].year = i + 1;
        results[i].population = population;
    }
    *resultCount = years;
    return results;
}
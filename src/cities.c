#include "cities.h"

#include <stdlib.h>

void addCity(Cities *cities, City city) {
    if (cities->capacity <= 0) {
        cities->capacity = 4;
        cities->array = calloc(cities->capacity, sizeof(City));
    }
    else if (cities->count == cities->capacity) {
        cities->array = realloc(cities->array, cities->capacity * 2 * sizeof(City));
    }

    cities->array[cities->count] = city;
    cities->count++;
}

void deleteCity(Cities *cities, size_t index) {
    if (index < 0 || index >= cities->count) {
        return;
    }

    cities->count--;

    for (size_t city = index; city < cities->count; city++) {
        cities->array[city] = cities->array[city + 1];
    }
}

void createAddCity(Cities *cities, char *name) {
    City city = {
        .name = name
    };

    addCity(cities, city);
}
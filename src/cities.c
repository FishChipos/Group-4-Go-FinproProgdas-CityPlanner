#include "cities.h"

#include <stdlib.h>
#include <string.h>

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

void createAddCity(Cities *cities, char name[128]) {
    City city = { 0 };
    strcpy_s(city.name, 128 * sizeof(char), name);

    addCity(cities, city);
}

void renameCity(City *city, char* newName, size_t length) {
    if (city->name == NULL) {
        city->name = calloc(length, sizeof(char));
    }
    else {
        city->name = realloc(city->name, length * sizeof(char));
    }

    strncpy(city->name, newName, length);
}
#include "cities.h"

#include <stdlib.h>
#include <string.h>

void addCity(Cities *cities, City city) {
    // If the cities array has not yet been allocated, do so.
    if (cities->capacity <= 0) {
        // Initial capacity is 4.
        cities->capacity = 4;
        cities->array = calloc(cities->capacity, sizeof(City));
    }
    // If array is at capacity, double its capacity.
    else if (cities->count == cities->capacity) {
        cities->array = realloc(cities->array, cities->capacity * 2 * sizeof(City));
    }

    // Set the new city.
    cities->array[cities->count] = city;

    // Increment internal city counter.
    cities->count++;
}

void deleteCity(Cities *cities, size_t index) {
    // If index is invalid, return.
    if (index < 0 || index >= cities->count) {
        return;
    }

    // Decrement internal city counter.
    cities->count--;

    // Move all city elements ahead of the deleted city one spot back.
    for (size_t city = index; city < cities->count; city++) {
        cities->array[city] = cities->array[city + 1];
    }
}

void renameCity(City *city, char* newName, size_t length) {
    // If no name has been assigned yet, allocate memory.
    if (city->name == NULL) {
        city->name = calloc(length, sizeof(char));
    }
    // If there is an existing name, reallocate the memory.
    else {
        city->name = realloc(city->name, length * sizeof(char));
    }

    // Copy the desired new name into the name field.
    strncpy(city->name, newName, length);
}
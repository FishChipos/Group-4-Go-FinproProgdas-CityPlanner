#ifndef CITIES_H
#define CITIES_H

#include <stddef.h>

typedef struct {
    char *name;
} City;

typedef struct {
    City *array;
    size_t count;
    size_t capacity;
} Cities;

void addCity(Cities *cities, City city);
void deleteCity(Cities *cities, size_t index);

void createAddCity(Cities *cities, char *name);

#endif
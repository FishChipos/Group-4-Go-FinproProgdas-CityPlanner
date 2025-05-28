#ifndef CITYEVALUATION_H
#define CITYEVALUATION_H

#include <stddef.h>

// Calculates the population density in a given area.
double calculatePopulationDensity(double area, size_t population);

// Calculates the density score for a city.
double scorePopulationDensity(double area, size_t population);

// Calculates the public transportation score for a city.
double scorePublicTransportation(double publicTrans, size_t population);

// Calculates the personal transportation score for a city.
double scorePersonalTransportation(double personalTrans, size_t population);

// Calculates the water score for a city.
double scoreWater(double supply, double consum);

// Calculates the education availability score for a city.
double scoreEducation(size_t unit, double population);

// Calculates the healthcare availability score for a city.
double scoreHospital(size_t unit, double population);

#endif

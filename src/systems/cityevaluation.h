#ifndef CITYEVALUATION_H
#define CITYEVALUATION_H

#include <stddef.h>

// Calculates the density score for a city.
// Also writes the population density to the supplied pointer.
double scorePopulationDensity(double area, size_t population, double *userPopulationDensity);

// Calculates the public transportation score for a city.
// Also writes the number of people per public transportation unit to the supplied pointer.
double scorePublicTransportation(double publicTrans, size_t population, double *userPeoplePerPublicTransportationUnit);

// Calculates the personal transportation score for a city.
// Also writes the number of people per personal transportation unit to the supplied pointer.
double scorePersonalTransportation(double personalTrans, size_t population, double *userPeoplePerPersonalTransportationUnit);

// Calculates the water score for a city.
// Also writes the ratio of water supply to consumption to the supplied pointer.
double scoreWaterSupply(double supply, double consumption, double *userRatioWaterSupplyToConsumption);

// Calculates the education availability score for a city.
// Also the writes the number of people per school to the supplied pointer.
double scoreEducation(size_t unit, double population, double *userPeoplePerSchool);

// Calculates the healthcare availability score for a city.
// Also writes the number of people per hospital to the supplied pointer.
double scoreHealthcare(size_t unit, double population, double *userPeoplePerHospital);

#endif

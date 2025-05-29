#ifndef CITYEVALUATION_H
#define CITYEVALUATION_H

#include <stddef.h>

// Calculates the density score for a city.
double scorePopulationDensity(double area, size_t population, double *userPopulationDensity);

// Calculates the public transportation score for a city.
double scorePublicTransportation(double publicTrans, size_t population, double *userPeoplePerPublicTransportationUnit);

// Calculates the personal transportation score for a city.
double scorePersonalTransportation(double personalTrans, size_t population, double *userPeoplePerPersonalTransportationUnit);

// Calculates the water score for a city.
double scoreWaterSupply(double supply, double consumption, double *userRatioWaterSupplyToConsumption);

// Calculates the education availability score for a city.
double scoreEducation(size_t unit, double population, double *userPeoplePerSchool);

// Calculates the healthcare availability score for a city.
double scoreHealthcare(size_t unit, double population, double *userPeoplePerHospital);

#endif

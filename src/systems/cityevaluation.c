#include "cityevaluation.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// Clamps a value between lower bound and upper bound and returns the result.
double clampDouble(double value, double lowerBound, double upperBound) {
    if (value > upperBound) return upperBound;
    else if (value < lowerBound) return lowerBound;
    else return value;
}

double scorePopulationDensity(double area, size_t population, double *userPopulationDensity) {
    // If area or population is less than equal to 0 return 0.
    if (population <= 0 || area <= 0) return 0;

    double populationDensity = (double)population / area;
    
    // Calculate population density score.
    double score = 100 - 25 * (populationDensity / 2000 - 1);

    score = clampDouble(score, 0, 100);
    
    if (userPopulationDensity != NULL) *userPopulationDensity = populationDensity;
    return score;
}

double scorePublicTransportation(double publicTransportationUnits, size_t population, double *userPeoplePerPublicTransportationUnit) {
    // If publicTransportationUnits or population is less than equal to 0 return 0.
    if (population <= 0 || publicTransportationUnits <= 0) return 0;
    
    double peoplePerPublicTransportationUnit = population / publicTransportationUnits;

    // Calculate Public Transportation score.
    double score = 100 - 25 * log2(peoplePerPublicTransportationUnit / 100);

    score = clampDouble(score, 0, 100);
    
    if (userPeoplePerPublicTransportationUnit != NULL) *userPeoplePerPublicTransportationUnit = peoplePerPublicTransportationUnit;
    return score;
}

double scorePersonalTransportation(double personalTransportationUnits, size_t population, double *userPeoplePerPersonalTransportationUnit) {
    // If personalTransportationUnits or population is less than equal to 0 return 0.
    if (population <= 0 || personalTransportationUnits <= 0) return 0;
    
    double peoplePerPersonalTransportationUnit = population / personalTransportationUnits;

    // Calculate Personal Transportation score.
    double score = 25 * (log2(peoplePerPersonalTransportationUnit) - 1);

    score = clampDouble(score, 0, 100);
    
    if (userPeoplePerPersonalTransportationUnit != NULL) *userPeoplePerPersonalTransportationUnit = peoplePerPersonalTransportationUnit;
    return score;
}

double scoreWaterSupply(double waterSupply, double waterConsumption, double *userWaterSupplyToConsumptionRatio) {
    // If supply or consum is less than equal to 0 return 0.
    if (waterSupply <= 0 || waterConsumption <= 0) return 0;
    
    double waterSupplyToConsumptionRatio = waterSupply / waterConsumption;

    // Calculate water score.
    double score = waterSupplyToConsumptionRatio * 100 - 20;

    score = clampDouble(score, 0, 100);

    if (userWaterSupplyToConsumptionRatio != NULL) *userWaterSupplyToConsumptionRatio = waterSupplyToConsumptionRatio;
    return score;
}

double scoreEducation(size_t schools, double population, double *userPeoplePerSchool) {
    // If unit or population is less than equal to 0 return 0.
    if (schools <= 0 || population <= 0) return 0;

    double peoplePerSchool = population / schools;
    
    // Calculate education availability score.
    double score = 100 - 25 *  (peoplePerSchool / 1000 - 1);

    score = clampDouble(score, 0, 100);

    if (userPeoplePerSchool != NULL) *userPeoplePerSchool = peoplePerSchool;
    return score;
}

double scoreHealthcare(size_t hospitals, double population, double *userPeoplePerHospital) {
    // If unit or population is less than equal to 0 return 0.
    if (hospitals <= 0 || population <= 0) return 0;

    double peoplePerHospital = population / (double)hospitals;
    
    // Calculate healthcare availability score.
    double score = 100 - 25 * (pow(1.01,peoplePerHospital - 200) - 1);

    score = clampDouble(score, 0, 100);

    if (userPeoplePerHospital != NULL) *userPeoplePerHospital = peoplePerHospital;
    return score;
}


#include "pages.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#include "../systems/cityevaluation.h"

void pageCityEvaluation(City *city) {
    bool pageShouldClose = false;

    // In the future, probably figure out a cleaner way to do this,
    // Likely by splitting calculation and output into two different functions.

    // Calculate water consumption.
    double waterConsumption = city->population * 100;

    // Necessary figures to output.
    double populationDensity;
    double peoplePerPublicTransportationUnit;
    double peoplePerPersonalTransportationUnit;
    double waterSupplyToConsumptionRatio;
    double peoplePerSchool;
    double peoplePerHospital;

    // Calculate scores and store them in this struct.
    struct {
        double populationDensity;
        double publicTransportation;
        double personalTransportation;
        double waterSupply;
        double education;
        double healthcare;
    } scores = {
        .populationDensity = scorePopulationDensity(city->area, city->population, &populationDensity),
        .publicTransportation = scorePublicTransportation(city->transportation.publicTransportation, city->population, &peoplePerPublicTransportationUnit),
        .personalTransportation = scorePersonalTransportation(city->transportation.personalTransportation, city->population, &peoplePerPersonalTransportationUnit),
        .waterSupply = scoreWaterSupply(city->waterSupply, waterConsumption, &waterSupplyToConsumptionRatio),
        .education = scoreEducation(city->schools, city->population, &peoplePerSchool),
        .healthcare = scoreHealthcare(city->hospitals, city->population, &peoplePerHospital)
    };

    // Calculate the average score.
    double averageScore = 0;
    size_t scoreCount = 0;

    for (double *ptrScore = &scores.populationDensity; ptrScore <= &scores.healthcare; ptrScore++) {
        averageScore += *ptrScore;
        scoreCount++;
    }

    averageScore /= scoreCount;
    
    while (!pageShouldClose) {
        enum {
            BACK = 1,
        } choice = -1;

        system("clear");

        // Print UI including evaluation results.
        printf("\033[1m--- CITY - EVALUATION ---\033[0m\n");

        printCityData(city);
    
        printf("\nCity Population Density: %.2f people/km^2\n", populationDensity);
        printf("Score: %.2f\n\n", scores.populationDensity);

        printf("People per public transportation unit: %.2f\n", peoplePerPublicTransportationUnit);
        printf("Score: %.2f\n\n", scores.publicTransportation);

        printf("People per personal transportation unit: %.2f\n", peoplePerPersonalTransportationUnit);
        printf("Score: %.2f\n\n", scores.personalTransportation);
        
        printf("Water consumption per day: %.0f L\n", waterConsumption);
        printf("Ratio of supply to consumption per day: %.2f%%\n", waterSupplyToConsumptionRatio * 100);
        printf("Score: %.2f\n\n", scores.waterSupply);

        printf("People per school: %.2f\n", peoplePerSchool);
        printf("Score: %.2f\n\n", scores.education);
        
        printf("People per hospital: %.2f\n", peoplePerHospital);
        printf("Score: %.2f\n\n", scores.healthcare);

        printf("Average Score: %.2f\n", averageScore);

        // Print city quality.
        printf("City Quality: \033[1m");
        if (averageScore >= 75) {
            printf("\033[34mGREAT");
        }
        else if (averageScore >= 50) {
            printf("\033[32mGOOD");
        }
        else if (averageScore >= 25) {
            printf("\033[33mPASSING");
        }
        else {
            printf("\033[31mPOOR");
        }
        puts("\033[0m\n");

        puts("\033[91m1. Back\033[0m\n");

        printf("%s", "\033[2mChoice: \033[0m");
        char buffer[128];

        // Get user input.
        fgets(buffer, 128, stdin);
        sscanf(buffer, "%d", (int*)&choice);

        puts("");
        switch (choice) {
            case BACK:
                pageShouldClose = true;
                break;
            default:
                promptInvalidInput();
                break;
        }
    }    
}

#include "pages.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#include "../cityevaluation.h"

void pageCityEvaluation(App *app, City *city) {
    bool pageShouldClose = false;

    // Calculate the population density for this city.
    double populationDensity = calculatePopulationDensity(city->area, city->population);

    while (!pageShouldClose) {
        enum {
            BACK = 1,
        } choice = -1;

        system("clear");

        // Print UI including evaluation results.
        printf("\033[1m--- CITY - EVALUATION ---\033[0m\n");
    
        printf("City Population Density: %.2f people/km^2\n", populationDensity);
        printf("Score: %.2f%\n\n", scorePopulationDensity(city->area, city->population));

        printf("People per public transportation: %.2f\n", city->population/city->transportation.publicTransportation);
        printf("Score: %.2f%\n\n", scorePublicTransportation(city->transportation.publicTransportation, city->population));

        printf("People per personal transportation: %.2f\n", city->population/city->transportation.personalTransportation);
        printf("Score: %.2f%\n\n", scorePersonalTransportation(city->transportation.personalTransportation, city->population));
        
        printf("Consumption: %.2f L\n", city->population*100);
        printf("Rasio of supply to consumption: %.2f%\n", city->waterSupply/(city->population*100)*100);
        printf("Score: %.2f%\n\n", scoreWater(city->waterSupply, city->population*100));

        printf("People per school: %.2f\n", city->population/city->education);
        printf("Score: %.2f%\n\n", scoreEducation(city->education, city->population));
        
        printf("People per hospital: %.2f\n", city->population/city->hospital);
        printf("Score: %.2f%\n\n", scoreHospital(city->hospital, city->population));

        puts("");
        puts("1. Back\n");

        printf("%s", "Choice: ");
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

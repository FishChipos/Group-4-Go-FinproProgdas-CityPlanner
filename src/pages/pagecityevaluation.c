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
    
        printf("City Population Density: %f\n", populationDensity);
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

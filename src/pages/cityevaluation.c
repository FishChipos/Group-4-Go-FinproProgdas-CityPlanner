#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include "pages.h"

typedef struct {
    float area;
    unsigned long long population;
} City;

int calculateDensity(float area, unsigned long long population) {
    if (area <= 0) return 0;

    float density = population / area;

    if (density <= 1000) return 100;
    else if (density <= 3000) return 75;
    else if (density <= 5000) return 50;
    else return 25;
}

void pageCityEvaluation(App *app, City *city) {
    bool pageShouldClose = false;

    while (!pageShouldClose) {
        printf("\nCity Evaluation\n");

        int score = calculateDensity(city->area, city->population);

        printf("City Density: %d\n", score);

        }    

    }

#include "pages.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#include "../cityevaluation.h"

int pageCityEvaluation(App *app, City *city) {
    bool pageShouldClose = false;

    while (!pageShouldClose) {
        printf("\nCity Evaluation\n");

        int score = calculateDensity(city->area, city->population);

        printf("City Density: %d\n", score);

        }    

    }

#include "pages.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#include "../cityevaluation.h"

void pageCityEvaluation(App *app, City *city) {
    bool pageShouldClose = false;

    while (!pageShouldClose) {
        enum {
            BACK = 1,
        } choice = -1;

        system("clear");
    
        printf("\nCity Evaluation\n");
        puts("");
    
        int score = calculateDensity(city->area, city->population);

        printf("City Density: %d\n", score);
        puts("");
        puts("1. Back\n");

        printf("%s", "Choice: ");
        char buffer[128];
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

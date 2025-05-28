#include "pages.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printCityData(App *app, City *city) {
    printf("\033[1;5;33m%s\033[0m\n", city->name);
    printf("%-15s: %llu %s\n", "Population", city->population, city->population == 1 ? "person" : "people");
    printf("%-15s: %.2lf m^2\n", "Area", city->area);
    printf("%-15s: %llu\n", "Transportation", city->transportation.personalTransportation + city->transportation.publicTransportation);
}

void pageCityTransportation(App *app, City *city) {
    bool pageShouldClose = false;

    while (!pageShouldClose) {
        enum {
            BACK = 1,
            PUBLIC,
            PERSONAL
        } choice = -1;

        system("clear");

        puts("\033[1m--- CITY - TRANSPORTATION ---\033[0m");
        printCityData(app, city);

        puts("");
        
        printf("%-15s: %llu\n", "Public", city->transportation.publicTransportation);
        printf("%-15s: %llu\n", "Personal", city->transportation.personalTransportation);

        puts("");

        puts("1. Back\n");
        puts("2. Public");
        puts("3. Personal\n");

        printf("%s", "Choice: ");
        char buffer[128];
        fgets(buffer, 128, stdin);
        sscanf(buffer, "%d", (int*)&choice);

        puts("");
        
        switch (choice) {
            case BACK:
                pageShouldClose = true;
                break;
            case PUBLIC:
                printf("%s", "Enter number of vehicles: ");
                fgets(buffer, 128, stdin);
                sscanf(buffer, "%llu", &city->transportation.publicTransportation);
                break;
            case PERSONAL:
                printf("%s", "Enter number of vehicles: ");
                fgets(buffer, 128, stdin);
                sscanf(buffer, "%llu", &city->transportation.personalTransportation);
                break;
            default:
                promptInvalidInput();
                break;
        }
    }

}

void pageCity(App *app, City *city) {
    bool pageShouldClose = false;

    while (!pageShouldClose) {
        enum {
            BACK = 1,
            RENAME = 2,
            EVALUATION = 3,
            SIMULATION = 4,
            POPULATION = 5,
            AREA = 6,
            TRANSPORT = 7,
        } choice = -1;

        system("clear");

        puts("\033[1m--- CITY ---\033[0m");
        printCityData(app, city);

        puts("");

        puts("1. Back\n");

        puts("\033[1mCITY ACTIONS\033[0m");
        puts("2. Rename City");
        puts("3. Evaluate City");
        puts("4. Simulate City\n");

        puts("\033[1mCITY DATA\033[0m");
        puts("Choose a category to view and edit data");
        puts("5. Population");
        puts("6. Area");
        puts("7. Transportation\n");

        printf("%s", "Choice: ");
        char buffer[128];
        fgets(buffer, 128, stdin);
        sscanf(buffer, "%d", (int*)&choice);

        puts("");
        
        switch (choice) {
            case BACK:
                pageShouldClose = true;
                break;
            case RENAME:
                printf("%s", "Enter city name: ");
                fgets(buffer, 128, stdin);
                buffer[strcspn(buffer, "\n\r")] = '\0';
                renameCity(city, buffer, 128);
                break;
            case EVALUATION:
                pageCityEvaluation(app, city);
                break;
            case SIMULATION:
                pageCitySimulation(app, city);
                break;
            case POPULATION:
                printf("%s", "Enter city population: ");
                fgets(buffer, 128, stdin);
                sscanf(buffer, "%llu", &city->population);
                break;
            case AREA:
                printf("%s", "Enter city area: ");
                fgets(buffer, 128, stdin);
                sscanf(buffer, "%lf", &city->area);
                break;
            case TRANSPORT:
                pageCityTransportation(app, city);
                break;
            default:
                promptInvalidInput();
                break;
        }
    }
}

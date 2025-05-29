#include "pages.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prints the overall data for a city.
void printCityData(City *city) {
    printf("\033[1;5;92m%s\033[0m\n", city->name);
    printf("%-15s: %llu %s\n", "Population", city->population, city->population == 1 ? "person" : "people");
    printf("%-15s: %.2lf km^2\n", "Area", city->area);
    printf("%-15s: %llu units\n", "Transportation", city->transportation.personalTransportation + city->transportation.publicTransportation);
    printf("%-15s: %.2lf L\n", "Water Supply", city->waterSupply);
    printf("%-15s: %llu units\n", "Schools", city->schools);
    printf("%-15s: %llu units\n", "Hospitals", city->hospitals);
}

// Displays subpage for city transportation data.
void pageCityTransportation(City *city) {
    bool pageShouldClose = false;

    while (!pageShouldClose) {
        // Possible choices.
        enum {
            BACK = 1,
            PUBLIC,
            PERSONAL
        } choice = -1;

        system("clear");

        // Print UI.
        puts("\033[1m--- CITY - TRANSPORTATION ---\033[0m");
        printCityData(city);

        puts("");
        
        printf("%-15s: %llu\n", "Public", city->transportation.publicTransportation);
        printf("%-15s: %llu\n", "Personal", city->transportation.personalTransportation);

        puts("");

        puts("\033[91m1. Back\033[0m\n");
        puts("\033[1mTRANSPORTATION DATA\033[0m");
        puts("Choose a type of transportation to edit it.");
        puts("\033[94m2. Public");
        puts("3. Personal\033[0m\n");

        printf("%s", "\033[2mChoice: \033[0m");
        char buffer[128];
        fgets(buffer, 128, stdin);
        sscanf(buffer, "%d", (int*)&choice);

        puts("");
        
        switch (choice) {
            case BACK:
                pageShouldClose = true;
                break;
            case PUBLIC:
                // Change public transportation data.
                printf("%s", "Enter number of units: ");
                fgets(buffer, 128, stdin);
                sscanf(buffer, "%llu", &city->transportation.publicTransportation);
                break;
            case PERSONAL:
                // Change personal transportation data.
                printf("%s", "Enter number of units: ");
                fgets(buffer, 128, stdin);
                sscanf(buffer, "%llu", &city->transportation.personalTransportation);
                break;
            default:
                promptInvalidInput();
                break;
        }
    }

}

void pageCity(City *city) {
    bool pageShouldClose = false;

    while (!pageShouldClose) {
        // Possible choices.
        enum {
            BACK = 1,
            RENAME = 2,
            EVALUATION = 3,
            SIMULATION = 4,
            POPULATION = 5,
            AREA = 6,
            TRANSPORT = 7,
            WATER = 8,
            EDUCATION = 9,
            HOSPITAL = 10,
        } choice = -1;

        system("clear");

        // Print UI.
        puts("\033[1m--- CITY ---\033[0m");
        printCityData(city);

        puts("");

        puts("\033[91m1. Back\033[0m\n");

        puts("\033[1mCITY ACTIONS\033[0m");
        puts("\033[94m2. Rename City");
        puts("3. Evaluate City");
        puts("4. Simulate City\033[0m\n");

        puts("\033[1mCITY DATA\033[0m");
        puts("Choose a category to view and edit data");
        puts("\033[94m5. Population");
        puts("6. Area");
        puts("7. Transportation");
        puts("8. Water Supply");
        puts("9. Schools");
        puts("10. Hospitals\033[0m\n");

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
            case RENAME:
                // Rename the city after asking for a new one.
                printf("%s", "Enter new city name: ");
                fgets(buffer, 128, stdin);
                buffer[strcspn(buffer, "\n\r")] = '\0';
                renameCity(city, buffer, 128);
                break;
            case EVALUATION:
                // Navigate to the evaluation page for this city.
                pageCityEvaluation(city);
                break;
            case SIMULATION:
                // Navigate to the simulation page for this city.
                pageCitySimulation(city);
                break;
            case POPULATION:
                // Ask for new population.
                printf("%s", "Enter city population: ");
                fgets(buffer, 128, stdin);
                sscanf(buffer, "%llu", &city->population);
                break;
            case AREA:
                // Ask for new area.
                printf("%s", "Enter city area (in km^2): ");
                fgets(buffer, 128, stdin);
                sscanf(buffer, "%lf", &city->area);
                break;
            case TRANSPORT:
                // Navigate to the transportation subpage for this city.
                pageCityTransportation(city);
                break;
            case WATER:
                // Ask for new water supply.
                printf("%s", "Enter water supply (in L/day): ");
                fgets(buffer, 128, stdin);
                sscanf(buffer, "%lf", &city->waterSupply);
                break;
            case EDUCATION:
                // Ask for new education availability building.
                printf("%s", "Enter number of schools: ");
                fgets(buffer, 128, stdin);
                sscanf(buffer, "%llu", &city->schools);
                break;
            case HOSPITAL:
                // Ask for new healthcare availability building.
                printf("%s", "Enter number of hospitals: ");
                fgets(buffer, 128, stdin);
                sscanf(buffer, "%llu", &city->hospitals);
                break;
            default:
                // Invalid input.
                promptInvalidInput();
                break;
        }
    }
}

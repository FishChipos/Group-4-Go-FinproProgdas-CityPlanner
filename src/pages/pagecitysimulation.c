#include "pages.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "../systems/citysimulation.h"

void pageCitySimulation(App *app, City *city) {
    bool pageClosed = false;
    int choice;
    char buffer[128];

    // If city data is incomplete then return.
    if (city->name == NULL || city->population == 0 || city->area <= 0) {
        printf("\nCity data is incomplete.\n");
        promptInvalidInput();
        return;
    }
    
    while (!pageClosed) {
        system("clear");

        // Print UI.
        printf("\033[1m--- CITY - SIMULATION ---\033[0m\n");
        printf("\033[91m1. Back\033[0m\n\n");
        printf("\033[94m2. Simulate City\n");
        printf("3. View logs\033[0m\n\n");
        printf("\033[2mChoice: \033[0m");

        fgets(buffer, 128, stdin);
        sscanf(buffer, "%d", (int*)&choice);

        switch (choice) {
            // Go back.
            case 1:
                pageClosed = true;
                break;
            // Simulate city.
            case 2: {
                int years = 0;
                double growthRate = 0.0;
                printf("How many years you want to simulate: ");
                if (scanf("%d", &years) != 1 || years <= 0) {
                    printf("Invalid year input.\n");
                    while (getchar() != '\n');
                    break;
                }
                while (getchar() != '\n');

                printf("Enter population growth rate (in percent, e.g. 2 for 2%%): ");
                if (scanf("%lf", &growthRate) != 1) {
                    printf("Invalid growth rate input.\n");
                    while (getchar() != '\n');
                    break;
                }
                while (getchar() != '\n');

                int resultCount = 0;
                CitySimulationResult *results = simulateCity(city, years, &resultCount, growthRate);

                if (!results) {
                    printf("Simulation failed.\n");
                    break;
                }

                printf("\nPopulation:\n");
                for (int i = 0; i < resultCount; i++) {
                    printf("Year %d: Population = %zu\n", results[i].year, results[i].population);
                }

                //Save results confirmation
                char save;
                printf("\nSave it to log? (y/n): ");
                scanf(" %c", &save);
                while (getchar() != '\n');
                if (save == 'y' || save == 'Y') {

                    //Count existing logs
                    int logsCount = 0;
                    FILE *logFile = fopen("simulation_logs.txt", "r");
                    if (logFile) {
                        char line[256];
                        while (fgets(line, sizeof(line), logFile)) {
                            if (strncmp(line, "Simulation", 10) == 0) {
                                logsCount++;
                            }
                        }
                        fclose(logFile);
                    }
                    logsCount++;
                    
                    //Save results to file
                    FILE *f = fopen("simulation_logs.txt", "a");
                    if (f) {
                        fprintf(f, "Simulation %d for %s:\n", logsCount, city->name);
                        for (int i = 0; i < resultCount; i++) {
                            fprintf(f, "Year %d: Population = %zu\n", results[i].year, results[i].population);
                        }
                        fprintf(f, "\n");
                        fclose(f);
                        printf("Simulation saved.\n");
                    } else {
                        printf("Failed to save simulation.\n");
                    }
                }

                free(results);
                promptContinue();
                break;
            }
            // View simulation logs.
            case 3:
                printf("\nSimulation logs\n");
                FILE *f = fopen("simulation_logs.txt", "r");
                if (f) {
                    char line[256];
                    while (fgets(line, sizeof(line), f)) {
                        printf("%s", line);
                    }
                    fclose(f);
                } else {
                    printf("No simulation archive yet.\n");
                }
                promptContinue();
                break;
            default:
                printf("Invalid Choice.\n");
                promptInvalidInput();
                break;
        }
    }
}
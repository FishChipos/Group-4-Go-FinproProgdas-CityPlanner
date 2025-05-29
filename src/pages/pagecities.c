#include "pages.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>

void pageCities(App *app) {
    // Possible modes for the cities page.
    enum {
        MODE_NORMAL = 0,
        MODE_DUPLICATE,
        MODE_DELETE
    } mode = 0;

    bool pageShouldClose = false;

    // Input buffer.
    char buffer[128];

    while (!pageShouldClose) {
        // Choices for normal mode.
        enum {
            CHOICE_BACK = 1,
            CHOICE_ADD = 2,
            CHOICE_DUPLICATE = 3,
            CHOICE_DELETE = 4
        } choice = -1;

        // Choices for delete mode.
        enum {
            CHOICE_DELETE_EXIT = 1
        } choiceDelete = -1;

        // Choices for duplicate mode.
        enum {
            CHOICE_DUPLICATE_EXIT = 1
        } choiceDuplicate = -1;

        system("clear");

        switch (mode) {
            case MODE_NORMAL:
                // Print normal mode UI.
                puts("\033[1m--- CITIES ---\033[0m");
                puts("\033[91m1. Back\033[0m\n");

                puts("\033[1mACTIONS\033[0m");
                puts("\033[94m2. Add city");
                puts("3. Duplicate city");
                puts("4. Delete city\033[0m\n");
                
                puts("\033[1mYOUR CITIES\033[0m");
                if (app->cities.count <= 0) {
                    // No cities.
                    puts("No cities yet!\n");
                }
                else {
                    // Print city names.
                    puts("Choose a city to view it\033[94m");
                    for (size_t cityIndex = 0; cityIndex < app->cities.count; cityIndex++) {
                        printf("%llu. %s\n", cityIndex + 4 + 1, app->cities.array[cityIndex].name);
                    }
                    puts("\033[0m");
                }

                printf("\033[2mChoice: \033[0m");

                // Get user input.
                fgets(buffer, 128, stdin);
                sscanf(buffer, "%d", (int*)&choice);

                puts("");

                switch (choice) {
                    case CHOICE_BACK:
                        pageShouldClose = true;
                        break;
                    case CHOICE_ADD:
                        // Add a city and rename it according to user input.
                        addCity(&app->cities, (City) { 0 });

                        printf("%s", "Enter city name: ");

                        char cityName[128];
                        fgets(cityName, 128, stdin);
                        cityName[strcspn(cityName, "\n\r")] = '\0';

                        renameCity(&app->cities.array[app->cities.count - 1], cityName, 128);
                        break;
                    // Change modes.
                    case CHOICE_DUPLICATE:
                        mode = MODE_DUPLICATE;
                        break;
                    case CHOICE_DELETE:
                        mode = MODE_DELETE;
                        break;
                    default:
                        // If a city was chosen.
                        if (choice >= 5 && choice <= 5 + (unsigned int)app->cities.count - 1) {
                            pageCity(&app->cities.array[choice - 5]);
                        }
                        // Otherwise it's invalid input.
                        else {
                            promptInvalidInput();
                        }
                        break;
                }
                break;
            case MODE_DUPLICATE:
                // Print duplicate mode UI.
                puts("\033[1m--- CITIES ---\033[0m");
                puts("\033[91m1. Exit duplicate mode.\033[0m\n");

                if (app->cities.count > 0) {
                    puts("Choose a city to \033[1;34mDUPLICATE\033[0m it\033[94m");
                    for (size_t cityIndex = 0; cityIndex < app->cities.count; cityIndex++) {
                        printf("%llu. %s\n", cityIndex + 1 + 1, app->cities.array[cityIndex].name);
                    }
    
                    puts("\033[0m");
                }

                printf("\033[2mChoice: \033[0m");
                
                // Get user input.
                fgets(buffer, 128, stdin);
                if (buffer[0] != '\0') sscanf(buffer, "%d", (int*)&choiceDuplicate);

                switch (choiceDuplicate) {
                    case CHOICE_DUPLICATE_EXIT:
                        mode = MODE_NORMAL;
                        break;
                    default:
                        // If a city was chosen duplicate it.
                        if (choiceDuplicate >= 2 && choiceDuplicate < 2 + (unsigned int)app->cities.count) {
                            size_t cityIndex = choiceDuplicate - 2;
                            City copiedCity = app->cities.array[cityIndex];
                            addCity(&app->cities, copiedCity);
                        }
                        // Otherwise it's invalid input.
                        else {
                            promptInvalidInput();
                        }
                        break;
                }
                break;
            case MODE_DELETE:
                // Print delete mode UI.
                puts("\033[1m--- CITIES ---\033[0m");
                puts("\033[91m1. Exit delete mode.\033[0m\n");
                
                if (app->cities.count > 0) {
                    puts("Choose a city to \033[1;31mDELETE\033[0m it\033[94m");
                    for (size_t cityIndex = 0; cityIndex < app->cities.count; cityIndex++) {
                        printf("%llu. %s\n", cityIndex + 1 + 1, app->cities.array[cityIndex].name);
                    }
    
                    puts("\033[0m");
                }

                printf("\033[2mChoice: \033[0m");
                
                // Get user input.
                fgets(buffer, 128, stdin);
                sscanf(buffer, "%d", (int*)&choiceDelete);

                switch (choiceDelete) {
                    case CHOICE_DELETE_EXIT:
                        mode = MODE_NORMAL;
                        break;
                    default:
                        // If a city was chosen delete it.
                        if (choiceDelete >= 2 && choiceDelete < 2 + (unsigned int)app->cities.count) {
                            size_t cityIndex = choiceDelete - 2;
                            deleteCity(&app->cities, cityIndex);
                        }
                        // Otherwise it's invalid input.
                        else {
                            promptInvalidInput();
                        }
                        break;
                }
                break;
        }
        
    }
}
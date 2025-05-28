#include "pages.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>

void pageCities(App *app) {
    enum {
        MODE_NORMAL = 0,
        MODE_DUPLICATE,
        MODE_DELETE
    } mode = 0;

    bool pageShouldClose = false;

    char buffer[128];

    while (!pageShouldClose) {
        enum {
            CHOICE_BACK = 1,
            CHOICE_ADD = 2,
            CHOICE_DUPLICATE = 3,
            CHOICE_DELETE = 4
        } choice = -1;

        enum {
            CHOICE_DELETE_EXIT = 1
        } choiceDelete = -1;

        enum {
            CHOICE_DUPLICATE_EXIT = 1
        } choiceDuplicate = -1;

        system("clear");

        switch (mode) {
            case MODE_NORMAL:
                puts("\033[1m--- CITIES ---\033[0m");
                puts("1. Back\n");

                puts("\033[1mACTIONS\033[0m");
                puts("2. Add city");
                puts("3. Duplicate city");
                puts("4. Delete city\n");
                
                puts("\033[1mYOUR CITIES\033[0m");
                if (app->cities.count <= 0) {
                    puts("No cities yet!\n");
                }
                else {
                    puts("Choose a city to view it");
                    for (size_t cityIndex = 0; cityIndex < app->cities.count; cityIndex++) {
                        printf("%llu. %s\n", cityIndex + 4 + 1, app->cities.array[cityIndex].name);
                    }
                    puts("");
                }

                printf("Choice: ");

                fgets(buffer, 128, stdin);
                sscanf(buffer, "%d", (int*)&choice);

                puts("");

                switch (choice) {
                    case CHOICE_BACK:
                        pageShouldClose = true;
                        break;
                    case CHOICE_ADD:
                        addCity(&app->cities, (City) { 0 });

                        printf("%s", "Enter city name: ");

                        char cityName[128];
                        fgets(cityName, 128, stdin);
                        cityName[strcspn(cityName, "\n\r")] = '\0';

                        renameCity(&app->cities.array[app->cities.count - 1], cityName, 128);
                        break;
                    case CHOICE_DUPLICATE:
                        mode = MODE_DUPLICATE;
                        break;
                    case CHOICE_DELETE:
                        mode = MODE_DELETE;
                        break;
                    default:
                        if (choice >= 5 && choice <= 5 + (unsigned int)app->cities.count - 1) {
                            pageCity(app, &app->cities.array[choice - 5]);
                        }
                        else {
                            promptInvalidInput();
                        }
                        break;
                }
                break;
            case MODE_DUPLICATE:
                puts("\033[1m--- CITIES ---\033[0m");
                puts("1. Exit duplicate mode.\n");

                if (app->cities.count > 0) {
                    puts("Choose a city to \033[1;34mDUPLICATE\033[0m it");
                    for (size_t cityIndex = 0; cityIndex < app->cities.count; cityIndex++) {
                        printf("%llu. %s\n", cityIndex + 1 + 1, app->cities.array[cityIndex].name);
                    }
    
                    puts("");
                }

                printf("Choice: ");
                
                fgets(buffer, 128, stdin);
                if (buffer[0] != '\0') sscanf(buffer, "%d", (int*)&choiceDuplicate);

                switch (choiceDuplicate) {
                    case CHOICE_DUPLICATE_EXIT:
                        mode = MODE_NORMAL;
                        break;
                    default:
                        if (choiceDuplicate >= 2 && choiceDuplicate < 2 + (unsigned int)app->cities.count) {
                            size_t cityIndex = choiceDuplicate - 2;
                            // TODO: Make a copy function.
                            City copiedCity = app->cities.array[cityIndex];
                            addCity(&app->cities, copiedCity);
                        }
                        else {
                            promptInvalidInput();
                        }
                        break;
                }
                break;
            case MODE_DELETE:
                puts("\033[1m--- CITIES ---\033[0m");
                puts("1. Exit delete mode.\n");
                
                if (app->cities.count > 0) {
                    puts("Choose a city to \033[1;31mDELETE\033[0m it");
                    for (size_t cityIndex = 0; cityIndex < app->cities.count; cityIndex++) {
                        printf("%llu. %s\n", cityIndex + 1 + 1, app->cities.array[cityIndex].name);
                    }
    
                    puts("");
                }

                printf("Choice: ");
                
                fgets(buffer, 128, stdin);
                sscanf(buffer, "%d", (int*)&choiceDelete);

                switch (choiceDelete) {
                    case CHOICE_DELETE_EXIT:
                        mode = MODE_NORMAL;
                        break;
                    default:
                        if (choiceDelete >= 2 && choiceDelete < 2 + (unsigned int)app->cities.count) {
                            size_t cityIndex = choiceDelete - 2;
                            deleteCity(&app->cities, cityIndex);
                        }
                        else {
                            promptInvalidInput();
                        }
                        break;
                }
                break;
        }
        
    }
}
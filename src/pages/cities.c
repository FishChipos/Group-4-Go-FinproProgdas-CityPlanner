#include "pages.h"

#include <stdio.h>
#include <stdlib.h>

void pageCities(App *app) {
    enum {
        CHOICE_BACK = 1,
        CHOICE_ADD,
        CHOICE_DUPLICATE,
        CHOICE_DELETE
    } choice;

    enum {
        CHOICE_DELETE_EXIT = 1
    } choiceDelete;

    enum {
        CHOICE_DUPLICATE_EXIT = 1
    } choiceDuplicate;

    enum {
        MODE_NORMAL = 0,
        MODE_DUPLICATE,
        MODE_DELETE
    } mode;

    bool pageShouldClose = false;

    while (!pageShouldClose) {
        system("clear");

        switch (mode) {
            case MODE_NORMAL:
                puts("\033[1m--- CITIES ---\033[0m");
                puts("1. Back");
                puts("2. Add city");
                puts("3. Duplicate city");
                puts("4. Delete city\n");

                if (app->cities.count <= 0) {
                    puts("No cities yet!\n");
                }
                else {
                    for (size_t cityIndex = 0; cityIndex < app->cities.count; cityIndex++) {
                        printf("%llu. %s\n", cityIndex + 4 + 1, app->cities.array[cityIndex].name);
                    }
                    puts("");
                }

                printf("Choice: ");
                scanf("%d", (int*)&choice);

                switch (choice) {
                    case CHOICE_BACK:
                        pageShouldClose = true;
                        break;
                    case CHOICE_ADD:
                        addCity(&app->cities, (City) { 0 });

                        char cityName[128];
                        snprintf(cityName, 128, "City %llu", app->cities.count);

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
                            // Open city.
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
                    for (size_t cityIndex = 0; cityIndex < app->cities.count; cityIndex++) {
                        printf("%llu. %s\n", cityIndex + 1 + 1, app->cities.array[cityIndex].name);
                    }
    
                    puts("");
                }

                puts("MODE: \033[1;34mDUPLICATE\033[0m\n");

                printf("Choice: ");
                scanf("%d", (int*)&choiceDuplicate);

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
                    for (size_t cityIndex = 0; cityIndex < app->cities.count; cityIndex++) {
                        printf("%llu. %s\n", cityIndex + 1 + 1, app->cities.array[cityIndex].name);
                    }
    
                    puts("");
                }

                puts("MODE: \033[1;31mDELETE\033[0m\n");

                printf("Choice: ");
                scanf("%d", (int*)&choiceDelete);

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
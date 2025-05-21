#include "pages.h"

#include <stdio.h>

void pageCities(App *app) {
    enum : int {
        CHOICE_BACK = 1,
        CHOICE_ADD,
        CHOICE_DUPLICATE,
        CHOICE_DELETE
    } choice;

    bool pageShouldClose = false;

    while (!pageShouldClose) {
        puts("--- CITIES ---");
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

        scanf("%d", &choice);

        puts("");

        switch (choice) {
            case CHOICE_BACK:
                pageShouldClose = true;
                break;
            case CHOICE_ADD:
                break;
            case CHOICE_DUPLICATE:
                break;
            case CHOICE_DELETE:
                break;
            default:
                break;
        }
    }
}
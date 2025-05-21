#include "pages.h"

#include <stdio.h>
#include <stdlib.h>

void pageStart(App *app) {
    enum : int {
        CHOICE_START = 1,
        CHOICE_EXIT
    } choice;

    bool pageShouldClose = false;

    while (!pageShouldClose) {
        system("clear");

        puts("\033[1m=== CITY PLANNER ===\033[0m");
        puts("1. Start");
        puts("2. Exit\n");

        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case CHOICE_START:
                pageCities(app);
                break;
            case CHOICE_EXIT:
                app->shouldClose = true;
                pageShouldClose = true;
                break;
            default:
                promptInvalidInput();
                break;
        }
    }
}
#include "pages.h"

#include <stdio.h>

void pageStart(App *app) {
    enum : int {
        CHOICE_START = 1,
        CHOICE_EXIT
    } choice;

    bool pageShouldClose = false;

    while (!pageShouldClose) {
        puts("=== CITY PLANNER ===");
        puts("1. Start");
        puts("2. Exit\n");

        printf("Choice: ");

        scanf("%d", &choice);

        puts("");

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
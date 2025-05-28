#include "pages.h"

#include <stdio.h>
#include <stdlib.h>

void pageStart(App *app) {
    // Possible input choices.
    enum {
        CHOICE_START = 1,
        CHOICE_EXIT = 2
    } choice = -1;

    bool pageShouldClose = false;

    // Buffer for input.
    char buffer[128];

    // Page loop.
    while (!pageShouldClose) {
        system("clear");

        // Print UI.
        puts("\033[1m=== CITY PLANNER ===\033[0m");
        puts("1. Start");
        puts("2. Exit\n");

        printf("Choice: ");

        // Get user choice.
        fgets(buffer, 128, stdin);
        sscanf(buffer, "%d", (int*)&choice);

        switch (choice) {
            case CHOICE_START:
                // Navigate to the cities page.
                pageCities(app);
                break;
            case CHOICE_EXIT:
                // Close page and app.
                app->shouldClose = true;
                pageShouldClose = true;
                break;
            default:
                // Invalid input.
                promptInvalidInput();
                break;
        }
    }
}
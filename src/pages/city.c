#include "pages.h"

#include <stdio.h>
#include <stdlib.h>

void pageCity(App *app, City *city) {
    enum {
        CHOICE_BACK = 1
    } choice;

    bool pageShouldClose = false;

    while (!pageShouldClose) {
        system("clear");

        puts("\033[1mCITY\033[0m");
        printf("%-10s: %s\n", "Name", city->name);

        puts("");

        puts("1. Back\n");

        printf("%s", "Choice: ");
        scanf("%d", (int*)&choice);

        switch (choice) {
            case CHOICE_BACK:
                pageShouldClose = true;
                break;
            default:
                promptInvalidInput();
                break;
        }
    }
}
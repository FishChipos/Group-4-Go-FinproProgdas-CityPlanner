#include "pages.h"

#include <stdio.h>

void promptInvalidInput() {
    printf("%s", "Invalid input! Press ENTER to continue.");
    fflush(stdin);
    getchar();
}

void promptContinue() {
    printf("%s", "Press ENTER to continue.");
    fflush(stdin);
    getchar();
}
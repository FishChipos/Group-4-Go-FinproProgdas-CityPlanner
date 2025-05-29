#include "pages.h"

#include <stdio.h>

void promptInvalidInput() {
    printf("%s", "Invalid input! Press \033[1mENTER\033[0m to continue.");
    fflush(stdin);
    getchar();
}

void promptContinue() {
    printf("%s", "Press \033[1mENTER\033[0m to continue.");
    fflush(stdin);
    getchar();
}
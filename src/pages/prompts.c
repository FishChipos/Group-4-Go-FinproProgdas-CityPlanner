#include "pages.h"

#include <stdio.h>

void promptInvalidInput() {
    printf("%s", "Invalid input! Press ENTER to continue.");
    fflush(stdin);
    getchar();
}
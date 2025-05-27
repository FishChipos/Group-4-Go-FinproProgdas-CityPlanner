#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "app.h"
#include "pages/pages.h"

int main() {
    App app = { 0 };

    while (!app.shouldClose) {
        system("clear");
        pageStart(&app);
    }

    remove("simulation_logs.txt"); // Clean up log file on exit
    return 0;
}
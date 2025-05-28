#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "app.h"
#include "pages/pages.h"

int main() {
    // Instantiate the app state.
    App app = { 0 };

    // Main app loop.
    while (!app.shouldClose) {
        // Clear system every time the program restarts.
        system("clear");
        // Display start page.
        pageStart(&app);
    }

    // Clear terminal on exit.
    system("clear");

    // Clean up log file on exit
    remove("simulation_logs.txt");

    return 0;
}
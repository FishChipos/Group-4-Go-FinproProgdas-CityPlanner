// TODO: Figure out scrolling.

#include "pages.h"

#include <ncurses/ncurses.h>
#include <ctype.h>

#include "cities.h"
#include "window.h"
#include "app.h"

void infoPage(App *app) {
    if (app->terminalFlags != 0) {
        addstr("CITY PLANNER\n\n");

        if (app->terminalFlags & FLAG_TERMINAL_COLOR_UNSUPPORTED) {
            addstr("INFO: Color is not supported on this terminal.\n");
        }
        
        if (app->terminalFlags & FLAG_TERMINAL_COLOR_FIXED) {
            addstr("INFO: Color definitions are fixed on this terminal.\n");
        }

        addstr("\nPress anything to continue.");

        refresh();

        getch();
    }   

    app->page = PAGE_START;
}

void startMenuPage(App *app) {
    BorderedWindow borderedWindow = {
        .config = {
            .dimensions = {
                .height = 18,
                .width = 60
            },
            .origin = {
                .y = 1,
                .x = 4
            },   
            .borderColor = COLOR_WHITE
        }
    };

    createBorderedWindow(&borderedWindow);

    WINDOW *window = borderedWindow.contentWindow;

    bool pageShouldClose = FALSE;

    enum {
        CHOICE_START = 0,
        CHOICE_SETTINGS,
        CHOICE_EXIT
    } choice = 0;

    int inputChar = 0;

    do {
        // Clear the window.
        wclear(window);

        // Handle input.
        if (tolower(inputChar) == 'w') {
            if (choice == 0) {
                choice = CHOICE_EXIT;
            }
            else {
                choice--;
            }
        }
        else if (tolower(inputChar) == 's') {
            choice = (choice + 1) % 3;
        }
        else if (inputChar == '\n' || inputChar == '\r') {
            // Move to other pages.
            switch (choice) {
                case CHOICE_START:
                    app->page = PAGE_CITIES;
                    pageShouldClose = TRUE;
                    break;
                case CHOICE_SETTINGS:

                    pageShouldClose = TRUE;
                    break;
                case CHOICE_EXIT:
                    app->shouldClose = TRUE;
                    pageShouldClose = TRUE;
                    break;
            }
        }

        // Draw the page.
        mvwaddstr(window, 2, 4, "MAIN MENU");

        mvwaddstr(window, 4, 6, "Start");
        mvwaddstr(window, 5, 6, "Settings");
        mvwaddstr(window, 6, 6, "Exit");

        mvwaddstr(window, borderedWindow.config.dimensions.height - 2 - 2 - 1, 6, "Use W, A, S, D to navigate and ENTER to select");

        // Draw arrow and highlights.
        mvwaddch(window, 4 + choice, 4, '>');
        mvwchgat(window, 4 + choice, 4, -1, A_BOLD, 0, NULL);

        wrefresh(window);
    } while (!pageShouldClose && (inputChar = getch()));

    deleteBorderedWindow(&borderedWindow);
}

void citiesPage(App *app) {
    BorderedWindow borderedWindow = {
        .config = {
                .dimensions = {
                .height = 18,
                .width = 60
            },
            .origin = {
                .y = 1,
                .x = 4
            },
            .borderColor = COLOR_WHITE
        }
    };

    createBorderedWindow(&borderedWindow);
    WINDOW *window = borderedWindow.contentWindow;

    bool pageShouldClose = FALSE;

    enum {
        CHOICE_BACK = 0,
        CHOICE_ADD,
        CHOICE_DELETE
    } choice = 0;

    enum {
        MODE_NORMAL = 0,
        MODE_DELETE
    } mode = 0;

    int inputChar = 0;

    do {
        // Clear the window.
        wclear(window);

        // Handle input.
        if (tolower(inputChar) == 'w') {
            if (mode == MODE_DELETE) {
                if (choice <= CHOICE_DELETE + 1) {
                    choice = CHOICE_DELETE + app->cities.count;
                }
                else {
                    choice--;
                }
            }
            else {
                if (choice == 0) {
                    choice = CHOICE_DELETE + app->cities.count;
                }
                else {
                    choice--;
                }
            }
        }
        else if (tolower(inputChar) == 's') {

            if (mode == MODE_DELETE) {
                
                
                if (choice >= CHOICE_DELETE + app->cities.count) {
                    choice = CHOICE_DELETE + 1;
                }
                else {
                    choice++;
                } 
            }   
            else {
                if (choice >= CHOICE_DELETE + app->cities.count) {
                    choice = CHOICE_BACK;
                }
                else {
                    choice++;
                }
            }
        }
        else if (inputChar == '\n' || inputChar == '\r') {
            if (mode == MODE_DELETE) {
                size_t cityIndex = choice - CHOICE_DELETE - 1;

                // Snap the cursor to the nearest city available.
                if (cityIndex >= app->cities.count - 1) {
                    choice--;
                }

                deleteCity(&app->cities, cityIndex);
            }
            else {
                switch (choice) {
                    case CHOICE_BACK:
                        app->page = PAGE_START;
                        pageShouldClose = TRUE;
                        break;
                    case CHOICE_ADD:
                        createAddCity(&app->cities, "City");
                        snprintf(app->cities.array[app->cities.count - 1].name, 128, "City %lld", app->cities.count);

                        break;
                    case CHOICE_DELETE:
                        mode = MODE_DELETE;
                        choice = CHOICE_DELETE + 1;
                        break;
                    default:
                        // Open a city.
                        break;
                }
            }
        }

        if (mode == MODE_DELETE && tolower(inputChar) == 'q') {
            mode = MODE_NORMAL;
            choice = CHOICE_BACK;
        }

        // Draw the page.
        mvwaddstr(window, 2, 4, "CITIES");

        mvwaddstr(window, 4, 6, "Back");
        mvwaddstr(window, 5, 6, "Add City");
        mvwaddstr(window, 6, 6, "Delete City");

        if (app->cities.count == 0) {
            mvwaddstr(window, 8, 6, "No cities yet!");
        }
        else {
            for (size_t cityIndex = 0; cityIndex < app->cities.count; cityIndex++) {
                if (cityIndex >= 4) break;

                mvwprintw(window, 8 + cityIndex, 6, "%s", app->cities.array[cityIndex].name);
            }
        }

        // Draw controls for delete mode.
        if (mode == MODE_DELETE) {
            mvwaddstr(window, borderedWindow.config.dimensions.height - 2 - 2 - 1, 6, "Press Q to exit delete mode.");
        }
        
        // Draw arrow and highlights.
        if (mode == MODE_DELETE) {
            if (app->cities.count > 0) {
                init_pair(2, COLOR_RED, COLOR_BLACK);

                mvwaddch(window, 7 + (choice - CHOICE_DELETE), 4, '>');
                mvwchgat(window, 7 + (choice - CHOICE_DELETE), 4, -1, A_BOLD, 2, NULL);
            }
        }
        else {
            if (choice > CHOICE_DELETE) {
                mvwaddch(window, 7 + (choice - CHOICE_DELETE), 4, '>');
                mvwchgat(window, 7 + (choice - CHOICE_DELETE), 4, -1, A_BOLD, 0, NULL);
            }
            else {
                mvwaddch(window, 4 + choice, 4, '>');
                mvwchgat(window, 4 + choice, 4, -1, A_BOLD, 0, NULL);
            }
        }

        wrefresh(window);
    } while (!pageShouldClose && (inputChar = getch()));
}

void cityPage(City *city) {
    // TO BE FINISHED
}

void settingsPage(App *app) {
    // TO BE FINISHED
}
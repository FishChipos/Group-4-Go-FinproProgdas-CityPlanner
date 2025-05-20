#include "pages.h"

#include <ncurses/ncurses.h>
#include <ctype.h>

#include "window.h"

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
    typedef enum {
        CHOICE_START = 0,
        CHOICE_SETTINGS,
        CHOICE_EXIT
    } Choice;

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

    Choice choice = 0;
    int inputChar = 0;

    do {
        wclear(window);
        // Input handling.
        // W for up.
        if (tolower(inputChar) == 'w') {
            if (choice == 0) {
                choice = CHOICE_EXIT;
            }
            else {
                choice--;
            }
        }
        
        // S for down.
        if (tolower(inputChar) == 's') {
            choice = (choice + 1) % 3;
        }

        // Enter key.
        if (inputChar == '\n') {
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

        mvwaddstr(window, 2, 4, "MAIN MENU");

        mvwaddstr(window, 4, 6, "Start");
        mvwaddstr(window, 5, 6, "Settings");
        mvwaddstr(window, 6, 6, "Exit");

        mvwaddstr(window, 8, 6, "Use W, A, S, D to navigate and ENTER to select");

        // Draw arrow and highlights.
        mvwaddch(window, 4 + choice, 4, '>');
        mvwchgat(window, 4 + choice, 4, -1, A_BOLD, 0, NULL);

        wrefresh(window);
    } while (!pageShouldClose && (inputChar = getch()));

    deleteBorderedWindow(&borderedWindow);
}

void citiesPage(App *app) {
    typedef enum {
        CHOICE_BACK = 0,
        CHOICE_ADD,
        CHOICE_DELETE,
    } Choice;

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

    Choice choice = 0;
    int inputChar = 0;

    do {
        wclear(window);
        // Input handling.
        if (tolower(inputChar) == 'w') {
            if (choice == 0) {
                choice = CHOICE_DELETE + app->cities.count;
            }
            else {
                choice--;
            }
        }

        if (tolower(inputChar) == 's') {
            choice = (choice + 1) % (CHOICE_DELETE + app->cities.count + 1);
        }

        if (inputChar == '\n') {
            if (choice > CHOICE_DELETE) {
                // Do something.
            }
            else {
                switch (choice) {
                    case CHOICE_BACK:
                        app->page = PAGE_START;
                        pageShouldClose = TRUE;
                        break;
                    case CHOICE_ADD:
                        break;
                    case CHOICE_DELETE:
                        break;
                }
            }
        }

        mvwaddstr(window, 2, 4, "CITIES");

        mvwaddstr(window, 4, 6, "Back");
        mvwaddstr(window, 5, 6, "Add City");
        mvwaddstr(window, 6, 6, "Delete City");

        if (app->cities.count == 0) {
            mvwaddstr(window, 8, 6, "No cities yet!");
        }
        else {
            for (size_t cityIndex = 0; cityIndex < app->cities.count; cityIndex++) {
                mvwprintw(window, 8 + cityIndex, 6, "%s", app->cities.array[cityIndex].name);
            }
        }
        
        // Draw arrow and highlights.
        if (choice > CHOICE_DELETE) {
            mvwaddch(window, 8 + (choice - CHOICE_DELETE), 4, '>');
            mvwchgat(window, 8 + (choice - CHOICE_DELETE), 4, -1, A_BOLD, 0, NULL);
        }
        else {
            mvwaddch(window, 4 + choice, 4, '>');
            mvwchgat(window, 4 + choice, 4, -1, A_BOLD, 0, NULL);
        }

        wrefresh(window);
    } while (!pageShouldClose && (inputChar = getch()));
}

void settingsPage(App *app) {

}
#include "pages.h"

#include <ncurses/ncurses.h>
#include <ctype.h>

#include "window.h"

void infoPage(App *app) {
    if (app->terminalFlags != 0) {
        printw("CITY PLANNER\n\n");

        if (app->terminalFlags & FLAG_TERMINAL_COLOR_UNSUPPORTED) {
            printw("INFO: Color is not supported on this terminal.\n");
        }
        
        if (app->terminalFlags & FLAG_TERMINAL_COLOR_FIXED) {
            printw("INFO: Color definitions are fixed on this terminal.\n");
        }

        printw("\nPress anything to continue.");

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
    } CHOICE;

    const WindowConfig config = {
        .dimensions = {
            .height = 18,
            .width = 60
        },
        .padding = {
            .top = 1,
            .left = 4
        },
        .borderColor = COLOR_WHITE
    };

    WINDOW *window = createWindow(config);
    bool windowShouldClose = FALSE;

    mvwprintw(window, 2, 4, "MAIN MENU");
    mvwprintw(window, 4, 6, "Start");
    mvwprintw(window, 5, 6, "Settings");
    mvwprintw(window, 6, 6, "Exit");

    mvwprintw(window, 8, 6, "Use W, A, S, D to navigate and ENTER to select");

    wrefresh(window);

    CHOICE choice = CHOICE_START;

    int c = 0;

    do {
        // Remove the cursor from last iteration.
        mvwprintw(window, 4 + choice, 4, " ");

        // Arrow keys emit \033, [, and then A for up arrow and B for down arrow.
        if (tolower(c) == 'w') {
            if (choice == CHOICE_START) {
                choice = CHOICE_EXIT;
            }
            else {
                choice--;
            }
        }
        else if (tolower(c) == 's') {
            choice = (choice + 1) % 3;
        }
        // Enter key.
        else if (c == '\n') {
            // Move to other pages.
            switch (choice) {
                case CHOICE_START:

                    windowShouldClose = TRUE;
                    break;
                case CHOICE_SETTINGS:

                    windowShouldClose = TRUE;
                    break;
                case CHOICE_EXIT:
                    windowShouldClose = TRUE;
                    app->shouldClose = TRUE;
                    break;
            }
        }

        // Print a cursor for the selected choice.
        wattron(window, COLOR_PAIR(1));
        mvwprintw(window, 4 + choice, 4, ">");
        wattroff(window, COLOR_PAIR(1));

        wrefresh(window);
    } while (!windowShouldClose && (c = getch()));

    deleteWindow(window);
}

void settingsPage(App *app) {

}
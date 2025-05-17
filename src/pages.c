#include "pages.h"

#include <ncurses/ncurses.h>

#include "window.h"

void infoPage(Settings *settings, TerminalFlags *flags) {
    if (*flags != 0) {
        printw("CITY PLANNER\n\n");

        if (*flags & FLAG_TERMINAL_COLOR_UNSUPPORTED) {
            printw("INFO: Color is not supported on this terminal.\n");
        }
        
        if (*flags & FLAG_TERMINAL_COLOR_FIXED) {
            printw("INFO: Color definitions are fixed on this terminal.\n");
        }

        printw("\nPress anything to continue.");

        refresh();

        getch();
    }   
}

void startMenuPage(Settings *settings) {
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
        .borderColor = COLOR_YELLOW,
    };

    WINDOW *window = createWindow(config);
    bool windowShouldClose = FALSE;

    mvwprintw(window, 2, 4, "MAIN MENU");
    mvwprintw(window, 4, 6, "Start");
    mvwprintw(window, 5, 6, "Exit");

    wrefresh(window);

    CHOICE choice = CHOICE_START;

    int c = 0;

    do {
        // Remove the cursor from last iteration.
        mvwprintw(window, 4 + choice, 4, " ");

        // Arrow keys emit \033, [, and then A for up arrow and B for down arrow.
        if (c == '\033') {
            getch();
            c = getch();

            switch (c) {
                case 'A':
                    if (choice == CHOICE_START) {
                        choice = CHOICE_EXIT;
                    }
                    else {
                        choice--;
                    }
                    break;

                case 'B':
                    choice = (choice + 1) % 3;
                    break;
            }
        }
        // Enter key.
        else if (c == '\n') {
            // Move to other pages.
            
        }

        // Print a cursor for the selected choice.
        wattron(window, COLOR_PAIR(1));
        mvwprintw(window, 4 + choice, 4, ">");
        wattroff(window, COLOR_PAIR(1));

        wrefresh(window);
    } while (!windowShouldClose && (c = getch()));

    deleteWindow(window);
}

void settingsPage(Settings *settings) {

}
#include "pages.h"

#include <ncurses/ncurses.h>

#include "window.h"

void mainPage() {
    typedef enum {
        CHOICE_START = 0,
        CHOICE_EXIT
    } CHOICE;

    const WindowConfig config = {
        .dimensions = {
            .height = 12,
            .width = 40
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
                    choice = (choice + 1) % 2;
                    break;
            }
        }
        // Enter key.
        else if (c == '\n') {
            switch (choice) {
                case CHOICE_START:
                    break;

                case CHOICE_EXIT:
                    windowShouldClose = TRUE;
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
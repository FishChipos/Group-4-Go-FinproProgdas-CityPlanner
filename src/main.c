#include <stdio.h>
#include <stdlib.h>
#include <ncurses/ncurses.h>

#include "pages.h"

#define CURSOR_INVISIBLE 0

int main() {
    system("clear");

    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    curs_set(CURSOR_INVISIBLE);

    bool showInfoPage = FALSE;

    // Info messages for color-related terminal stuff.
    if (!has_colors()) {
        printw("INFO: Terminal does not support color.\n");
        showInfoPage = TRUE;
    }
    else {
        start_color();
    }

    if (!can_change_color()) {
        printw("INFO: Terminal cannot change color definitions.\n");
        showInfoPage = TRUE;
    }

    if (showInfoPage) {
        printw("Press anything to continue.");

        refresh();

        getch();

        clear();
    }

    refresh();

    mainPage();

    endwin();

    return 0;
}
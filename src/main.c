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

    if (!has_colors()) {
        printw("INFO: Terminal does not support color.");
        mvprintw(1, 0, "Press anything to continue.");

        refresh();

        getch();
        clear();
    }
    else {
        start_color();
    }

    refresh();

    mainPage();

    endwin();

    return 0;
}
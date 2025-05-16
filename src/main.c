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

    TerminalFlags flags = 0;

    if (!has_colors()) {
        flags |= FLAG_COLOR_UNSUPPORTED;
    }
    else {
        start_color();
    }
    
    if (!can_change_color()) flags |= FLAG_COLOR_FIXED;

    infoPage(flags);

    clear();
    refresh();

    mainPage();

    endwin();

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <ncurses/ncurses.h>

#include "pages.h"
#include "settings.h"
#include "window.h"

#define CURSOR_INVISIBLE 0

int main() {
    system("clear");

    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    curs_set(CURSOR_INVISIBLE);

    // Initialize structs.
    TerminalFlags terminalFlags = 0;
    Settings settings;

    if (!has_colors()) {
        terminalFlags |= FLAG_TERMINAL_COLOR_UNSUPPORTED;
    }
    else {
        start_color();
    }

    if (!can_change_color()) terminalFlags |= FLAG_TERMINAL_COLOR_FIXED;

    infoPage(&settings, &terminalFlags);

    clear();
    refresh();

    startMenuPage(&settings);

    endwin();

    return 0;
}
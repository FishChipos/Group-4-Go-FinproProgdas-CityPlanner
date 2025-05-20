#include <stdio.h>
#include <stdlib.h>
#include <ncurses/ncurses.h>

#include "app.h"
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

    refresh();

    // Initialize structs.
    App app = {
        .shouldClose = FALSE,
        .terminalFlags = 0,
        .page = PAGE_INFO
    };

    // Initialize terminal flags.
    if (!has_colors()) {
        app.terminalFlags |= FLAG_TERMINAL_COLOR_UNSUPPORTED;
    }
    else {
        start_color();
    }

    if (!can_change_color()) app.terminalFlags |= FLAG_TERMINAL_COLOR_FIXED;

    // Main loop.
    while (!app.shouldClose) {
        switch (app.page) {
            case PAGE_INFO:
                infoPage(&app);
                break;
            case PAGE_START:
                startMenuPage(&app);
                break;
            case PAGE_SETTINGS:
                settingsPage(&app);
                break;
        }

        clear();
        refresh();
    };

    endwin();

    return 0;
}
#include "pages.h"

#include <ncurses/ncurses.h>

#include "window.h"

void mainPage() {
    const WindowConfig config = {
        .dimensions = {
            .height = 12,
            .width = 40
        },
        .padding = {
            .top = 1,
            .left = 4
        }
    };

    WINDOW *window = createWindow(config);

    mvwprintw(window, 2, 4, "MAIN MENU");
    mvwprintw(window, 4, 4, "Press q to close.");

    wrefresh(window);

    char c;

    while ((c = getch()) != 'q') {
        wrefresh(window);
    }

    deleteWindow(window);
}
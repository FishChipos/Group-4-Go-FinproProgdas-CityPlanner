#include "window.h"

WINDOW *createWindow(WindowConfig config) {
    WINDOW *window;

    window = newwin(config.dimensions.height, config.dimensions.width, config.padding.top, config.padding.left);

    init_pair(1, COLOR_RED, COLOR_BLACK);

    wattron(window, COLOR_PAIR(1));
    box(window, 0, 0);
    wattroff(window, COLOR_PAIR(1));

    wrefresh(window);

    return window;
}

void deleteWindow(WINDOW *window) {
    // Remove border.
    wborder(window, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');

    wrefresh(window);
    
    delwin(window);
}
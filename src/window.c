#include "window.h"
#include <ncurses/ncurses.h>

void createBorderedWindow(BorderedWindow *window) {
    WINDOW **borderWindow = &window->borderWindow;
    WINDOW **contentWindow = &window->contentWindow;

    *borderWindow = newwin(window->config.dimensions.height, window->config.dimensions.width, window->config.padding.top, window->config.padding.left);
    *contentWindow = newwin(window->config.dimensions.height - 2, window->config.dimensions.width - 2, window->config.padding.top + 1, window->config.padding.left + 1);

    init_pair(1, window->borderColor, COLOR_BLACK);

    wattron(*borderWindow, COLOR_PAIR(1));
    box(*borderWindow, 0, 0);
    wattroff(*borderWindow, COLOR_PAIR(1));

    wrefresh(*borderWindow);
    wrefresh(*contentWindow);
}

void deleteBorderedWindow(BorderedWindow *window) {
    WINDOW **borderWindow = &window->borderWindow;
    WINDOW **contentWindow = &window->contentWindow;

    wclear(*borderWindow);
    wclear(*contentWindow);

    wrefresh(*borderWindow);
    wrefresh(*contentWindow);
    
    delwin(*borderWindow);
    delwin(*contentWindow);
}
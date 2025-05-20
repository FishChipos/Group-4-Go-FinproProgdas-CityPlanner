/*
Global app state.
TODO: Implement saving and loading maybe.
*/

#ifndef APP_H
#define APP_H

#include <ncurses/ncurses.h>

#include "cities.h"

typedef struct {
    bool colorEnabled;
} Settings;

typedef enum {
    FLAG_TERMINAL_COLOR_UNSUPPORTED = 1,
    FLAG_TERMINAL_COLOR_FIXED = 2,
} TerminalFlags;

typedef enum {
    PAGE_INFO = 0,
    PAGE_START,
    PAGE_CITIES,
    PAGE_SETTINGS,
} Page;

typedef struct {
    bool shouldClose;
    TerminalFlags terminalFlags;
    Settings settings;
    Page page;
    Cities cities;
} App;

#endif
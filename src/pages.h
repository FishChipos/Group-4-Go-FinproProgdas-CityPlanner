/*
Functions to display pages.
*/

#ifndef PAGES_H
#define PAGES_H

typedef enum {
    FLAG_COLOR_UNSUPPORTED = 1,
    FLAG_COLOR_FIXED = 2,
} TerminalFlags;

// Page functions.

void infoPage(TerminalFlags flags);
void mainPage();

#endif
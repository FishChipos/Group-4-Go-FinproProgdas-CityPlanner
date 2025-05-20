/*
Functions to display pages.
*/

#ifndef PAGES_H
#define PAGES_H

#include "settings.h"

typedef enum {
    FLAG_TERMINAL_COLOR_UNSUPPORTED = 1,
    FLAG_TERMINAL_COLOR_FIXED = 2,
} TerminalFlags;

// Page functions.

// Displays an info page for the flags set for the terminal.
void infoPage(Settings *settings, TerminalFlags *terminalFlags);
// Displays the start menu page.
void startMenuPage(Settings *settings);

void mainPage(Settings *settings);

void settingsPage(Settings *settings);

#endif
/*
Functions to display pages.
*/

#ifndef PAGES_H
#define PAGES_H

#include "app.h"

// Page functions.

// Displays an info page for the flags set for the terminal.
void infoPage(AppState *app);
// Displays the start menu page.
void startMenuPage(AppState *app);

void mainPage(AppState *app);

void settingsPage(AppState *app);

#endif
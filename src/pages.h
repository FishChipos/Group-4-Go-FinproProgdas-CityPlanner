/*
Functions to display pages.
*/

#ifndef PAGES_H
#define PAGES_H

#include "app.h"

// Page functions.

// Displays an info page for the flags set for the terminal.
void infoPage(App *app);
// Displays the start menu page.
void startMenuPage(App *app);

void mainPage(App *app);

void settingsPage(App *app);

#endif
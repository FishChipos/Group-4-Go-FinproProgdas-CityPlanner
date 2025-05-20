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

// Displays the cities page.
void citiesPage(App *app);
// Displays the page for a city.
void cityPage(City *city);

// Displays the settings page.
void settingsPage(App *app);

#endif
#ifndef PAGES_H
#define PAGES_H

#include "../app.h"

// Displays the start page.
void pageStart(App *app);

// Displays the cities page.
void pageCities(App *app);

// Displays the page for a city.
void pageCity(App *app, City *city);

// Displays the page for an evaluation of a city.
void pageCityEvaluation(App *app, City *city);

// Displays the page for a simulation of a city.
void pageCitySimulation(App *app, City *city);

// Prints a prompt for invalid input and waits for user input.
void promptInvalidInput();

// Prints a prompt and waits for user input.
void promptContinue();

#endif
#ifndef PAGES_H
#define PAGES_H

#include "../app.h"

void pageStart(App *app);

void pageCities(App *app);

void pageCity(App *app, City *city);

void promptInvalidInput();

#endif
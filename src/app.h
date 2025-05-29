#ifndef APP_H
#define APP_H

#include <stdbool.h>

#include "systems/cities.h"

// Struct containing the state of the app.
typedef struct {
    // Whether the app should close.
    bool shouldClose;

    // Stores an array of cities for this current session.
    Cities cities;
} App;

#endif
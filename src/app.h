#ifndef APP_H
#define APP_H

#include <stdbool.h>

#include "cities.h"

typedef struct {
    bool shouldClose;

    Cities cities;
} App;

#endif
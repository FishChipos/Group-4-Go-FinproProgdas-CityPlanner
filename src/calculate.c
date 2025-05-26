#include "calculate.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int calculateDensity(float area, unsigned long long population) {
    if (area <= 0) return 0;

    float density = population / area;

    if (density <= 1000) return 100;
    else if (density <= 3000) return 75;
    else if (density <= 5000) return 50;
    else return 25;
}

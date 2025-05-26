#include "calculate.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int calculateDensity(double area, size_t population) {
    if (area <= 0) return 0;

    double density = population / area;

    if (density <= 5000) return 100;
    else if (density <= 8000) return 75;
    else if (density <= 10000) return 50;
    else return 25;
}

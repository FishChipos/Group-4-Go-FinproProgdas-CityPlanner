#include "cityevaluation.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

double calculatePopulationDensity(double area, size_t population) {
    // If area is 0 or less then return 0.
    if (area <= 0) return 0;

    // Calculate density.
    double density = population / area;

    return density;
}

#include "cityevaluation.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

double calculatePopulationDensity(double area, size_t population) {
    // If area or population is less than equal to 0 return 0.
    if (area <= 0 || population <= 0) return 0;

    // Calculate density.
    double density = population / area;

    return density;
}

double scorePopulationDensity(double area, size_t population) {
    // If area or population is less than equal to 0 return 0.
    if (population <= 0 || area <= 0) return 0;
    
    // Calculate population density score.
    double score = 100 - 25 * ((population / (area * 2000)) - 1);
    if (score > 100) {
        score = 100;
    } else if(score < 0) {
        score = 0;
    }
    
    return score;
}

double scorePublicTransportation(double publicTrans, size_t population) {
    // If publicTrans or population is less than equal to 0 return 0.
    if (population <= 0 || publicTrans <= 0) return 0;
    
    // Calculate Public Transportation score.
    double score = 100 - 25 * log2(population / (publicTrans * 100));
    if (score > 100) {
        score = 100;
    } else if(score < 0) {
        score = 0;
    }
    
    return score;
}

double scorePersonalTransportation(double personalTrans, size_t population) {
    // If personalTrans or population is less than equal to 0 return 0.
    if (population <= 0 || personalTrans <= 0) return 0;
    
    // Calculate Personal Transportation score.
    double score = 25 * (log2(population / personalTrans) - 1);
    if (score > 100) {
        score = 100;
    } else if(score < 0) {
        score = 0;
    }
    
    return score;
}

double scoreWater(double supply, double consum) {
    // If supply or consum is less than equal to 0 return 0.
    if (supply <= 0 || consum <= 0) return 0;
    
    // Calculate water score.
    double score = (supply / consum) * 100 - 20;
    if (score > 100) {
        score = 100;
    } else if(score < 0) {
        score = 0;
    }
    return score;
}

double scoreEducation(size_t unit, double population) {
    // If unit or population is less than equal to 0 return 0.
    if (unit <= 0 || population <= 0) return 0;
    
    // Calculate education availability score.
    double score = 100 - 25 *  ((population / (unit * 1000)) - 1);
    if (score > 100) {
        score = 100;
    } else if(score < 0) {
        score = 0;
    }
    return score;
}

double scoreHospital(size_t unit, double population) {
    // If unit or population is less than equal to 0 return 0.
    if (unit <= 0 || population <= 0) return 0;
    
    // Calculate healthcare availability score.
    double score = 100 - 25 *  (pow(1.01,(population / unit ) - 200) - 1);
    if (score > 100) {
        score = 100;
    } else if(score < 0) {
        score = 0;
    }
    return score;
}


#include "inputparser.h"

int parseInt(char *string) {
    int result;

    sscanf(string, "%d", &result);

    return result;
}
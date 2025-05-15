#ifndef WINDOW_H
#define WINDOW_H

#include <ncurses/ncurses.h>

typedef struct {
    struct {
        int height;
        int width;
    } dimensions;
    struct {
        int top;
        int left;
    } padding;
    struct {
        int r;
        int g;
        int b;
    } color;
} WindowConfig;

WINDOW *createWindow(WindowConfig config);
void deleteWindow(WINDOW *window);

#endif
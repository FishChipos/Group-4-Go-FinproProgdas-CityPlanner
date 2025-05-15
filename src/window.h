#ifndef WINDOW_H
#define WINDOW_H

#include <ncurses/ncurses.h>

// Struct containing configuration options for a window.
typedef struct {
    struct {
        int height;
        int width;
    } dimensions;
    
    struct {
        int top;
        int left;
    } padding;
    
    int borderColor;
    int textColor;
} WindowConfig;

// Creates a window with default border.
WINDOW *createWindow(WindowConfig config);
// Deletes a window and removes the border.
void deleteWindow(WINDOW *window);

#endif
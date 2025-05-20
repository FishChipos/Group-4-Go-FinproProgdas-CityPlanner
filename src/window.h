/*
Utility functions for window-related stuff.
*/

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

    int textColor;
    int borderColor;

} WindowConfig;

// Struct containing configuration options for a window.
typedef struct {
    WINDOW *borderWindow;
    WINDOW *contentWindow;

    WindowConfig config;
} BorderedWindow;

// Creates a window with default border.
void createBorderedWindow(BorderedWindow *window);
// Deletes a window and removes the border.
void deleteBorderedWindow(BorderedWindow *window);

#endif
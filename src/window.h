/*
Utility functions for window-related stuff.
*/

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
        int y;
        int x;
    } origin;

    int textColor;
    int borderColor;
} WindowConfig;

// Struct encapsulating a bordered window.
// Has a window for the border and another window for the content to enable persistent borders.
typedef struct {
    WINDOW *borderWindow;
    WINDOW *contentWindow;

    WindowConfig config;
} BorderedWindow;

// Creates a bordered window.
void createBorderedWindow(BorderedWindow *window);
// Deletes a bordered window.
void deleteBorderedWindow(BorderedWindow *window);

#endif
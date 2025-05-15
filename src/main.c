#include <stdio.h>
#include <ncurses/ncurses.h>

int main() {
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);

    printw("Hello world!");
    refresh();
    getch();
    endwin();

    return 0;
}
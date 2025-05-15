#include <stdio.h>
#include <ncurses/ncurses.h>

int main() {
    initscr();
    printw("Hello world!");
    refresh();
    getch();
    endwin();

    return 0;
}
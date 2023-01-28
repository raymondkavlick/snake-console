
#include "Screen.h"
#include <ncurses.h>


Screen::Screen() {
    initscr();

}

Screen::~Screen(){
   // endwin();
}
void Screen::tic(){
   // refresh();
}
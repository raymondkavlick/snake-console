
#include "Screen.h"
#include <ncurses.h>
#include <unistd.h>
#include <cstdlib>
#include <string>
#include <vector>

Screen::Screen() {
    initscr();
    clear();
    curs_set(0);    
    cbreak();
    noecho();
    keypad(stdscr,true);
    nodelay(stdscr, true);
    set_refresh_rate_HZ_to_delay(4);
}

Screen::Screen(int rate) : refresh_HZ(rate) {
    set_refresh_rate_HZ_to_delay(rate);
}

Screen::~Screen(){
    endwin();
}
void Screen::tic(board_container & board){
 
    int row = 0;
    for (const auto & ch : board){
        for (const auto & c : ch)  {
            print_ch(c);
        }
        move(++row,0);
    }
    refresh();
    usleep(refresh_delay_us);
}

void Screen::print_str(std::vector<char> & v) {
    for (const auto & c : v) print_ch(c);
}

void Screen::print_ch(char ch) {
    static char buff[2];
    buff[0] = ch;
    addch(buff[0]);
}

int Screen::get_key() {
    return getch();
}
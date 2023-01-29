
#include "Screen.h"
#include <ncurses.h>
#include <unistd.h>
#include <cstdlib>
#include <string>

Screen::Screen() {
    initscr();
    set_refresh_rate_HZ_to_delay(30);
}

Screen::Screen(int rate) : refresh_HZ(rate) {
    set_refresh_rate_HZ_to_delay(rate);
}

Screen::~Screen(){
    endwin();
}
void Screen::tic(board_container & board){
    clear();
    for ( auto & ch : board){
        for (const auto & c : ch) 
        {
            const char d = '*';
            std::string temp = "*";
            printw(temp.c_str());
        }
        printw("\r\n");
    }

    refresh();
    usleep(refresh_delay_us);
}

wchar_t Screen::get_wc(const char c)
{
    char arr[1];
    arr[0] = c;
    const size_t cSize = 2;
    wchar_t* wc = new wchar_t[cSize];
    mbstowcs (wc, arr, cSize);

    return wc[0];
}
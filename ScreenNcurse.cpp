
#include "ScreenNcurse.h"
#include <ncurses.h>
#include <unistd.h>
#include <cstdlib>
#include <string>
#include <vector>

ScreenNcurse::ScreenNcurse() {
    initscr();
    clear();    
    curs_set(0);    
    cbreak();
    keypad(stdscr,true);
    nodelay(stdscr, true);
    set_refresh_rate_HZ_to_delay(refresh_HZ);
}

void ScreenNcurse::close() {
    endwin();
}

void ScreenNcurse::tic(board_container & board, int score){
 
    int row = 0;
    for (const auto & ch : board){
        for (const auto & c : ch)  {
            print_ch(c);
        }
        move(++row,0);
    }

    move(++row,0);
    printw(" Score = %d",score);
    move(0,0);
    refresh();
    usleep(refresh_delay_us);
}

void ScreenNcurse::print_str(std::vector<char> & v) {
    for (const auto & c : v) print_ch(c);
}

void ScreenNcurse::print_ch(char ch) {
    static char buff[2];
    buff[0] = ch;
    addch(buff[0]);
}

void ScreenNcurse::set_log(std::string log) {
    if (logging_enabled) {
        move(0,0);
        //printw(log.c_str());
        refresh();
        sleep(2);
    }
}

Direction ScreenNcurse::get_direction() {
    auto key = getch();
    static Direction prev = Direction::LEFT;
    switch (key) {
        case KEY_LEFT:
            return prev = Direction::LEFT;
        case KEY_UP:
            return prev = Direction::UP;
        case KEY_DOWN:
            return prev = Direction::DOWN;
        case KEY_RIGHT:
            return prev = Direction::RIGHT;
        default:
            break;
    }
    return prev;
}
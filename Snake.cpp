#include "Snake.h"
#include <iostream>

Snake::Snake()
{
    board.assign(BOARD_SIZE,board_row(init_char,BOARD_SIZE));
}

bool Snake::tic()
{
    if (gameover) return false;
    screen.tic(board);

    return true;
}
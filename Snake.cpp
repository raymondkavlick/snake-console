#include "Snake.h"

Snake::Snake()
{
    
}
Snake::~Snake()
{
    
}

bool Snake::tic() {
    if (gameover) return false;
    screen.tic();
    return true;
}
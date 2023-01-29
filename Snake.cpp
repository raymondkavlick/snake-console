#include "Snake.h"
#include <iostream>
#include <string>
#include <unistd.h>

Snake::Snake() {
    board.assign(NUM_ROWS,board_row(NUM_COLS,init_char));
    snake.push({NUM_ROWS / 2, NUM_COLS / 2});
    board[snake.back().first][snake.back().second] = snake_char;
    srand(time(NULL));
    for (uint32_t i = 0; i < NUM_OF_RATS; i++) addRat();
    screen.tic(board);
}

bool Snake::tic() {

    handle_input();
    if (gameover) {
        screen.close();
        return false;
    }
    screen.tic(board);

    return true;
}

void Snake::handle_input() {

    auto nextdir = get_direction();
    if (nextdir == Direction::RIGHT)
        snake.push({snake.back().first,snake.back().second + 1});
    else if (nextdir == Direction::LEFT)
        snake.push({snake.back().first,snake.back().second - 1});
    else if (nextdir == Direction::UP)
        snake.push({snake.back().first - 1,snake.back().second});
    else if (nextdir == Direction::DOWN)
        snake.push({snake.back().first + 1,snake.back().second});

    auto snake_pos = snake.back();

    if (isGameOver()) {
        gameover = true;
        return;
    }
    
    if (board[snake_pos.first][snake_pos.second] == rat_char) {
        snake_len++;
        addRat();
    }
    board[snake.back().first][snake.back().second] = snake_char;

    if (snake.size() >= snake_len + 1) {
        board[snake.front().first][snake.front().second] = init_char;
        snake.pop();
    }
}

bool Snake::isGameOver() {
    auto snake_pos = snake.back();
    return snake_pos.first < 0 ||
        snake_pos.first == NUM_ROWS ||
        snake_pos.second < 0 ||
        snake_pos.second == NUM_COLS ||
        board[snake_pos.first][snake_pos.second] == snake_char;
}

void Snake::addRat() {
    bool found = false;

    while (!found) {
        int randrow = rand() % NUM_ROWS;
        int randcol = rand() % NUM_COLS;
        auto & nextRat = board[randrow][randcol];
        if (nextRat != snake_char) {
            nextRat = rat_char;
            found = true;
        }
    }
}

Direction Snake::get_direction() {
    static Direction dir = Direction::LEFT;

    switch (screen.get_direction()) {
        case Direction::RIGHT:
            if (dir != Direction::LEFT)
                dir = Direction::RIGHT;
            break;
        case Direction::LEFT:
            if (dir != Direction::RIGHT)
                dir = Direction::LEFT;
            break;
        case Direction::DOWN:
            if (dir != Direction::UP)
                dir = Direction::DOWN;
            break;
        case Direction::UP:
            if (dir != Direction::DOWN)
                dir = Direction::UP;
            break;
        default:
            break;
    }
    return dir;
}

void Snake::setBoard(char set) {
    for (auto & ch : board)
        for (auto & c : ch) c = set;
}
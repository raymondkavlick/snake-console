
#include "ScreenNcurse.h"
#include <vector>
#include <queue>


class Snake {
public:
	Snake();
	bool tic();
private:
	void handle_input();
	static constexpr size_t SNAKE_START_LEN {5};
	static constexpr size_t NUM_OF_RATS {5};
	static constexpr size_t BOARD_SIZE_ROWS {11};
	static constexpr size_t NUM_ROWS {BOARD_SIZE_ROWS};
	static constexpr size_t NUM_COLS {BOARD_SIZE_ROWS * 2};
	std::queue<point> snake;
	size_t snake_len = SNAKE_START_LEN;
	ScreenNcurse screen;
	bool gameover = false;
	board_container board;
	static constexpr char init_char {'-'};
	static constexpr char snake_char {'@'};
	static constexpr char rat_char {'#'};
	bool isGameOver();
	void addRat();
	Direction get_direction();
	void setBoard(char);
};


#include "Screen.h"
#include <vector>
#include <queue>

enum class Direction {
	RIGHT,
	LEFT,
	DOWN,
	UP
};

class Snake {
	
using board_row = std::vector<char>;
using board_container = std::vector<board_row>;
using point = std::pair<size_t,size_t> ;
public:
	Snake();
	bool tic();
private:
	void handle_input();
	static constexpr size_t SNAKE_START_LEN {3};
	static constexpr size_t BOARD_SIZE_ROWS {7};
	static constexpr size_t NUM_ROWS {BOARD_SIZE_ROWS};
	static constexpr size_t NUM_COLS {BOARD_SIZE_ROWS * 2};
	std::queue<point> snake;
	size_t snake_len = SNAKE_START_LEN;
	Screen screen;
	bool gameover = false;
	board_container board;
	static constexpr char init_char {'-'};
	static constexpr char snake_char {'@'};
	static constexpr char rat_char {'#'};
	bool isGameOver();
	void addRat();
	Direction get_direction();
};


#include "Screen.h"
#include <vector>


class Snake {
	static constexpr size_t BOARD_SIZE {5};
	
using board_row = std::vector<char>;
using board_container = std::vector<board_row>;
public:
	Snake();
	bool tic();
private:
	Screen screen;
	bool gameover = false;
	int num = 0;
	board_container board;
	static constexpr char init_char {'*'};
};

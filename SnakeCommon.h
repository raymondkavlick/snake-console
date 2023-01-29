#include <vector>

enum class Direction {
	RIGHT,
	LEFT,
	DOWN,
	UP
};

using board_row = std::vector<char>;
using board_container = std::vector<board_row>;
using point = std::pair<int,int>;


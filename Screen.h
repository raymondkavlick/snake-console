#include <ncurses.h>

class Screen {
public:
	Screen () {
		initscr();
	}
	~Screen(){
		endwin();
	}

	void tic() {
		refresh();
	}
    void test();
};

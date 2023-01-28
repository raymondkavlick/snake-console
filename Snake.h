
#include "Screen.h"

class Snake {
public:
	Snake();
	~Snake();
	bool tic();
private:
	Screen screen;
	bool gameover = false;
};

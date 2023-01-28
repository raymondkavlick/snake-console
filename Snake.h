
#include <thread>
#include <Screen.h>

#define sleepms(val) std::this_thread::sleep_for(val##ms)

class Snake {
public:
	Snake (){};
	bool tic() {
		if (gameover) return false;
		screen.tic();
		sleepms(100);
		return true;
	}
private:
	Screen screen;
	bool gameover = false;
};

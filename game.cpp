//A program to play snake on the console

#include <stdlib.h>
#include <iostream> 
#include <thread>
#include <ncurses.h>

using namespace std;

class Snake;

int main(void){	

	Snake snake;

	while (snake.tic());
	auto ch = getch();			/* Wait for user input */
	return 0;
}

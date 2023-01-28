//A program to play snake on the console

#include <stdlib.h>
#include "Snake.h"
#include <iostream>
#include <ncurses.h>

using namespace std;

class Snake;

int main(void){	

	Snake snake;

	cout << "Hello\r\n";
	while (snake.tic());
	//auto ch = getch();			/* Wait for user input */
	return 0;
}

//A program to play snake on the console , platform independent
#include <memory>
#include "Snake.h"
#include <iostream>

using namespace std;

int main() {	
	auto snake = std::make_unique<Snake>();
	while (snake->tic());
	cout << "\r\n* Score : " << snake->getScore() << " *\r\n";
	return 0;
}

//A program to play snake on the console

#include <stdlib.h>
#include <iostream>
#include <memory>
#include "Snake.h"

using namespace std;

int main(void){	

	auto snake = std::make_unique<Snake>();
	while (snake->tic());
	return 0;
}

//A program to play snake on the console
#include <memory>
#include "Snake.h"

using namespace std;

int main() {	

	auto snake = std::make_unique<Snake>();
	while (snake->tic());
	return 0;
}

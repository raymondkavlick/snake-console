default:
	g++ Snake.cpp Snake.h
#	g++ Screen.cpp -lncurses
#	g++ game.cpp Snake.o Screen.o -o game

clean: 
	rm game
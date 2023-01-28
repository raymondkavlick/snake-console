CC = g++
OBJ = game
HEADER = Screen.h
CFLAGS = -c -Wall 

hello: $(OBJ)
    $(CC) $(OBJ) -o $@

main.o: src/main.cpp $(HEADER)
    $(CC) $(CFLAGS) $< -o $@

clean: 
    rm -rf *o hello
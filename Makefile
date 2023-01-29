CC = g++
SRCS := $(wildcard *.cpp)
OBJS := $(SRCS:cpp=o)
CFLAGS := -std=c++20 -Wall

.PHONY: all clean

default: clean game 

game: $(OBJS) Makefile
	$(CC) -o $@ $(OBJS) $(CFLAGS) -lncurses

$(OBJS): %.o: %.cpp Makefile
	$(CC) -c $< $(CFLAGS)

clean:
	@rm -rf app $(OBJS)
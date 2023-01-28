CC = g++
SRCS := $(wildcard *.cpp)
OBJS := $(SRCS:cpp=o)
CFLAGS := -Wall -Werror

.PHONY: all clean

default: game 

game: $(OBJS) Makefile
	$(CC) -o $@ $(OBJS) $(CFLAGS) -lncurses

$(OBJS): %.o: %.cpp Makefile
	$(CC) -c $< $(CFLAGS)

clean:
	@rm -rf app $(OBJS)
CC = g++
SRCS := $(wildcard *.cpp)
OBJS := $(SRCS:cpp=o)
CFLAGS := -Wall

.PHONY: all clean

default: clean game 

game: $(OBJS) Makefile
	$(CC) -o $@ $(OBJS) $(CFLAGS) -lncurses

$(OBJS): %.o: %.cpp Makefile
	$(CC) -c $< $(CFLAGS)

clean:
	@rm -rf app $(OBJS)
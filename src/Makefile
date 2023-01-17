CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++17
TARGET = main

all: clean main

main: clean
	$(CC) $(CFLAGS) -c main.cpp -o main.o
	$(CC) $(CFLAGS) -c mystring.cpp -o mystring.o
	$(CC) $(CFLAGS) *.o -o $(TARGET).out

clean:
	rm -rf *.o *.out

rebuild: all

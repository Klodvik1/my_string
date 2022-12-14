CC = g++
CFLAGS = -Wall -Wextra -Werror
TARGET = s21_cat

all: clean main

main: clean
	$(CC) $(CFLAGS) ./main.cpp -o ./main.o
#$(CC) $(CFLAGS) ./mystring.cpp -o ./mystring.o
	$(CC) $(CFLAGS) ./*.o -o ./$(TARGET_1)


clean:
	rm -rf *.o *.a *.out *.info *.html *.gc* 
	

rebuild: all

# makefile that builds the library

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror -pedantic -std=c99 -g

# 'build' builds the library
build: *.c
	$(CC) $(CFLAGS) -c -fpic *.c
	ar rcs liball.a *.o

# 'clean' removes all .o and executable files
clean:
	rm -f *.o

# 'pack' packs all object files into a '.a' archive
pack:
	tar -cvf liball.tar *.c *.h Makefile
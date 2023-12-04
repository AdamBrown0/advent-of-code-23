CC=gcc
CFLAGS=-I.

DEPS = array_helper.h assert_helper.h debug_helper.h file_helper.h math_helper.h misc_helper.h string_helper.h
OBJ = main.o array_helper.o assert_helper.o debug_helper.o file_helper.o math_helper.o misc_helper.o string_helper.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
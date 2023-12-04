# Variables
CC = gcc
AR = ar
CFLAGS = -c
ARFLAGS = rcs
LIB = libhelper.a
SRCS = $(wildcard ../helper/*.c)
OBJS = $(SRCS:.c=.o)

# Default target
all: $(LIB)

# Rule to create object files
%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

# Rule to create the library
$(LIB): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

# Rule to clean intermediate files
clean:
	rm -f $(OBJS) $(LIB)
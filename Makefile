SRC = ft_split.c      pipex.c          process.c \

# Specify the target binary
TARGET = pipex

# Specify the object files that need to be built
OBJECTS = $(SRC:.c=.o)

# Specify the compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -O2

# Default rule
all: $(TARGET)

# Rule to build the target binary
$(TARGET):  $(OBJECTS)
	$(CC)   $(CFLAGS)   -o  $(TARGET)   $(OBJECTS)

# Rule to build the object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f $(TARGET) $(OBJECTS)

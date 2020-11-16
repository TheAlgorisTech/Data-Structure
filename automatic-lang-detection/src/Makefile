
# Compiler to user
CC=gcc

# Compiler Flags
# -Wall turns on most, but not all, compiler warnings
CFLAGS=-Wall

TARGET=trie
UTILS=utils

all:$(TARGET)

$(TARGET):  $(UTILS).c $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(UTILS).c $(TARGET).c 

clean:
	rm *.o *.out $(TARGET)

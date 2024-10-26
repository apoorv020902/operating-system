# Makefile for compiling proc_creation program

CC = gcc
CFLAGS = -Wall -g
TARGET = proc_creation

all: $(TARGET)

$(TARGET): proc_creation.c
	$(CC) $(CFLAGS) -o $(TARGET) proc_creation.c

clean:
	rm -f $(TARGET)

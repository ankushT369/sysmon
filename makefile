# Makefile for ptrace_syscall_tracer

CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c99
TARGET = main
SRC = main.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)


#
#
#
#


CC = gcc
CFLAGS = -Wall -g
BUILD_DIR = build
OUTPUT = loancalc

build: main.o loans.o
	$(CC) $(CFLAGS) -o $(OUTPUT) $(BUILD_DIR)/main.o $(BUILD_DIR)/loans.o

main.o: main.c
	$(CC) -c $(CFLAGS) -o $(BUILD_DIR)/main.o main.c


loans.o: loans.h loans.c
	$(CC) -c $(CFLAGS) -o $(BUILD_DIR)/loans.o loans.c

clean:
	rm -r -f $(BUILD_DIR)/*
	rm $(OUTPUT)

rebuild: clean build

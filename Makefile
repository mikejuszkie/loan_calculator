#
#
#
#


CC = gcc
CFLAGS = -std=c99 -Wall -g
BUILD_DIR = build
OUTPUT = loan_calculator


build: build/main.o build/loans.o
	$(CC) $(CFLAGS) -o $(OUTPUT) $(BUILD_DIR)/main.o $(BUILD_DIR)/loans.o

build/main.o: main.c
	$(CC) -c $(CFLAGS) -o $(BUILD_DIR)/main.o main.c


build/loans.o: loans.h loans.c
	$(CC) -c $(CFLAGS) -o $(BUILD_DIR)/loans.o loans.c

debug: 
	CFLAGS += -D DEBUG 
	make build

clean:
	rm -r -f $(BUILD_DIR)/*.o
	rm $(OUTPUT)

rebuild: clean build


CC := g++
CFLAGS := -g -O2 -Wall -pedantic -std=c++23
LIBS := -Iinclude/*

TARGET_EXEC := ./ray-net
BUILD_DIR := ./build

INC_DIR := include
INC_DIRS := $(shell find $(INC_DIR) -type d)
SRC_FILES := $(shell find $(INC_DIR) -name '*.cpp')

main: $(SRC)
	$(CC) src/main.cpp $(CFLAGS) $(LIBS) $(SRCS) -o $(TARGET_EXEC)

run: main
	./$(TARGET_EXEC)

install:


clean:
	rn -r $(BUILD_DIR)









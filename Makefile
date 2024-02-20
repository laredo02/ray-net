
CC := g++
CFLAGS := -g -O2 -Wall -pedantic -std=c++23
LIBS := -Iinclude/*

TARGET_EXEC := ./ray-net
BUILD_DIR := ./build

INC_DIR := include
INC_DIRS := $(shell find $(INC_DIR) -type d)
SRC_FILES := $(shell find $(INC_DIR) -name '*.cpp')

main: $(SRC_FILES)
	$(CC) -I$(INC_DIRS) $(CFLAGS) $(LIBS) $(SRCS) $(SRC_FILES) -o $(TARGET_EXEC)

run: main
	./$(TARGET_EXEC)

install:


clean:
	rm -r $(BUILD_DIR)
	rm $(TARGET_EXEC)









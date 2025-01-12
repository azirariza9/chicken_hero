SRC_DIR = src
BUILD_DIR = build 
BIN_DIR	= bin
LIB_DIR = lib 
INCLUDE_DIR = include

TARGET = $(BIN_DIR)/chicken_hero
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES = $(patsubst $(SRC_DIR)/*.cpp,$(BUILD_DIR)/%.o,$(SRC_FILES))

CC = clang++
CFLAGS = -I$(INCLUDE_DIR) -L$(LIB_DIR) -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion -Werror -std=c++23
LDFLAGS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

all: $(TARGET)

$(TARGET) : $(OBJ_FILES) | $(BIN_DIR)
	$(CC) $(OBJ_FILES) -o $@ $(CFLAGS) $(LDFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/$.c | $(BUILD_DIR)
	$(CC) -c $< -o $@ $(CFLAGS)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BIN_DIR) :
	mkdir -p $(BIN_DIR)

clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

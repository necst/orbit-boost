# Compiler
CC := /usr/bin/gcc

# Compiler flags
CFLAGS := -Wall -std=gnu11 -I /usr/include/xrt/
LDFLAGS := -lxrt_core -lxrt_coreutil

# Directories
SRC_DIR := src
BUILD_DIR := build

# Source files
SRC := $(wildcard $(SRC_DIR)/*.c)
OBJ := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC))

# Target executable
TARGET := ldl_dsolve

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) -c $< -o $@ $(CFLAGS)

$(BUILD_DIR):
	mkdir -p $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf $(BUILD_DIR) $(TARGET)

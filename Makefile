CC ?= gcc
CFLAGS ?= -std=c17 -Wall -Wextra -pedantic -Iinclude -O2
BUILD_DIR = build

SRCS = src/main.c src/roadmap.c src/memory_pool.c
OBJS = $(BUILD_DIR)/main.o $(BUILD_DIR)/roadmap.o $(BUILD_DIR)/memory_pool.o

TEST_SRCS = tests/test_main.c src/roadmap.c src/memory_pool.c
TEST_OBJS = $(BUILD_DIR)/test_main.o $(BUILD_DIR)/roadmap.o $(BUILD_DIR)/memory_pool.o

TARGET = $(BUILD_DIR)/learn_c
TEST_TARGET = $(BUILD_DIR)/test_runner

.PHONY: all clean test run

all: $(TARGET)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.o: src/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/test_main.o: tests/test_main.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@

$(TEST_TARGET): $(TEST_OBJS)
	$(CC) $(TEST_OBJS) -o $@

test: $(TEST_TARGET)
	./$(TEST_TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf $(BUILD_DIR)

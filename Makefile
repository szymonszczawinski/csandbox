# Unity source
UNITY_SRC = unity/unity.c
CC = gcc
BUILD_DIR = build

# BIN_DIR = bin
BIN_DIR = bin$(if $(DEBUG),/debug,/release)
TARGET = $(BIN_DIR)/myproject
SYMLINK = myproject

# Base compiler flags
CFLAGS_BASE = -Wall -Wextra -Isrc -Iunity
# Enable debug flags when DEBUG=1
ifeq ($(DEBUG),1)
    CFLAGS += -g -O0
    BUILD_MODE := [DEBUG]
else
    CFLAGS += -O2
    BUILD_MODE := [RELEASE]
endif
CFLAGS += $(CFLAGS_BASE)

# Source files and corresponding object files in build/
MAIN_SRC := src/main.c
MAIN_OBJ := $(patsubst src/%.c,$(BUILD_DIR)/%.o,$(MAIN_SRC))

# All other project sources (excluding main.c)
SRC := $(filter-out $(MAIN_SRC), $(shell find src -name "*.c"))
OBJ := $(patsubst src/%.c,$(BUILD_DIR)/%.o,$(SRC))


# Test files and binaries
TEST_SRC := $(shell find test -name "Test*.c")
TEST_BINS := $(patsubst test/%.c,$(BUILD_DIR)/test/%.test,$(TEST_SRC))

.PHONY: all clean test

all: main

# Link main executable
main: $(OBJ) $(MAIN_OBJ)
	@echo "🔧 Building in mode: $(BUILD_MODE)"
	@mkdir -p $(BIN_DIR)
	$(CC) -o $(TARGET) $^
	@ln -sf $(TARGET) $(SYMLINK)

# Compile .c → .o in build/ directory, keeping relative paths
$(BUILD_DIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Compile test sources to test executables in build/


# Create test executable by extracting module name and finding its source



# Rule to build a test binary from a Test*.c file
$(BUILD_DIR)/test/%.test: test/%.c
	@mkdir -p $(dir $@)
	@TEST_FILE=$<; \
	MODULE_NAME=$$(echo $$(basename $$TEST_FILE) | sed 's/^Test//' | sed 's/\.c//'); \
	SRC_FILE=$$(find src -name "$$MODULE_NAME.c"); \
	if [ -z "$$SRC_FILE" ]; then \
		echo "❌ Error: Could not find source file for module '$$MODULE_NAME'"; \
		exit 1; \
	fi; \
	echo "✅ Building test: $@ (linked with $$SRC_FILE)"; \
	$(CC) $(CFLAGS) $$TEST_FILE $(UNITY_SRC) $$SRC_FILE -o $@


# Run all tests
test: $(TEST_BINS)
	@echo "Running unit tests:"
	@for test in $(TEST_BINS); do \
		echo "==> Running $$test..."; \
		./$$test; \
	done

clean:
	rm -rf $(BUILD_DIR) bin $(SYMLINK)

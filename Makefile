# Check arguments

TARGET_HW=helloapp

TARGET_NAME=$(TARGET_HW)

# Directories
BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/$(TARGET_HW)/obj

INCLUDE_DIRS = ./src \
			   ./external/ \
			   ./

# Toolchain
CC = gcc
RM = rm

# Files
TARGET = $(BUILD_DIR)/$(TARGET_HW)/bin/$(TARGET_NAME)

SOURCES_WITH_HEADERS = \
		src/app/hellofunc.c \
		src/app/calculator/calc.c \

MAIN_FILE = src/main.c

SOURCES = \
		$(MAIN_FILE) \
		$(SOURCES_WITH_HEADERS)

HEADERS = \
		$(SOURCES_WITH_HEADERS:.c=.h) \

OBJECT_NAMES = $(SOURCES:.c=.o)
OBJECTS = $(patsubst %,$(OBJ_DIR)/%,$(OBJECT_NAMES))

# Defines
# HW_DEFINE = $(addprefix -D,$(HW))
# TEST_DEFINE = $(addprefix -DTEST=,$(TEST))
# DEFINES = \
	# $(HW_DEFINE) \
	# $(TEST_DEFINE) \
	# -DPRINTF_INCLUDE_CONFIG_H \
	# -DDISABLE_ENUM_STRINGS \
	# -DDISABLE_TRACE \

# Static Analysis
## Don't check the msp430 helper headers (they have a LOT of ifdefs)
# CPPCHECK_INCLUDES = ./src ./
# IGNORE_FILES_FORMAT_CPPCHECK = \
	# external/printf/printf.h \
	# external/printf/printf.c
# SOURCES_FORMAT_CPPCHECK = $(filter-out $(IGNORE_FILES_FORMAT_CPPCHECK),$(SOURCES))
# HEADERS_FORMAT = $(filter-out $(IGNORE_FILES_FORMAT_CPPCHECK),$(HEADERS))
# CPPCHECK_FLAGS = \
	# --quiet --enable=all --error-exitcode=1 \
	# --inline-suppr \
	# --suppress=missingIncludeSystem \
	# --suppress=unmatchedSuppression \
	# --suppress=unusedFunction \
	# $(addprefix -I,$(CPPCHECK_INCLUDES)) \

# Flags
# MCU = msp430g2553
# WFLAGS = -Wall -Wextra -Werror -Wshadow
# CFLAGS = -mmcu=$(MCU) $(WFLAGS) -fshort-enums $(addprefix -I,$(INCLUDE_DIRS)) $(DEFINES) -Og -g
# LDFLAGS = -mmcu=$(MCU) $(DEFINES) $(addprefix -L,$(LIB_DIRS)) $(addprefix -I,$(INCLUDE_DIRS))

# Build
## Linking
$(TARGET): $(OBJECTS) $(HEADERS)
	echo $(OBJECTS)
	@mkdir -p $(dir $@)
	$(CC) $(LDFLAGS) $^ -o $@

## Compiling
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $^

# Phonies
.PHONY: all clean 

all: $(TARGET)

clean:
	@$(RM) -rf $(BUILD_DIR)

CC := g++
CFLAGS := #-Wall
TARGET ?= SimulationBanque

# Projet files hierarchy
SRC_DIR ?= ./src
INSTALL_DIR ?= ./bin
BUILD_DIR ?= ./build
INCLUDE_DIR ?= ./include
LIB_DIR ?= ./lib

# Files
SOURCE_FILES_1 := $(shell find $(SRC_DIR) -name '*.cpp' -exec basename {} \;)
OBJECTS_FILES_1 ?= $(SOURCE_FILES_1:.cpp=.o)

SOURCE_FILES ?= $(addprefix $(SRC_DIR)/, $(SOURCE_FILES_1))
OBJECTS_FILES ?= $(addprefix $(SRC_DIR)/, $(OBJECTS_FILES_1))

# Build
all: dir $(TARGET)

dir:
	@mkdir -p $(SRC_DIR)
	@mkdir -p $(INSTALL_DIR)
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(INCLUDE_DIR)
	@mkdir -p $(LIB_DIR)

$(TARGET): $(OBJECTS_FILES)
	$(CC) -o $@ $^ $(CFLAGS)
	@mv $(SRC_DIR)/*.o $(BUILD_DIR)
	@mv $(TARGET) $(INSTALL_DIR)

clean:
	rm -rf $(BUILD_DIR)/*.o
	rm -rf $(INSTALL_DIR)/$(TARGET)
	
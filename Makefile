###################### DISCLAIMER #######################
# Taken from https://spin.atomicobject.com/ and adapted #
#########################################################

# Global
# CC := g++
# TARGET ?= SimulationBanque

# # Project files hierarchy
# SRC_DIR ?= ./src
# INSTALL_DIR ?= ./bin
# BUILD_DIR ?= ./build

# # Files
# SRC_FILES := $(shell find $(SRC_DIR) -name *.cpp -or -name *.c -or -name *.s)
# OBJECTS_FILES := $(addsuffix .o,$(basename $(SRC_FILES)))
# DEP_FILES := $(OBJECTS_FILES:.o=.d)

# INCLUDE_DIR := $(shell find $(SRC_DIR) -type d)
# INC_FLAGS := $(addprefix -I,$(INCLUDE_DIR))

# CPPFLAGS ?= $(INC_FLAGS) -MMD -MP

# $(INSTALL_DIR)/$(TARGET): $(OBJECTS_FILES)
# 	$(CC) $(CPPFLAGS) $(OBJECTS_FILES) -o $@

# .PHONY: clean

# clean:
# 	$(RM) $(INSTALL_DIR)/$(TARGET) $(OBJECTS_FILES) $(DEP_FILES)

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
SOURCE_FILES := $(shell find $(SRC_DIR) -name '*.cpp')
OBJECTS_FILES ?= $(SOURCE_FILES:.cpp=.o)

# Build
all: $(TARGET)

$(TARGET): $(OBJECTS_FILES)
	@echo $(OBJECTS_FILES)
	$(CC) -o $@ $^ $(CFLAGS)

# main.o: hello.h

# %.o: %.c
# 	$(CC) -o $@ -c $< $(CFLAGS)

# .PHONY: clean mrproper

clean:
	rm -rf $(SRC_DIR)/*.o

# mrproper: clean
# 	rm -rf $(TARGET)
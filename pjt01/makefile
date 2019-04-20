CXX      := -g++
#CXXFLAGS := -pedantic-errors -Wall -Wextra -Werror
#CXXFLAGS := -Wall -Wextra -Werror
CXXFLAGS := -std=c++17 -Wall -Wextra
#LDFLAGS  := -L/usr/lib -lstdc++ -lm -lws2_32 -pthread
LDFLAGS  := -lws2_32 -pthread
BUILD    := ./build
OBJ_DIR  := $(BUILD)/objects
APP_DIR  := $(BUILD)/apps
#TARGET   := s.exe
TARGET   := test01.exe

INCLUDE  := -Iinclude 
INCLUDE  += -I.

SKIP_FILE := $(wildcard Test*.cpp)
#SKIP_FILE += c.cpp
SKIP_FILE += s.cpp c.cpp s1.cpp
SRC      :=                      \
	$(wildcard src/module1/*.cpp) \
	$(wildcard src/module2/*.cpp) \
	$(wildcard src/module3/*.cpp) \
	$(wildcard src/*.cpp)         \
	$(wildcard *.cpp)
SRC		:= $(filter-out $(SKIP_FILE) , $(SRC))

#OBJECTS := $(SRC:%.cpp=$(OBJ_DIR)/%.o)
#OBJECTS := $(SRC:%.cpp=$(OBJ_DIR)/%.o)
OBJECTS := $(TARGET:%.exe=$(OBJ_DIR)/%.o)
#OBJECTS += $(OBJ_DIR)/test01.o

all: init $(APP_DIR)/$(TARGET) deploy_current

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $@ -c $<

$(APP_DIR)/$(TARGET): $(OBJECTS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $(APP_DIR)/$(TARGET) $(OBJECTS) $(LDFLAGS) 

.PHONY: all build clean debug release

init:
	@mkdir -p $(APP_DIR)
	@mkdir -p $(OBJ_DIR)

debug: CXXFLAGS += -DDEBUG -g
debug: all

release: CXXFLAGS += -O2
release: all

deploy_current:
	@cp $(APP_DIR)/$(TARGET) $(TARGET)
	@echo copy from $(APP_DIR)/$(TARGET) to $(TARGET)

clean:
	-@rm -rvf $(OBJ_DIR)/*
	-@rm -rvf $(APP_DIR)/*
	-@rm -vf $(TARGET)

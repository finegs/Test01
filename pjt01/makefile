CXX      := -g++
#CXXFLAGS := -pedantic-errors -Wall -Wextra -Werror
CXXFLAGS := -std=c++1y -Wall -Wextra -Werror -Wno-unused-parameter
#LDFLAGS  := -L/usr/lib -lstdc++ -lm -lws2_32 -pthread
LDFLAGS  := -lws2_32 -pthread
BUILD    := build
OBJ_DIR  := $(BUILD)/objects
APP_DIR  := $(BUILD)/apps
#TARGET   := s.exe
TARGET   := t.exe
INCLUDE  := -Iinclude -I.

BOOST_HOME := G:/Programs/boost/boost
BOOST_INC := $(BOOST_HOME)/../boost_inc
BOOST_LIB := $(BOOST_HOME)/lib

INCLUDE +=  -I$(BOOST_INC)
LDFLAGS +=  -L$(BOOST_LIB)


SKIP_FILE := $(wildcard Test*.cpp)
#SKIP_FILE += c.cpp
SKIP_FILE += s.cpp c.cpp s1.cpp
#SRC      :=                      \
	$(wildcard src\module1\*.cpp) \
	$(wildcard src\module2\*.cpp) \
	$(wildcard src\module3\*.cpp) \
	$(wildcard src\*.cpp)         \
	$(wildcard *.cpp)
#SRC		:= $(filter-out $(SKIP_FILE) , $(SRC))

SRC 	:= $(TARGET:%.exe=%.cpp)
SRC		+= u.cpp mipc.cpp

#OBJS := $(SRC:%.cpp=$(OBJ_DIR)/%.o)
#OBJS := $(TARGET:%.exe=$(OBJ_DIR)/%.o)
OBJS := $(SRC:%.cpp=$(OBJ_DIR)/%.o)

all: build $(APP_DIR)/$(TARGET) release_this

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $@ -c $<

$(APP_DIR)/$(TARGET): $(OBJS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $(APP_DIR)/$(TARGET) $(OBJS) $(LDFLAGS) 

.PHONY: all build clean debug release

build:
	@mkdir -p $(APP_DIR)
	@mkdir -p $(OBJ_DIR)

debug: CXXFLAGS += -DDEBUG -g
debug: all

release: CXXFLAGS += -O2
release: all

release_this:
	@cp $(APP_DIR)/$(TARGET) $(TARGET)
	@echo copy from $(APP_DIR)/$(TARGET) to $(TARGET)

clean:
	-@rm -rf $(OBJ_DIR)/*
	-@rm -rf $(APP_DIR)/*
	-@rm -rf $(TARGET)

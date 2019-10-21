CXX      := -g++
#CXXFLAGS := -pedantic-errors -Wall -Wextra -Werror
#CXXFLAGS := -std=c++17 -Wall -Wextra -Werror -static
CXXFLAGS := -std=c++17 -Wall -Wextra
#LDFLAGS  := -L/usr/lib -lstdc++ -lm -lws2_32 -pthread
LDFLAGS  := -lws2_32 -pthread
BUILD    := build
OBJ_DIR  := $(BUILD)\objs
APP_DIR  := $(BUILD)\apps
#TARGET   := aa.exe
INCLUDE  := -I include
SKIP_FILE := $(wildcard Test*.cpp)
#SKIP_FILE += c.cpp
SKIP_FILE += b.cpp c.cpp s1.cpp
SRC      :=                      \
	$(wildcard src/module1/*.cpp) \
	$(wildcard src/module2/*.cpp) \
	$(wildcard src/module3/*.cpp) \
	$(wildcard src/*.cpp)         \
	$(wildcard *.cpp)
SRC		:= $(filter-out $(SKIP_FILE) , $(SRC))

ifeq ($(strip $(TARGET)),)
	ifeq ($(OS), Windows_NT)
		TARGET += aa.exe
		SRC:=$(TARGET:%.exe=%.cpp)
	else
		TARGET  := aa
		SRC := $(TARGET:%=%.cpp)
	endif
else
	ifeq ($(OS), Windows_NT)
		SRC := $(TARGET:%.exe=%.cpp)
	else
		SRC := $(TARGET:%=%.cpp)
	endif
endif


#OBJECTS := $(SRC:%.cpp=$(OBJ_DIR)/%.o)
OBJECTS := $(TARGET:%.exe=$(OBJ_DIR)/%.o)

all: build $(APP_DIR)/$(TARGET) release_this


#	@mkdir -p $(@D)
$(OBJ_DIR)/%.o: %.cpp
	@IF NOT EXIST $(@D) mkdir $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $@ -c $<


#	@mkdir -p $(@D)
$(APP_DIR)/$(TARGET): $(OBJECTS)
	@IF NOT EXIST $(@D) mkdir $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $(APP_DIR)/$(TARGET) $(OBJECTS) $(LDFLAGS) 

.PHONY: all build clean debug release

#build:
	#@mkdir -p $(APP_DIR)
	#@mkdir -p $(OBJ_DIR)

build:
	@IF NOT EXIST $(APP_DIR) mkdir $(APP_DIR)
	@IF NOT EXIST $(OBJ_DIR) mkdir $(OBJ_DIR)


debug: CXXFLAGS += -DDEBUG -g
debug: all

release: CXXFLAGS += -O2
release: all

release_this:
#	@copy /Y $(APP_DIR)/$(TARGET) $(TARGET)
	@copy /Y $(APP_DIR)\$(TARGET) $(TARGET)
#	@echo copy from $(APP_DIR)/$(TARGET) to $(TARGET)

clean:
#	-@rm -rvf $(OBJ_DIR)/*
#	-@rm -rvf $(APP_DIR)/*
#	-@rm -vf $(TARGET)
	@echo starting clean 
	@IF EXIST $(OBJ_DIR) del /S /F /Q $(OBJ_DIR)\*.o
	@IF EXIST $(APP_DIR) del /S /F /Q $(APP_DIR)\$(TARGET)
	@IF EXIST $(TARGET) del /F /Q $(TARGET)
	@echo complete clean


CXX      := -g++

CXXFLAGS := -std=c++17
CXXFLAGS += -Wall 
CXXFLAGS += -Wextra 
CXXFLAGS += -DUSE_MSTR_TOK=1 
CXXFLAGS += -DUSE_LOCAL_TIME=true

ifeq ($(OS), Windows_NT)
	xNIX_HEADER := 0
else
	xNIX_HEADER := 1
endif

#xNIX_HEADER := $(shell [ -e /usr/include ] && echo 1|| echo 0 )


LDFLAGS  := -L /usr/local/lib 
LDFLAGS  += -pthread 
LDFLAGS  += -lm 
LDFLAGS  += -lcrypt 
LDFLAGS  += -lrt

ifeq ($(OS),Windows_NT) 
	LDFLAGS  := -lws2_32 -pthread
	INCLUDE  := -I include
else
	ifeq ($(USE_WIRINGPI),1)
		LDFLAGS  += -lwiringPi
	endif
	LDFLAGS  := -L /usr/local/lib -pthread -lwiringPi -lm -lcrypt -lrt
	INCLUDE  := -I include -I /usr/local/include
endif
BUILD    := build

ifeq ($(OS),Windows_NT)
	OBJ_DIR  := $(BUILD)\objs
	APP_DIR  := $(BUILD)\apps
else
	OBJ_DIR  := $(BUILD)/objs
	APP_DIR  := $(BUILD)/apps
endif

INCLUDE := -I include
INCLUDE += -I /usr/local/include

SRCS_INC := mutil.cpp

#skip files
SKIP_FILE := $(wildcard Test*.cpp)
SKIP_FILE += b.cpp c.cpp s1.cpp
#SRC      :=                      \
#	$(wildcard src/module1/*.cpp) \
#	$(wildcard src/module2/*.cpp) \
#	$(wildcard src/module3/*.cpp) \
#	$(wildcard src/*.cpp)         \
#	$(wildcard *.cpp)
#SRC		:= $(filter-out $(SKIP_FILE) , $(SRC))

#include other source files

TARGET_DEFAULT = aa

ifeq ($(OS),Windows_NT)

	ifeq ($(strip $(TARGET)),)
		TARGET = $(TARGET_DEFAULT:%=%.exe)
	endif

	SRC_TARGET :=$(TARGET:%.exe=%.cpp)
	#added by SGK 20200215
#	ifeq ($(UNAMEO), Msys)
	ifeq ($(xNIX_HEADER), 1)
		CLN := clean_oth
		BLD := build_oth
		RELEASE_APP := release_app_oth
	else
		CLN := clean_win
		BLD := build_win
		RELEASE_APP := release_app_win
	endif
else
	ifeq ($(strip $(TARGET)),)
		TARGET =$(TARGET_DEFAULT)
	endif
	ifeq ($(strip $(target)),)
		TARGET:=$(TARGET_DEFAULT)
	else
		TARGET:=$(target)
	endif

	SRC_TARGET :=$(TARGET:%=%.cpp)
	CLN:=clean_oth
	BLD:=build_oth
	RELEASE_APP:=release_app_oth
endif

SRCS = $(SRCS_INC)	
SRCS += $(SRC_TARGET)	

OBJS := $(SRCS:%.cpp=%.o)

#SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
#OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))


all: $(TARGET) example_main

#	@mkdir -p $(@D)
#$(OBJS):$(SRCS)
%.o:%.cpp
#	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $@ -c $<
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $? -o $@

#	@mkdir -p $(@D)
$(TARGET):$(OBJS)
	$(CXX) $(INCLUDE) $(LDFLAGS) -o $@ $^

.PHONY: clean all

build_win:
	@IF NOT EXIST $(BUILD) ( mkdir $(BUILD) )
	@IF NOT EXIST $(APP_DIR) ( mkdir $(APP_DIR) )
	@IF NOT EXIST $(OBJ_DIR) ( mkdir $(OBJ_DIR) )

build_oth:
	@mkdir -p $(BUILD)
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(APP_DIR)


debug: CXXFLAGS += -DDEBUG -g
debug: all

release: CXXFLAGS += -O2
release: all

release_app_win:
	copy /Y $(APP_DIR)\$(TARGET) $(TARGET)

release_app_oth:
	@cp $(APP_DIR)/$(TARGET) $(TARGET)

clean:$(CLN)

clean_win: clean_example_dll
	@echo starting $@
	-@del /F /Q *.o
	-@del /F /Q $(TARGET)
#	-@IF EXIST $(OBJ_DIR) ( del /S /F /Q $(OBJ_DIR)\*.o )
#	-@IF EXIST $(APP_DIR) ( del /S /F /Q $(APP_DIR)\$(TARGET) )
#	-@IF EXIST $(TARGET) ( del /F /Q $(TARGET) )
	@echo complete $@

clean_oth:
	@echo starting clean 
	@rm -rf *.o
	@rm -rf $(TARGET)
	@echo complete clean

uninstall_win:
	@echo starting $(@)
	@if exist $(TARGET) ( del /F /Q $(TARGET))
	@echo complete $(@)

uninstall_oth:
	@echo starting $(@)
	@rm -f $(TARGET)
	@echo complete $(@)

example_dll:
	$(CXX) -DBUILDING_EXAMPLE_DLL -c $(@:%=%.cpp)
	$(CXX) -shared -o $(@:%=%.dll) $(@:%=%.o) -Wl,--out-implib,libexample_dll.a

example_main: example_dll
	$(CXX) -c $(@:%=%.cpp) -o $(@:%=%.o)
	$(CXX) -o $@ $(@:%=%.o) -L. -l$< 

clean_example_dll:
	@echo starting $@
	-@del /S /Q *.dll
	-@del /S /Q *.a
	@echo complete $@

help:
	@echo off
	@echo debug
	@echo $(TARGET) (default)
	@echo release
	@echo clean_win
	@echo clean_oth
	@echo build_dll			::  Build DLL for windows
	@echo dll_main	:: Build Main with DLL

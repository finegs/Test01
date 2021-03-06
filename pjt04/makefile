######################  Init All Variables ###############################################
CXX      := g++ 
BUILD     := build
APP_DIR   := $(BUILD)/apps
OBJ_DIR   := $(BUILD)/objects
DEFAULT_TARGET := testMain

ifeq ($(OS),Windows_NT)
	RM = del /Q /F
	RRM = rmdir /Q /S
	MKDIR = mkdir
	MKDIRS = mkdirs_win
	OSFLAG += -D WIN32
	ifeq ($(PROCESSOR_ARCHITECTURE),AMD64)
		OSFLAG += -D AMD64
	endif
	ifeq ($(PROCESSOR_ARCHITECTURE),x86)
		OSFLAG += -D IA32
	endif
else
	RM = rm -f
	RRM = rm -f -r
	MKDIR = mkdir -p
	MKDIRS = mkdirs_other
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Linux)
		OSFLAG += -D LINUX
	endif
	ifeq ($(UNAME_S),Darwin)
		OSFLAG += -D OSX
	endif
		UNAME_P := $(shell uname -p)
	ifeq ($(UNAME_P),x86_64)
		OSFLAG += -D AMD64
	endif
	ifneq ($(filter %86,$(UNAME_P)),)
		OSFLAG += -D IA32
	endif
	ifneq ($(filter arm%,$(UNAME_P)),)
		OSFLAG += -D ARM
	endif
endif


OSFLAG    := 
ifeq ($(OS), Windows_NT)
	OSFLAG += -D WIN32
endif

ifeq ($(strip $(TARGET)),)
	ifeq ($(OS), Windows_NT)
		TARGET += $(DEFAULT_TARGET)
		SRC:=$(TARGET:%=%.cpp)
	else
		TARGET  := $(DEFAULT_TARGET)
		SRC := $(TARGET:%=%.cpp)
	endif
else
	ifeq ($(OS), Windows_NT)
		SRC := $(TARGET:%=%.cpp)
	else
		SRC := $(TARGET:%=%.cpp)
	endif
endif

SRC_OTHER := testLib.cpp

SRC       += $(SRC_OTHER)

#SKIP_FILE := $(wildcard Test*.cpp)
#SKIP_FILE += s.cpp
#SKIP_FILE += c.cpp
#SKIP_FILE += s1.cpp

#CXXFLAGS := -pedantic-errors -Wall -Wextra -Werror
#CXXFLAGS := -std=c++1y -Wall -Wextra -Werror -Wno-unused-parameter
#LDFLAGS  := -L/usr/lib -lstdc++ -lm -lws2_32 -pthread
CXXFLAGS  := -std=c++17

CXXFLAGS  += -Wall
CXXFLAGS  += -Wextra
CXXFLAGS  += -Wno-unused-parameter

INC_PATH  += -I.
INC_PATH  += -Iinc    

LFLAGS    :=
LDFLAGS   :=

ifeq ($(OS), Windows_NT)
#	LDFLAGS  := -Wl, -Bstatic
    LDFLAGS  := -static
	LDFLAGS  += -lws2_32
#	LDFLAGS  += -Wl,-Bdynamic
else
	LDFLAGS  += -lrt
	LDFLAGS  += -ldl
endif


#LDFLAGS  += -Wl,-Bdynamic
LDFLAGS   += -lstdc++
LDFLAGS   += -lm
LDFLAGS   += -pthread

#LDFLAGS   += -lwsock32

ifeq ($(OS), Windows_NT)
	LIB_PATH  := -L$(MINGW_HOME)/x86_64-w64-mingw32/lib
else
	LIB_PATH  := 
endif

################## BOOST #################################
BOOST_INC := $(BOOST_HOME)/../boost_inc
BOOST_LIB := $(BOOST_HOME)/lib

INC_PATH  += -I$(BOOST_INC)
LIB_PATH  += -L$(BOOST_LIB)

##########################################################
OBJS 	:= $(SRC:%.cpp=$(OBJ_DIR)/%.o)
##########################################################

#################  all (Default)      ######

all: init  $(TARGET)

##########################################################

init: ${MKDIRS}

#################             Compile            ######
$(OBJ_DIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INC_PATH) -c $< -o $@
##########################################################

##########          Link               ######
$(TARGET): $(OBJS)
#	$(CXX) $(CXXFLAGS) $(INC_PATH) -o $(APP_DIR)/$(TARGET) $(OBJS) $(LDFLAGS) 
	$(CXX) $(LIB_PATH) $(OBJS) $(LDFLAGS) -o $@
 
##########################################################

##########             Build All always SRC or SRC_OTHERS is changed without target removed ########
.PHONY: all build clean debug release

##########################################################

##########             Make Directory to store obj, target files ######################
mkdirs_win:
	-@if NOT EXIST "$(APP_DIR)" mkdir "$(APP_DIR)"
	-@if NOT EXIST "$(OBJ_DIR)" mkdir "$(OBJ_DIR)"

mkdirs_other:
	-@if [ ! -d "$(APP_DIR)" ]; then \
		mkdir -p  "$(APP_DIR)";    \
	fi
	-@if [ ! -d "$(OBJ_DIR)" ]; then \
		mkdir -p "$(OBJ_DIR)";     \
	fi
##########################################################

debug: CXXFLAGS += -DDEBUG -g
debug: all

##########################################################

release: CXXFLAGS += -O2
release: all

##########################################################

##########            Copy Target File to current path for easy to test run #########################
release_this:
	cp $(TARGET) $(APP_DIR)/$(TARGET)

##########################################################

##########            Clean Target, Object and Current Path Target Files    #########################
clean:
	-@echo Starting clean.
	-@$(RM) "$(TARGET)"
	-@IF EXIST "$(OBJ_DIR)" $(RM) "$(OBJ_DIR)\*.*"
	-@IF EXIST "$(APP_DIR)" $(RM) "$(APP_DIR)\*.*"
	-@echo Clean done.

##########################################################



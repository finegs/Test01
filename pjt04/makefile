######################  Init All Variables ###############################################
CXX      := g++ 
BUILD     := build
APP_DIR   := $(BUILD)/apps
OBJ_DIR   := $(BUILD)/objects

ifeq ($(OS),Windows_NT)
	RM = del /Q /F
	RRM = rmdir /Q /S
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
		TARGET += t.exe
		SRC:=$(TARGET:%.exe=%.cpp)
	else
		TARGET  := t
		SRC := $(TARGET:%=%.cpp)
	endif
else
	ifeq ($(OS), Windows_NT)
		SRC := $(TARGET:%.exe=%.cpp)
	else
		SRC := $(TARGET:%=%.cpp)
	endif
endif

#SRC   := $(TARGET:%=%.cpp)

SRC_OTHER := u.cpp mipc.cpp uu1.cpp

SRC       += $(SRC_OTHER)

SKIP_FILE := $(wildcard Test*.cpp)
SKIP_FILE += s.cpp
SKIP_FILE += c.cpp
SKIP_FILE += s1.cpp

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

all: $(TARGET)


##########################################################

#################             Compile            ######
$(OBJ_DIR)/%.o: %.cpp
	-@if NOT EXIST "$(@D)" . \
		mkdir -p "$(@D)".       \
	fi
	$(CXX) $(CXXFLAGS) $(INC_PATH) -o $@ -c $<

##########################################################

##########          Link               ######
$(TARGET): $(OBJS)
	-@if NOT EXIST "$(@D)" . \
		mkdir -p "$(@D)".      \
	fi
#	$(CXX) $(CXXFLAGS) $(INC_PATH) -o $(APP_DIR)/$(TARGET) $(OBJS) $(LDFLAGS) 
#   -lws2_32, -lwsock32 should be added to end of LDFLAGS and end of link command 	
	$(CXX) -o $@ $(LIB_PATH) $(OBJS) $(LDFLAGS)
 
##########################################################

##########             Build All always SRC or SRC_OTHERS is changed without target removed ########
.PHONY: all build clean debug release

##########################################################

##########             Make Directory to store obj, target files ######################
mkdirs:
	-@if NOT EXIST "$(APP_DIR)" .\
		mkdir -p "$(APP_DIR)".     \
	fi
	-@if NOT EXIST "$(OBJ_DIR)" .\
		mkdir -p "$(OBJ_DIR)".     \
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
	-@$(RM) "$(OBJ_DIR)\*.*"
	-@$(RM) "$(APP_DIR)\*.*"
#
#	-@rm -rf "$(OBJ_DIR)"/*.*
#	-@rm -rf "$(APP_DIR)"/*.*
#	-@if EXIST "$(TARGET)"  \
#		del /F "$(TARGET)".     \
#	fi
	-@echo Clean done.

##########################################################



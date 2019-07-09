######################  Init All Variables ###############################################
CXX      := g++ #CXXFLAGS := -pedantic-errors -Wall -Wextra -Werror
#CXXFLAGS := -std=c++1y -Wall -Wextra -Werror -Wno-unused-parameter
#LDFLAGS  := -L/usr/lib -lstdc++ -lm -lws2_32 -pthread
BUILD     := build
APP_DIR   := $(BUILD)/apps
OBJ_DIR   := $(BUILD)/objects

ifeq ($(strip $(TARGET)),)
	TARGET  := t.exe
endif

SRC 	  := $(TARGET:%.exe=%.cpp)
SRC_OTHER := u.cpp mipc.cpp uu1.cpp

SRC       += $(SRC_OTHER)

SKIP_FILE := $(wildcard Test*.cpp)
SKIP_FILE += s.cpp
SKIP_FILE += c.cpp
SKIP_FILE += s1.cpp

CXXFLAGS  := -std=c++17
CXXFLAGS  += -Wall
CXXFLAGS  += -Wextra
CXXFLAGS  += -Wno-unused-parameter

INC_PATH  += -I.
INC_PATH  += -Iinc    


LDFLAGS   :=
LDFLAGS   += -lm
LDFLAGS   += -pthread
LDFLAGS   += -lws2_32
#LDFLAGS   += -lwsock32

LIB_PATH  := -L$(MINGW_HOME)/x86_64-w64-mingw32/lib

################## BOOST #################################

#BOOST_HOME := G:/Programs/boost/boost
BOOST_INC := $(BOOST_HOME)/../boost_inc
BOOST_LIB := $(BOOST_HOME)/lib

INC_PATH  += -I$(BOOST_INC)
LIB_PATH  += -L$(BOOST_LIB)


##########################################################

#OBJS := $(TARGET:%.exe=$(OBJ_DIR)/%.o)
OBJS 	:= $(SRC:%.cpp=$(OBJ_DIR)/%.o)

##########################################################

#################  all (Default)      ######

all: mkdirs $(APP_DIR)/$(TARGET) release_this

##########################################################

#################             Compile            ######
$(OBJ_DIR)/%.o: %.cpp
	if [ ! -d $(@D) ]; then \
		mkdir -p $(@D);     \
	fi
	$(CXX) $(CXXFLAGS) $(INC_PATH) -o $@ -c $<

##########################################################

##########          Link               ######
$(APP_DIR)/$(TARGET): $(OBJS)
	if [ ! -d $(@D) ]; then \
		mkdir -p $(@D);     \
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
	if [ ! -d "$(APP_DIR)" ]; then \
		mkdir -p "$(APP_DIR)";     \
	fi
	if [ ! -d "$(OBJ_DIR)" ]; then \
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
	@cp $(APP_DIR)/$(TARGET) $(TARGET)
	@echo cp from $(APP_DIR)/$(TARGET) to $(TARGET)

##########################################################

##########            Clean Target, Object and Current Path Target Files    #########################
clean:
	@rm -rf $(OBJ_DIR)/*.*
	@rm -rf $(APP_DIR)/*.*
	@rm $(TARGET)

##########################################################

###################################################################################
###################################################################################


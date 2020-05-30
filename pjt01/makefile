######################  Init All Variables ###############################################
CXX      		:= g++ 
BUILD     		:= build

DEFAULT_TARGET 	:= t

ifeq ($(OS),Windows_NT)
	RM = del /Q /F /S
	RRM = rd /Q /S
	OSFLAG += -D WIN32
	MKDIR = mkdir
	ifeq ($(PROCESSOR_ARCHITECTURE),AMD64)
		OSFLAG += -D AMD64
	endif
	ifeq ($(PROCESSOR_ARCHITECTURE),x86)
		OSFLAG += -D IA32
	endif

	APP_DIR   := $(BUILD)\apps
	OBJ_DIR   := $(BUILD)\objects

	MKDIRS    := MKDIRS_WIN
	CLEANS    := CLEANS_WIN
else

	RM = rm -f
	RRM = rm -f -r
	MKDIR = mkdir -p
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

	APP_DIR   := $(BUILD)/apps
	OBJ_DIR   := $(BUILD)/objects

	MKDIRS    := MKDIRS_OTHER
	CLEANS	  := CLEANS_OTHER
endif


OSFLAG    := 
ifeq ($(OS),Windows_NT)
	OSFLAG += -D WIN32
endif

ifeq ($(strip $(TARGET)),)
	ifneq ($(strip $(target)),)
		TARGET=$(target)
	endif
endif

ifeq ($(strip $(TARGET)),)
	TARGET  := $(DEFAULT_TARGET)
	SRC 	:= $(TARGET:%=%.cpp)
else
	SRC 	:= $(TARGET:%=%.cpp)
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
CXXFLAGS  += -DUSE_BOOST

INC_PATH  += -I.
INC_PATH  += -Iinc
ifeq ($(OS),Windows_NT)
	ifeq ($(BOOST_HOME),)
		INC_PATH	+= -ID:\Programs\boost\1.72\include\boost-1_73
	endif
else
	ifeq ($(BOOST_HOME),)
		BOOST_HOME = /d/Programs/boost/1.72
	endif
endif

LFLAGS    		:=
LDFLAGS   		:=

LDFLAGS   += -lstdc++
LDFLAGS   += -lm
LDFLAGS   += -pthread
#LDFLAGS   += -lwsock32
# -lws2_32 must be in end of LDFLAGS ( by SGK 2020516) to prevent link error : 'undefined reference to
#  `__imp_WSAStartup`
ifeq ($(OS),Windows_NT)
    LDFLAGS  += -static
    LDFLAGS  += -lws2_32
#	LDFLAGS  += -Wl,-Bdynamic
else
    LDFLAGS  += -lrt
endif


ifeq ($(OS),Windows_NT)
	LIB_PATH  := -L$(MINGW_HOME)/x86_64-w64-mingw32/lib
else
	LIB_PATH  := 
endif

################## BOOST #################################

ifeq ($(OS),Windows_NT)
	ifneq ($(BOOST_HOME),)
		BOOST_INC := $(BOOST_HOME)/../boost_inc
		BOOST_LIB := $(BOOST_HOME)/lib
	endif
endif

ifneq ($(BOOST_INC),) 
	INC_PATH  		+= -I$(BOOST_INC)
endif
ifneq ($(BOOST_LIB),)
	LIB_PATH  		+= -L$(BOOST_LIB)
endif

##########################################################
OBJS 			:= $(SRC:%.cpp=$(OBJ_DIR)/%.o)
##########################################################

#################  all (Default)      #########

all: MK_DIRS $(TARGET)

##########################################################

################# Compile ######
$(OBJ_DIR)/%.o:%.cpp
#	$(MK_DIRS)
#	$(CXX) $(CXXFLAGS) $(INC_PATH) -c $? -o $@ 
	$(CXX) $(CXXFLAGS) $(INC_PATH) -c $? -o $@ 

##########################################################

######################## Link ######
$(TARGET): $(OBJS)
#	$(MK_DIRS)
	$(CXX) $(LIB_PATH) $^ -o $@ $(LDFLAGS)

##########################################################

##########             Build All always SRC or SRC_OTHERS is changed without target removed ########
.PHONY: all build CLEANS debug release MK_DIRS

##########################################################

##########             Make Directory to store obj, target files ######################
MK_DIRS:$(MKDIRS)
	-@echo Complete $@

MKDIRS_WIN:
	-@echo Start $@
	-@IF NOT EXIST $(APP_DIR) ( $(MKDIR) $(APP_DIR) )
	-@IF NOT EXIST $(OBJ_DIR) ( $(MKDIR) $(OBJ_DIR) )
	-@echo Complete $@

MKDIRS_OTHER:
	-@echo Start $@
	-@test -d $(APP_DIR) || $(MKDIR) $(APP_DIR)
	-@test -d $(OBJ_DIR) || $(MKDIR) $(OBJ_DIR)
	-@echo Complete $@

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
clean: $(CLEANS)
	-@echo Complete $@

CLEANS_WIN:
	-@echo Starting $@
	-@IF EXIST $(TARGET) ( $(RM) $(TARGET) )
	-@IF EXIST $(OBJ_DIR) ( $(RM) $(OBJ_DIR)\* )
	-@IF EXIST $(APP_DIR) ( $(RM) $(APP_DIR)\* )
	-@echo Complete $@

CLEANS_OTHER:
	-@echo Starting $@
	-@if [ -f $(TARGET) ]; then $(RM) $(TARGET); fi 
	-@if [ -d $(OBJ_DIR) ]; then $(RM) $(OBJ_DIR)/*.o; fi 
	-@if [ -d $(APP_DIR) ]; then $(RM) $(APP_DIR)/$(TARGET); fi 
	-@echo Complete $@
	-@echo Complete $@

##########################################################


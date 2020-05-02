CXX      := -g++
#CXXFLAGS := -pedantic-errors -Wall -Wextra -Werror
#CXXFLAGS := -std=c++17 -Wall -Wextra -Werror -static
CXXFLAGS := -std=c++17 -Wall -Wextra
#LDFLAGS  := -L/usr/lib -lstdc++ -lm -lws2_32 -pthread

ifeq ($(OS), Windows_NT)
	LDFLAGS  := -lws2_32 -pthread
else
	LDFLAGS  := -pthread
endif
BUILD    := build


ifeq ($(OS), Windows_NT)
	OBJ_DIR  := $(BUILD)\objs
	APP_DIR  := $(BUILD)\apps
else
	OBJ_DIR  := $(BUILD)/objs
	APP_DIR  := $(BUILD)/apps
endif

ifeq ($(OS), Windows_NT)
	DEFAULT_TARGET := b.exe
else
	DEFAULT_TARGET := b
endif

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


ifneq ($(strip $(target)),)
	TARGET:=$(target)
endif

ifeq ($(strip $(TARGET)),)
	ifeq ($(OS), Windows_NT)
		TARGET := $(DEFAULT_TARGET)
		SRC:=$(TARGET:%.exe=%.cpp)
		BLD:=BUILD_WIN
		CLN:=clean_win
		release_app:=release_app_win
	else
		TARGET  := aa
		SRC := $(TARGET:%=%.cpp)
		BLD:=BUILD_OTH
		CLN:=clean_oth
		release_app:=release_app_oth
	endif
else
	ifeq ($(OS), Windows_NT)
		SRC := $(TARGET:%.exe=%.cpp)
		BLD:=BUILD_WIN
		CLN:=clean_win
		release_app:=release_app_win
	else
		SRC := $(TARGET:%=%.cpp)
		BLD:=BUILD_OTH
		CLN:=clean_oth
		release_app:=release_app_oth
	endif
endif

#SRC_EXIST := $( wildcard $(SRC) )
##ifneq (,$(wildcard $(SRC)))
#ifeq ($(strip $(SRC_EXIST)),)
##	@echo ##### Source is $(SRC) #####
##	-@echo Source is $(SRC)
##else
#	$(info "Source is $(SRC)")
#	CXX:=-gcc
#	CXXFLAGS := -Wall -Wextra
#	ifeq ($(OS), Windows_NT)
#		SRC:=$(TARGET:%.exe=%.c)
#	else
#		SRC:=$(TARGET:%=%.c)
#	endif
#endif


#OBJECTS := $(SRC:%.cpp=$(OBJ_DIR)/%.o)

ifeq ($(OS), Windows_NT)
	OBJECTS := $(TARGET:%.exe=$(OBJ_DIR)/%.o)
else
	OBJECTS := $(TARGET:%=$(OBJ_DIR)/%.o)
endif

#all: $(BLD) build $(APP_DIR)/$(TARGET) release_this
all: $(BLD) $(APP_DIR)/$(TARGET) $(release_app)


#	@mkdir -p $(@D)
#$(OBJ_DIR)/%.o: %.cpp
#	@IF NOT EXIST $(@D) mkdir $(@D)
#	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $@ -c $<

#	@mkdir -p $(@D)
$(OBJECTS): $(SRC)
#	@IF NOT EXIST $(@D) mkdir $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $@ -c $(SRC)

#	@mkdir -p $(@D)
$(APP_DIR)/$(TARGET): $(OBJECTS)
#	@IF NOT EXIST $(@D) mkdir $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $(APP_DIR)/$(TARGET) $(OBJECTS) $(LDFLAGS) 

.PHONY: all build clean debug release

#build:
	#@mkdir -p $(APP_DIR)
	#@mkdir -p $(OBJ_DIR)

build:
	ifeq ($(OS), Windows_NT)
		IF NOT EXIST $(APP_DIR) mkdir $(APP_DIR)
		IF NOT EXIST $(OBJ_DIR) mkdir $(OBJ_DIR)
	else
		md -p $(APP_DIR)
		md -p $(OBJ_DIR)

BUILD_WIN:
	IF NOT EXIST $(APP_DIR) mkdir $(APP_DIR)
	IF NOT EXIST $(OBJ_DIR) mkdir $(OBJ_DIR)

BUILD_OTH:
	mkdir -p $(APP_DIR)
	mkdir -p $(OBJ_DIR)



debug: CXXFLAGS += -DDEBUG -g
debug: all

release: CXXFLAGS += -O2
release: all

release_app_win:
	@copy /Y $(APP_DIR)\$(TARGET) $(TARGET)

release_app_oth:
	@cp $(APP_DIR)/$(TARGET) $(TARGET)

clean:$(CLN)

clean_win:
#	-@rm -rvf $(OBJ_DIR)/*
#	-@rm -rvf $(APP_DIR)/*
#	-@rm -vf $(TARGET)
	@echo starting clean 
	@IF EXIST $(OBJ_DIR) del /S /F /Q $(OBJ_DIR)\*.o
	@IF EXIST $(APP_DIR) del /S /F /Q $(APP_DIR)\$(TARGET)
	@IF EXIST $(TARGET) del /F /Q $(TARGET)
	@echo complete clean

clean_oth:
#	-@rm -rvf $(OBJ_DIR)/*
#	-@rm -rvf $(APP_DIR)/*
#	-@rm -vf $(TARGET)
	@echo starting clean 
	@rm -rf $(OBJ_DIR)/*.o
	@rm -rf $(APP_DIR)/$(TARGET)
	@rm -rf $(TARGET)
	@echo complete clean


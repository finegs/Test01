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
$(APP_DIR)/$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $(APP_DIR)/$(TARGET) $(OBJECTS) $(LDFLAGS) 

#	@mkdir -p $(@D)
#$(OBJ_DIR)/%.o: %.cpp
#	@IF NOT EXIST $(@D) mkdir $(@D)
#	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $@ -c $<

#	@mkdir -p $(@D)
$(OBJECTS):
#	@IF NOT EXIST $(@D) mkdir $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $@ -c $(SRC)


.PHONY: clean all


BUILD_WIN:
	@IF NOT EXIST $(BUILD) ( mkdir $(BUILD) )
	@IF NOT EXIST $(APP_DIR) ( mkdir $(APP_DIR) )
	@IF NOT EXIST $(OBJ_DIR) ( mkdir $(OBJ_DIR) )

BUILD_OTH:
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

clean_win:
	@echo starting clean 
	@IF EXIST $(OBJ_DIR) ( del /S /F /Q $(OBJ_DIR)\*.o )
	@IF EXIST $(APP_DIR) ( del /S /F /Q $(APP_DIR)\$(TARGET) )
	@IF EXIST $(TARGET) ( del /F /Q $(TARGET) )
	@echo complete clean

clean_oth:
	@echo starting clean 
	@rm -rf $(OBJ_DIR)/*.o
	@rm -rf $(APP_DIR)/$(TARGET)
	@rm -f $(TARGET)
	@echo complete clean

uninstall_win:
	@echo starting $(@)
	@if exist $(TARGET) ( del /F /Q $(TARGET))
	@echo complete $(@)

uninstall_oth:
	@echo starting $(@)
	@rm -f $(TARGET)
	@echo complete $(@)


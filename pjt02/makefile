CXX      := -g++
#CXXFLAGS := -pedantic-errors -Wall -Wextra -Werror
#CXXFLAGS := -std=c++17 -Wall -Wextra -Werror -static
#CXXFLAGS := -std=c++17 -Wall -Wextra
CXXFLAGS := -std=c++17 -Wextra -g -DMYSTRTOK=1
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

INCLUDE  := -I include
SRC_INC  := mutil.cpp

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
SRC = $(SRC_INC)

ifeq ($(OS), Windows_NT)

	ifeq ($(strip $(TARGET)),)
		TARGET += aa.exe
	endif

	SRC+=$(TARGET:%.exe=%.cpp)
	CLN:=clean_win
	BLD:=build_win
	RELEASE_APP:=release_app_win
else
	ifeq ($(strip $(TARGET)),)
		TARGET  := aa
	endif

	SRC+=$(TARGET:%=%.cpp)
	CLN:=clean_oth
	BLD:=build_oth
	RELEASE_APP:=release_app_oth
endif

#objects for other source files
#OBJECTS = $(SRC:%.cpp=$(OBJ_DIR)/%.o)
OBJS    = $(SRC:%.cpp=%.o)


#all
all: $(TARGET)

#	@mkdir -p $(@D)
$(OBJS):$(SRC)
#	@IF NOT EXIST $(@D) mkdir $(@D)
#	@echo "SRS IS "$(SRC)
#	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $@ -c $<
#	$(CXX) -c $? $(CXXFLAGS) $(INCLUDE)
	$(CXX) -c $^ $(CXXFLAGS) $(INCLUDE)

#	@mkdir -p $(@D)
$(TARGET):$(OBJS)
	$(CXX) -o $@ $^ $(LDFLAGS) 

#	@mkdir -p $(@D)
#$(OBJ_DIR)/%.o: %.cpp
#	@IF NOT EXIST $(@D) mkdir $(@D)
#	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $@ -c $<

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
	@copy /Y $(APP_DIR)\$(TARGET) $(TARGET)

release_app_oth:
	@cp $(APP_DIR)/$(TARGET) $(TARGET)

clean:$(CLN)

clean_win:
	@echo starting clean
	@del /F /Q *.o
	@del /F /Q $(TARGET)
#	-@IF EXIST $(OBJ_DIR) ( del /S /F /Q $(OBJ_DIR)\*.o )
#	-@IF EXIST $(APP_DIR) ( del /S /F /Q $(APP_DIR)\$(TARGET) )
#	-@IF EXIST $(TARGET) ( del /F /Q $(TARGET) )
	@echo complete clean

clean_oth:
	@echo starting clean 
	@rm -rf *.o
	@rm -rf $(TARGET)
#	@rm -rf $(OBJ_DIR)/*.o
#	@rm -rf $(APP_DIR)/$(TARGET)
#	@rm -f $(TARGET)
	@echo complete clean

uninstall_win:
	@echo starting $(@)
	@if exist $(TARGET) ( del /F /Q $(TARGET))
	@echo complete $(@)

uninstall_oth:
	@echo starting $(@)
	@rm -f $(TARGET)
	@echo complete $(@)


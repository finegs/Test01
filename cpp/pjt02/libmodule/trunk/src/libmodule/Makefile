###############################
# Makefile ver 0.1 by greenfish
###############################

####################
# basic make command
####################

# make                           : debug build   (native)
# make debug                     : debug build   (native)
# make release                   : release build (native)
# make rebuild [debug, release]  : rebuild       (native)
# make clean [debug, release]    : clean

#############################
# set default compile options
#############################

CC         = gcc
STRIP      = strip
PLATFORM   = i686
CONFIG     = debug
LIBNAME    = libmodule.so
LIBCOMPILE = -fPIC
LIBLINK    = -shared -Wl,-soname,$(LIBNAME),--version-script=ld_conf.lds
TRUNK_DIR  = $(abspath ../..)
SRC_DIR    = $(TRUNK_DIR)/src
INC_DIR    = -I./ -I$(SRC_DIR)/inc -I$(SRC_DIR)/lib -I/usr/local/include
BUILD_DIR  = $(TRUNK_DIR)/build/linux/$(PLATFORM)/$(CONFIG)
TARGET     = $(BUILD_DIR)/$(LIBNAME)
CFLAGS     = -Wall $(INC_DIR)
LFLAGS     = -ldl
SYSROOT    = 

####################################
# get makefile command line argument
####################################

ifneq "$(findstring clean, $(MAKECMDGOALS))" ""
    ARG.CLEAN = 1
endif
ifneq "$(findstring release, $(MAKECMDGOALS))" ""
    ARG.RELEASE = 1
endif
ifneq "$(findstring debug, $(MAKECMDGOALS))" ""
    ARG.DEBUG = 1
endif
ifneq "$(findstring rebuild, $(MAKECMDGOALS))" ""
    ARG.REBUILD = 1
endif

#####################################
# DEBUG / RELEASE build option branch
#####################################

ifeq ($(ARG.RELEASE),1)
    # -----------------
    # for release build
    # -----------------
    CFLAGS    += -DNDEBUG -O2
    CONFIG    = release
else
    # ---------------
    # for debug build
    # ---------------
    CFLAGS    += -g -DDEBUG -O0
    CONFIG    = debug
endif

# ----------------------------------
# for native build (using local gcc)
# ----------------------------------
# example) 2.6.38-8-generic-i686
# in cygwin, uname -r has bracket form (ex, 2.7.0(0.306/5/3)),
#    replace bracket to _ to correct error "... near unexpected token `('"
KERNEL_RELEASE = $(shell uname -r)
DELIMETER      = -
MACHINE_TYPE   = $(shell uname -m)
BRACKET_LEFT   = (
BRACKET_RIGHT  = )
PLATFORM_TMP   = $(KERNEL_RELEASE)$(DELIMETER)$(MACHINE_TYPE)
PLATFORM_TMP1  = $(subst $(BRACKET_LEFT),_,$(PLATFORM_TMP))
PLATFORM       = native

##################
# makefile process
##################

.PHONY: debug release build clean rebuild PRE_BUILD POST_BUILD all

# make process scenario
BUILD_STEP = PRE_BUILD $(TARGET) POST_BUILD

# set makefile target and dependency
# to prevent "make: Nothing to be done for 'release'" warning,
# use @true keyword
ifeq ($(ARG.REBUILD),1)
    # under rebuild, do clean before build
    rebuild: | clean $(BUILD_STEP)
    debug: ; @true
    release: ; @true
else ifeq ($(ARG.CLEAN),1)
    # under clean, target has no rule to build
    release: ; @true
    debug: ; @true
else
	# under build release or debug, do build
    build: | $(BUILD_STEP)
    release: build
    debug: build
endif

#######
# macro
#######

CONVERT_SRC   = $(subst $(LIBMODULE.INTERMEDIATE_DIR),$(SRC_DIR),$(@:.o=.cpp))
CONVERT_BUILD = $(subst $(SRC_DIR),$(LIBMODULE.INTERMEDIATE_DIR),$(@:.o=.cpp))

###################
# compile file list
###################

# main source
SRC_MAIN  = libmodule/so_main.cpp
SRC_MAIN += libmodule/libmodule.cpp

# common library
SRC_LIB   = lib/a.cpp
SRC_LIB  += lib/b.cpp

# all compile source file list
LIBMODULE.TARGET = $(SRC_MAIN) $(SRC_LIB)

# compile meta-file to be in intermediate directory
LIBMODULE.INTERMEDIATE_DIR = $(BUILD_DIR)/intermediate/$(LIBNAME)

# compile meta-file list (.obj, .d)
LIBMODULE.OBJ = $(addprefix $(LIBMODULE.INTERMEDIATE_DIR)/, $(LIBMODULE.TARGET:.cpp=.o))
LIBMODULE.DEP = $(addprefix $(LIBMODULE.INTERMEDIATE_DIR)/, $(LIBMODULE.TARGET:.cpp=.d))

###########
# Link Part
###########

$(TARGET): $(LIBMODULE.OBJ)
	@echo ----------------------------------------
	@echo Link : $(TARGET)
	@echo ----------------------------------------
	$(CC) $(LFLAGS) $(LIBLINK) $(LIBMODULE.OBJ) -o $(TARGET) $(SYSROOT)
	$(info )

##############
# Compile Part
##############

$(LIBMODULE.OBJ): %.o:
	@echo ----------------------------------------
	@echo Compile : $(notdir $(CONVERT_BUILD))
	@echo ----------------------------------------
	@mkdir -p $(@D)
	@$(CC) -MM -MF $(@:.o=.d) -MT"$(@)" $(CFLAGS) $(CONVERT_SRC) $(SYSROOT)
	$(CC) $(CFLAGS) $(LIBCOMPILE) -c -o $@ $(CONVERT_SRC) $(SYSROOT)
	$(info )

###################
# Pre-build process
###################

PRE_BUILD:
	@echo ================================================================
	@echo Make file started. config =\> $(CONFIG), platform =\> $(PLATFORM)
	@echo ================================================================
	
####################
# Post-build process
####################

# after release build, do strip command
POST_BUILD:
	@echo Post build...
	@if [ "$(CONFIG)" = "release" ]; then \
		echo Start to strip; \
		echo $(STRIP) $(TARGET); \
		$(STRIP) $(TARGET); \
	fi;
	@echo Compile completed : $(TARGET)
	@echo ================================================================
	@echo Make file finished. config =\> $(CONFIG), platform =\> $(PLATFORM)
	@echo ================================================================
	
##################################
# Clean up 한다.
clean:
	@rm -f $(LIBMODULE.OBJ)
	@rm -f $(LIBMODULE.DEP)
	@rm -f $(TARGET)
	@echo -----------------------------------------------------------------
	@echo Clean work finished. config =\> $(CONFIG), platform =\> $(PLATFORM)
	@echo -----------------------------------------------------------------

##################################
# 끝 부분에 dependency 파일들을 include한다.
-include $(LIBMODULE.DEP)
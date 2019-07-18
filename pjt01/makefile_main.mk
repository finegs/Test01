######################  Init All Variables ###############################################
OSFLAG :=
ifeq ($(OS), Windows_NT)
	OSFLAG += -DWIN32
	$(MAKE) -f makefile_win32.mk
else
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S), Linux)
		OSFLAG += -DLINUX
		$(MAKE) -f makefile_linux.mk
    endif
endif

all:
	echo make done

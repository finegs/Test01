CC:=g++
TARGET:=t.exe
OBJS:=$(TARGET:.exe=.o)
OBJS+=mipc.o
#OBJS+=s.o
#OBJS+=u.o
OBJS+=uu1.o

CFLAGS:= -O2 
INCLUDE:= -I. -Iinc -I$(BOOST_INC)

LIB_PATH:=-L$(BOOST_LIB) 

LFLAGS:=-lm
LFLAGS+=-lws2_32
LFLAGS+=-pthread

.PHONY : all

all : $(TARGET)


$(TARGET) : $(OBJS)
	$(CC) -o $@ $(LIB_PATH) $(LFLAGS) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $< 

%.o : %.cpp
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $< 

debug: CFLAGS+= -g -DDEBUG

release: CFLAGS += -O2

clean:
	rm -rf *.o $(TARGET)

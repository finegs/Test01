#CXX = $(shell wx-config --cxx)
CXX = g++
 
TARGET = HelloWorldApp.exe
 
OBJECTS = $(TARGET:%.exe=%.o)
 
 # implementation
 
 .SUFFIXES:      .o .cpp
 
 .cpp.o :
	$(CXX) -c `wx-config --cxxflags` -o $@ $<
 
 all:    $(TARGET)
 
 $(TARGET):     $(OBJECTS)
	$(CXX) -o $(TARGET) $(OBJECTS) `wx-config --libs`
 
 clean:
	@rm -f *.o $(TARGET)

WXLIBS = `wx-config --libs`
WXFLAGS = `wx-config --cxxflags`
INCLUDES = -I. -I./App -I./Frames
LIBS =
FLAGS = -g $(INCLUDES)
CPP = g++

.SUFFIXES:  .cpp

.cpp.o:
	$(CPP) $(WXFLAGS) $(FLAGS) -c $< -o $@

.cpp :
	$(CPP) $(WXFLAGS) $(FLAGS) $< -o $@ $(WXLIBS) $(LIBS)

SRC = main.cpp App/wxEditor.cpp Frames/MainFrame.cpp
OBJ = $(addsuffix .o, $(basename $(SRC)))

all: $(OBJ)
	$(CPP) $(WXFLAGS) $(FLAGS) -o $@ $(OBJ) $(WXLIBS) $(LIBS)

clean:
	rm -f $(OBJ)
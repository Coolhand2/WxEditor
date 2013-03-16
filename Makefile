WXLIBS = `wx-config --libs`
WXFLAGS = `wx-config --cxxflags`
INCLUDES = -I.
LIBS =
FLAGS = -g $(INCLUDES)
CPP = g++
SOURCES = main.cpp

.SUFFIXES:  .cpp

.cpp.o:
	$(CPP) $(WXFLAGS) $(FLAGS) -c $<

.cpp :
	$(CPP) $(WXFLAGS) $(FLAGS) $< -o $@ $(WXLIBS) $(LIBS)

SRC = main.cpp
OBJ = $(addsuffix .o, $(basename $(SRC)))

all: $(OBJ)
	$(CPP) $(WXFLAGS) $(FLAGS) -o $@ $(OBJ) $(WXLIBS) $(LIBS)

clean:
	rm -f $(OBJ)
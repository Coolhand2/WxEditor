WXLIBS = `wx-config --libs`
WXFLAGS = `wx-config --cxxflags`
INCLUDES = -I. -I./App -I./Frames
LIBS = $(WXLIBS)
ifeq ($(BUILD), release)
    FLAGS = -g -Wall -O3 -foptimize-sibling-calls $(INCLUDES) $(WXFLAGS)
else
    FLAGS = -g3 -fno-inline -O0 $(INCLUDES) $(WXFLAGS)
endif
CPP = g++
QUIET_CPP = @echo '    ' G++ $@;
QUIET_LINK = @echo '    ' LINK $@;
QUIET_RM = @echo '    ' CLEAN;

.SUFFIXES:  .cpp
.cpp.o:
	$(QUIET_CPP)$(CPP) $(FLAGS) -c $< -o $@

SRC = main.cpp App/wxEditor.cpp Frames/MainFrame.cpp
OBJ = $(addsuffix .o, $(basename $(SRC)))

all: wxEditor

wxEditor: $(OBJ)
	$(QUIET_LINK)$(CPP) $(FLAGS) -o $@ $(OBJ) $(LIBS)

clean:
	$(QUIET_RM) rm -f $(OBJ)
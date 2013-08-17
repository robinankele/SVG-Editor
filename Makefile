# //----------------------------------------------------------------------------
#/// Filename:      Makefile
#/// Description:   Makefile for exA
#/// Author:        Ankele Robin (0931951)
#/// Tutor:         Manuel Weber
#/// Group:         24
#/// Created:       08.09.2011
#/// Last change:   08.09.2011
#//-----------------------------------------------------------------------------

CXX = g++
CXXFLAGS = -c -Wall -g
LDFLAGS =
SOURCES = $(wildcard *.cpp)
OBJECTS = ${SOURCES:.cpp=.o}
TITLE = exA
ARCHIVE = $(TITLE).tar.gz

.PHONY : all clean valgrind archive

all: $(TITLE)

$(TITLE) : $(OBJECTS)
	$(CXX) $(LDFLAGS) -o $@ $(OBJECTS)

%.o : %.cpp 
	$(CXX) $(CXXFLAGS) -o $@ $< -MMD -MF ./$@.d

clean :
	rm -f *.o *.gch $(TITLE) *.d
  
valgrind : $(TITLE)
	valgrind --tool=memcheck --leak-check=yes ./$< $(P0) $(P1)

archive :
	tar cfz $(ARCHIVE) *.cpp *.h *.pdf $(TITLE)

-include $(wildcard ./*.d)
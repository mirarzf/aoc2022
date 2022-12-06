CPPFILES = $(wildcard *.cpp) $(filter-out $(wildcard */day*.cpp), $(wildcard */*.cpp))
HPPFILES = $(wildcard *.hpp) $(wildcard */*.hpp)
OBJFILES = $(CPPFILES:.cpp=.o)

OUT      = solve

CFLAGS = -Wall -Wextra
LDLIBS = -lstdc++ -lm

$(OUT): $(OBJFILES)
	g++ $(OBJFILES) $(LDLIBS) $(CFLAGS) -o $(OUT)

.PHONY: clean
clean:
	rm -f $(OBJFILES) $(OBJFILESINSUB) 
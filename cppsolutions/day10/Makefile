CPPFILES = $(wildcard *.cpp)
HPPFILES = $(wildcard *.hpp)
OBJFILES = $(CPPFILES:.cpp=.o)

OUT      = day10

CFLAGS = -Wall -Wextra
LDLIBS = -lstdc++ -lm

$(OUT): $(OUT).o $(OBJFILES) 
	g++ $(OBJSOURCE) $(OBJFILES) $(LDLIBS) $(CFLAGS) -o $(OUT)

.PHONY: clean
clean:
	rm -rf $(OBJSOURCE) $(OBJFILES) 
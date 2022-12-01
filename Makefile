CPPFILESINMAIN = $(*.cpp)
CPPFILESINCPPSOL = $(wildcard cpp_solutions/*.cpp)
HPPFILESINCPPSOL = $(wildcard cpp_solutions/*.hpp)
OBJFILESINMAIN = $(CPPFILESINMAIN:.cpp=.o)
OBJFILESINCPPSOL = $(CPPFILESINCPPSOL:.cpp=.o)
OUT      = solve

CFLAGS = -Wall -Wextra
LDLIBS = -lstdc++ -lm

$(OUT): solve.o $(OBJFILESINCPPSOL)
	g++ solve.o $(OBJFILESINCPPSOL)

.PHONY: clean
clean:
	rm -f $(OBJFILES) $(OUT)
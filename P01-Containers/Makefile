CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Wpedantic

TARGETS = p01_single_grades p01_multiple_grades

all: $(TARGETS)

p01_single_grades: p01_single_grades.o alumnos.o
	$(CXX) $(CXXFLAGS) $^ -o $@

p01_multiple_grades: p01_multiple_grades.o alumnos.o
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o $(TARGETS)

.PHONY: all clean

all: $(TARGETS)
	rm -f *.o

clean:
	rm -f *.o $(TARGETS)

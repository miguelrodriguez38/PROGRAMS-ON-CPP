CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g

SRCS = $(wildcard *.cc)
OBJS = $(SRCS:.cc=.o)
TARGET = p06_DFA_simulator

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

%.o: %.cc $(wildcard *.h)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
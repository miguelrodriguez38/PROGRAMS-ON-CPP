CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -g
TARGET := p02_strings

SRCS := $(wildcard *.cc)

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $@ $(SRCS)

.PHONY: all clean
clean:
	rm -f $(TARGET)
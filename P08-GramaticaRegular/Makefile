CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g
TARGET = dfa2grammar
SRCS = $(wildcard *.cc)
HDRS = $(wildcard *.h)

$(TARGET): $(SRCS) $(HDRS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: clean
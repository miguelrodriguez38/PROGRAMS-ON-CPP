CXX = g++
CXXFLAGS = -std=c++17 -Wall
TARGET = p04_html_analyzer
SRCS = Cliente.cc Attribute.cc Comment.cc Html.cc Link.cc Tag.cc
HDRS = Attribute.h Comment.h Html.h Link.h Tag.h
 
$(TARGET): $(SRCS) $(HDRS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)
 
clean:
	rm -f $(TARGET)
 
.PHONY: clean
 

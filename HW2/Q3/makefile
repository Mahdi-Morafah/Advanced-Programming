CXX = g++
CXXFLAGS = -std=c++17 -Wall -c
LXXFLAGS = -std=c++17
OBJECTS = main.o util.o 
TARGET = main

$(TARGET): $(OBJECTS)
	$(CXX) $(LXXFLAGS) $(OBJECTS) -o $(TARGET)
main.o: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp
util.o: util.cpp util.h
	$(CXX) $(CXXFLAGS) util.cpp
clean:
	rm -f $(TARGET) $(OBJECTS)


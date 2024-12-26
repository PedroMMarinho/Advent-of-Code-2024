# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

# Target and source files
TARGET = day3
SRC = day3.cpp

# Default target
all: $(TARGET)

# Build target
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# Clean up build files
clean:
	rm -f $(TARGET)

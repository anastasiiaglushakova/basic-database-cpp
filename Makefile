CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude

SRC = main.cpp src/DataBase.cpp
OBJ = $(SRC:.cpp=.o)

TARGET = my_program

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
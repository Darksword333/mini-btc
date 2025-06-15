CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude

SRC = $(wildcard src/*.cpp)
OBJ = $(patsubst src/%.cpp,bin/%.o,$(SRC))
TARGET = bin/mini-bitcoin

all: $(TARGET)

bin:
	mkdir -p bin

$(TARGET): $(OBJ) | bin
	$(CXX) $(CXXFLAGS) -o $@ $^

bin/%.o: src/%.cpp | bin
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf bin

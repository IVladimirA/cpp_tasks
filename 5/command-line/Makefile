CXX := g++
CXXFLAGS+=-std=c++17 -Wall -O2

.PHONY: build clean run

build: a.out

run: a.out
	./a.out -a 10 5

a.out: main.cpp
	$(CXX) $^ $(CXXFLAGS)

clean:
	rm a.out

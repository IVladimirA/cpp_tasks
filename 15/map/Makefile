CXX := g++
CXXFLAGS+=-std=c++17 -Wall -O2

.PHONY: build clean run

build: a.out

run: a.out
	./a.out

a.out: main.cpp grades.h grades.cpp
	$(CXX) $^ $(CXXFLAGS) -w -o a.out

clean:
	rm a.out

CXX := g++
CXXFLAGS+=-Wall -O2

.PHONY: build clean run

build: a.out

run: a.out
	./a.out

a.out: main.cpp
	$(CXX) $^ $(CXXFLAGS)

clean:
	rm a.out

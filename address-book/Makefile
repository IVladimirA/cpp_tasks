CXX := g++
CXXFLAGS+=-std=c++17 -Wall -O2
people := people/human/* people/student/* people/teacher/*
parser := utils/parser/*
creators := utils/creators/*
runner := utils/runner/*
utils := $(parser) $(creators) $(runner)
scores := scores/*
subject := subject/*
properties := $(scores) $(subject)
manager := manager/*

.PHONY: build clean run

build: a.out

run: a.out
	./a.out

a.out: main.cpp $(utils) $(people) $(properties) $(manager)
	$(CXX) $^ $(CXXFLAGS) -w -o a.out

clean:
	rm a.out

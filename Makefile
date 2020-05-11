CXX := g++
CXXFLAGS := -Wall

src = $(wildcard src/*.cpp)
objects := $(src:%.cpp=%.o)

all: build test

build: 
	@mkdir -p build/test/
	@mkdir -p build/objects/

test : $(objects)
	g++ -o build/test/test $(objects)
	mv $(objects) build/objects/

.PHONY : clean
clean:
	rm build/test/* build/objects/* 

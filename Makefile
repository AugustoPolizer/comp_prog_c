CXX := g++
CXXFLAGS := -Wall

src := $(wildcard src/*.cpp) \
	$(wildcard src/data_structures/*.cpp) 
objects := $(src:%.cpp=%.o)

all: build test

test : $(objects)
	g++ -o build/test/test $(objects)
	mv $(objects) build/objects/

build: 
	@mkdir -p build/test/
	@mkdir -p build/objects/

.PHONY : clean
clean:
	rm build/apps/* build/objects/* 
	rm build/test/* build/objects/* 

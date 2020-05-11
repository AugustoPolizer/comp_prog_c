CXX := g++
CXXFLAGS := -Wall

src = $(wildcard src/*.cpp)
objects := $(src:%.cpp=%.o)

test : $(objects)
	g++ -o build/apps/test $(objects)
	mv $(objects) build/objects/

.PHONY : clean
clean:
	rm build/apps/* build/objects/* 

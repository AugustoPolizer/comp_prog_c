CXX := g++
CXXFLAGS := -Wall

src := $(wildcard src/*.cpp) \
	$(wildcard src/data_structures/*.cpp) \
	$(wildcard src/dp/*.cpp) \
	$(wildcard src/common/*.cpp) \

objects := $(src:%.cpp=%.o)

all: build test

test : $(objects)
	g++ -o build/test/test $(objects)

build: 
	@mkdir -p build/test/

.PHONY : clean
clean:
	rm src/*.o src/*/*.o

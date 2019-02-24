all: ./obj ./bin bin/battleship  

CC := g++
SOURCES := $(wildcard src/*cpp)
OBJECTS := $(patsubst src/%.cpp, obj/%.o, $(SOURCES))
#OBJ := $(patsubst %, obj/%,$(OBJECTS))
INC := -I./inc

obj/%.o : src/%.cpp ./obj
	$(CC) -c -I./inc $< -o $@ 

bin/battleship : $(OBJECTS) ./bin 
	$(CC) $(OBJECTS) -o $@



#generate.o : src/generate.cpp inc/generate.h
#	g++ -c -I./inc src/generate.cpp  -o obj/generate.o

#battleship.o : src/battleship.cpp inc/generate.h
#	g++ -c -I./inc src/battleship.cpp   -o obj/battleship.o

./bin:
	mkdir -p bin

#battleship : battleship.o generate.o
#	g++ obj/battleship.o obj/generate.o -o bin/battleship

./obj:
	mkdir -p obj

clean: 
	rm -rf ./obj/*.o ./bin/*

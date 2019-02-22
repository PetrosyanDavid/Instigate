all: obj/generate.o obj/battleship.o ./bin ./obj bin/battleship  

obj/generate.o : src/generate.cpp inc/generate.h
	g++ -c src/generate.cpp inc/generate.h -o obj/generate.o

obj/battleship.o : src/battleship.cpp inc/generate.h
	g++ -c src/battleship.cpp inc/generate.h  -o obj/battleship.o

./bin:
	mkdir -p bin

bin/battleship : obj/battleship.o obj/generate.o
	g++ obj/battleship.o obj/generate.o -o bin/battleship

./obj:
	mkdir -p obj


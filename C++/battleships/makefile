all:  bin/battleship

CC := g++
SOURCES := $(wildcard src/*cpp)
OBJECTS := $(patsubst src/%.cpp, obj/%.o, $(SOURCES))
INC := -I./inc
DEPENDS := $(patsubst src/%.cpp,obj/%.dep,$(SOURCES))

obj/%.dep : src/%.cpp
	mkdir -p obj
	$(CC) $(INC) -MM $< -MT "$@ $(patsubst %.dep,%.o,$@)" -o $@

obj/%.o :
	$(CC) -c $(INC) $< -o $@ 

bin/battleship : $(OBJECTS) ./bin
	$(CC) $(OBJECTS) -o $@

./bin:
	mkdir -p bin

clean: 
	rm -rf ./obj  ./bin

-include $(DEPENDS)




all:  bin/battleship

CC        := g++
SOURCES   := $(wildcard src/*cpp)
INCLUDEH  := $(wildcard src/*hpp) 
INCLUDET  := $(wildcard src/*tpp)
INCLUDE_H := $(patsubst src/%.hpp, inc/%.hpp, $(INCLUDEH))
INCLUDE_T := $(patsubst src/%.tpp, inc/%.tpp, $(INCLUDET))
OBJECTS   := $(patsubst src/%.cpp, obj/%.o, $(SOURCES))
INC       := ./inc
DEPENDS   := $(patsubst src/%.cpp,obj/%.dep,$(SOURCES))
CFLAGS    := -c -g -Wall -Wextra -pedantic -std=c++11


ifeq ($(MAKECMDGOALS),)
	    -include $(DEPENDS)
else ifeq ($(MAKECMDGOALS),all)
	    -include $(DEPENDS)
endif

obj/%.dep : src/%.cpp ./inc
	mkdir -p obj
	$(CC) -I$(INC) -MM $< -MT "$@ $(patsubst %.dep,%.o,$@)" -o $@

obj/%.o :
	$(CC) $(CFLAGS) -I$(INC) $< -o $@ 

bin/battleship : $(OBJECTS) ./bin #$(INCLUDE_H) $(INCLUDE_T)
	$(CC) $(OBJECTS) -o $@

./inc :
	mkdir -p inc
	$(MAKE) $(INCLUDE_H) 
	$(MAKE) $(INCLUDE_T) 

./bin :
	mkdir -p bin

inc/%hpp : src/%hpp 
	ln -f $< $@

inc/%tpp : src/%tpp 
	ln -f $< $@

.PHONY clean: 
	rm -rf ./obj  ./bin ./inc

all:  bin/merge_sort

CC := g++
SOURCES := $(wildcard src/*cpp)
OBJECTS := $(patsubst src/%.cpp, obj/%.o, $(SOURCES))
INC := -I./inc
DEPENDS := $(patsubst src/%.cpp,obj/%.dep,$(SOURCES))

ifeq ($(MAKECMDGOALS),)
	-include $(DEPENDS)
else ifeq ($(MAKECMDGOALS),all)
	-include $(DEPENDS)
endif


obj/%.dep : src/%.cpp
	mkdir -p obj
	$(CC) $(INC) -MM $< -MT "$@ $(patsubst %.dep,%.o,$@)" -o $@

obj/%.o :
	$(CC) -c -g $(INC) $< -o $@ 

bin/merge_sort : $(OBJECTS) ./bin
	$(CC) $(OBJECTS) -o $@

./bin:
	mkdir -p bin

.PHONY clean: 
	rm -rf ./obj  ./bin





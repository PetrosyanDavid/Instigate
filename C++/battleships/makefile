all: ./obj ./bin battleship  

CC := g++
SOURCES := $(wildcard src/*cpp)
OBJ := $(notdir $(SOURCES:.cpp=.o))
OBJECTS := $(patsubst src/%.cpp, obj/%.o, $(SOURCES))
#OBJ := $(patsubst %, obj/%,$(OBJECTS))
INC := -I./inc
DEPENDS := $(patsubst src/%.cpp,obj/%.dep,$(SOURCES))

#default: \
	@echo $(SOURCES)\
	@echo $(OBJ) \
	@echo $(OBJECTS)


battleship : ./bin $(OBJECTS) 
	$(CC) $(OBJECTS) -o bin/$@

./bin:
	mkdir -p bin

./obj:
	mkdir -p obj

clean: 
	rm -rf ./obj/*  ./bin/*

obj/%.dep : src/%.cpp 
	g++ $(INC) -MM $< -MT "$@ $(patsubst %.dep,%.o,$@)" -o $@

obj/%.o : src/%.cpp ./obj 
	$(CC) -c -I./inc $< -o $@ 

-include $(DEPENDS)

all:  ../../bin/thread

CC        := g++
SOURCES   := $(wildcard ./*cpp)
INCLUDEH  := $(wildcard ./*hpp) 
INCLUDET  := $(wildcard ./*tpp)
LIBRARIES := ../../lib/thread/libthread.so
LIB_NAME  := $(notdir $(LIBRARIES))
L_NAME    := $(patsubst lib%.so, -l%, $(LIB_NAME))
INCLUDE_H := $(patsubst ./%.hpp, ../../inc/%.hpp, $(INCLUDEH))
INCLUDE_T := $(patsubst ./%.tpp, ../../inc/%.tpp, $(INCLUDET))
OBJECTS   := $(patsubst ./%.cpp, ../../obj/%.o, $(SOURCES))
INC       := ../../inc 
LINK      := ../../lib/thread
DEPENDS   := $(patsubst ./%.cpp,../../obj/%.dep,$(SOURCES))
CFLAGS    := -c -g -Wall -Wextra -pedantic -std=c++11


ifeq ($(MAKECMDGOALS),)
	    -include $(DEPENDS)
else ifeq ($(MAKECMDGOALS),all)
	    -include $(DEPENDS)
endif

default :
	@echo $(LIB_H)
	@echo $(LIB_NAME)
	@echo $(LIBRARIES)
	@echo $(L_NAME)

../../obj/%.dep : ./%.cpp $(LIBRARIES)
	$(CC) -I$(INC) -std=c++11 -MM $< -MT "$@ $(patsubst %.dep,%.o,$@)" -o $@

$(OBJECTS) : 
	$(CC) $(CFLAGS) -I$(INC) $< -o $@ 

../../bin/thread : $(OBJECTS) 
	$(CC) -pthread -L$(LINK) $(OBJECTS) -o $@ $(L_NAME)

$(LIBRARIES) :
	$(MAKE) -C ../threads


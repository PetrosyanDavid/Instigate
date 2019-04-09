all:  ../../bin/thread

CC        := g++
SOURCES   := $(wildcard ./*cpp)
INCLUDEH  := $(wildcard ./*hpp) 
INCLUDET  := $(wildcard ./*tpp)
INCLUDE_H := $(patsubst ./%.hpp, ../../inc/%.hpp, $(INCLUDEH))
INCLUDE_T := $(patsubst ./%.tpp, ../../inc/%.tpp, $(INCLUDET))
OBJECTS   := $(patsubst ./%.cpp, ../../obj/%.o, $(SOURCES))
INC       := ../../inc
DEPENDS   := $(patsubst ./%.cpp,../../obj/%.dep,$(SOURCES))
CFLAGS    := -c -g -Wall -Wextra -pedantic -std=c++11


ifeq ($(MAKECMDGOALS),)
	    -include $(DEPENDS)
else ifeq ($(MAKECMDGOALS),all)
	    -include $(DEPENDS)
endif

../../obj/%.dep : ./%.cpp 
	$(CC) -I$(INC) -std=c++11 -MM $< -MT "$@ $(patsubst %.dep,%.o,$@)" -o $@

$(OBJECTS) :
	$(CC) $(CFLAGS) -I$(INC) $< -o $@ 

../../bin/thread : $(INCLUDE_H) $(INCLUDE_T) $(OBJECTS) 
	$(CC) -pthread $(OBJECTS) -o $@

#./inc :
#	mkdir -p inc
#	$(MAKE) $(INCLUDE_H) 
#	$(MAKE) $(INCLUDE_T) 

../../inc/%hpp : ./%hpp 
	ln -f $< $@

../../%tpp : ./%tpp 
	ln -f $< $@

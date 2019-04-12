all:  ../../bin/server

CC        := g++
SOURCES   := $(wildcard ./*cpp)
INCLUDEH  := $(wildcard ./*hpp) 
INCLUDET  := $(wildcard ./*tpp)
LIB_H     := $(wildcard ../threads/*hpp)
LIB_NAME  := $(notdir $(LIB_H))
LIBRARIES := $(patsubst %.hpp, ../../lib/lib%.so, $(LIB_NAME))
L_NAME    := $(patsubst %.hpp, -l%, $(LIB_NAME))
INCLUDE_H := $(patsubst ./%.hpp, ../../inc/%.hpp, $(INCLUDEH))
INCLUDE_T := $(patsubst ./%.tpp, ../../inc/%.tpp, $(INCLUDET))
OBJECTS   := $(patsubst ./%.cpp, ../../obj/%.o, $(SOURCES))
INC       := ../../inc
LINK      := ../../lib
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

../../bin/server : $(INCLUDE_H) $(INCLUDE_T) $(OBJECTS) 
	$(CC) -pthread -L$(LINK) $(OBJECTS) -o $@ $(L_NAME)

$(LIBRARIES) :
	$(MAKE) -C ../threads

../../inc/%hpp : ./%hpp 
	ln -f $< $@

../../%tpp : ./%tpp 
	ln -f $< $@

all:  build

CC        := g++
SOURCES   := $(wildcard ./*cpp)
INCLUDEH  := $(wildcard ./*hpp) 
INCLUDET  := $(wildcard ./*tpp)
INCLUDE_H := $(patsubst ./%.hpp, ../../inc/%.hpp, $(INCLUDEH))
INCLUDE_T := $(patsubst ./%.tpp, ../../inc/%.tpp, $(INCLUDET))
LIBRARIES := $(patsubst ./%.hpp, ../../lib/lib%.so, $(INCLUDEH))
OBJECTS   := $(patsubst ./%.cpp, ../../obj/%.o, $(SOURCES))
INC       := ../../inc
DEPENDS   := $(patsubst ./%.cpp,../../obj/%.dep,$(SOURCES))
CFLAGS    := -c -g -Wall -Wextra -pedantic -std=c++11
LFLAGS    := -c -Wall -Werror -fPIC -Wextra -std=c++11

ifeq ($(MAKECMDGOALS),)
	    -include $(DEPENDS)
else ifeq ($(MAKECMDGOALS),all)
	    -include $(DEPENDS)
endif

default :
	@echo $(DEPENDS)
	@echo $(LIBRARIES)

../../obj/%.dep : ./%.cpp 
	$(CC) -I$(INC) -MM  $< -MT "$@ $(patsubst %.dep,%.o,$@)" -o $@

$(OBJECTS) :
	$(CC) $(LFLAGS) -I$(INC) $< -o $@ 
	
.PRECIOUS : $(INCLUDE_H) $(INCLUDE_T)

build : $(LIBRARIES)

../../lib/% : $(INCLUDE_H) $(INCLUDE_T) $(OBJECTS) 
	$(CC) -shared  $(OBJECTS) -o $@

../../inc/%hpp : ./%hpp 
	ln -f $< $@

../../%tpp : ./%tpp 
	ln -f $< $@

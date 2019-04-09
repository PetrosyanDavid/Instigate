SUBDIRS := $(wildcard */.)

all : $(SUBDIRS)

default :
	@echo $(SUBDIRS)

$(SUBDIRS) : 
	$(MAKE) -C $@

.PHONY : $(SUBDIRS)

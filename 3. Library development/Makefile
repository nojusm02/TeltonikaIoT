LIBDIR:=./lib
SRCDIR:=./src

.PHONY: all install uninstall

all: install
	
install:
	$(MAKE) -C $(LIBDIR) install
	$(MAKE) -C $(SRCDIR) all

uninstall:
	$(MAKE) -C $(LIBDIR) uninstall
	$(MAKE) -C $(SRCDIR) clean
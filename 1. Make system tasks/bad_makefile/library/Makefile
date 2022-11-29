#Make komandas leisti su sudo, nes dabartinis prefix to reikalauja
PREFIX    = /usr/local
CC:=gcc
CFLAGS:=-Wall 
LIB:=calculator.so

all: $(LIB)

$(LIB): math_functions.c math_functions.h

	$(CC) $(CFLAGS) -shared -o $(LIB) $^

install: $(LIB)
	mkdir -p $(DESTDIR)$(PREFIX)/include
	install -m 644 $(LIB) math_functions.h $(DESTDIR)$(PREFIX)/include

uninstall:
	rm $(DESTDIR)$(PREFIX)/include/math_functions.h
	rm $(DESTDIR)$(PREFIX)/include/$(LIB)


clean:
	rm -f $(LIB)

CFLAGS := -Wall  
LDFLAGS := -L../lib/ -llog
CPPFLAGS:=-I../lib

.PHONY: all clean

all: display writeProgram1 writeProgram2 

display: displayProgram.o
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

writeProgram1: writeProgram1.o
	$(CC) $(CFLAGS) $^ -o $@  $(LDFLAGS)

writeProgram2: writeProgram2.o
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

clean:
	$(RM) display writeProgram1 writeProgram2 *.o

CFLAGS=-Wall
EXECUTABLE=adressbook
DEPS = llist.h
OBJ = main.o llist.o


$(EXECUTABLE): $(OBJ) $(DEPS)
	$(CC) $(CFLAGS) -o $@ $^ 

clean:
	rm -rf *.o $(EXECUTABLE)

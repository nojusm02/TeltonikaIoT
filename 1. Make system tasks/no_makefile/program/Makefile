CC=gcc
CFLAGS=-I.
DEPS = maths.h usage.h
OBJ = maths.o usage.o main.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

calculator: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm calculator *.o
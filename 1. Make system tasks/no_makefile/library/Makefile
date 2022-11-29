CC = gcc

program: main.o file_reader.so
		LD_LIBRARY_PATH=`pwd` $(CC) -o program main.c file_reader.so

main.o: main.c
		$(CC) main.c -c -o main.o

file_reader.o: file_reader.c file_reader.h 
		$(CC) file_reader.c -fPIC -c -o file_reader.o

library file_reader.so: file_reader.o
		$(CC) -shared file_reader.o -o file_reader.so

clean:
	rm program *.o *.so
CC = icc

CFLAGS = -I. -O3 -std=c11
LIBS = -lm

DEPS = proto.h
OBJ  = main.o io.o add_numbers.o

make: $(OBJ) 
	$(CC) $(OBJ) $(LIBS) $(CFLAGS) -o mycode 

clean:
	rm *.o 

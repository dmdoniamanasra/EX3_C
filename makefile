WALL= -Wall -g
CC=gcc

all:libclassfunc.a stringProg
stringProg: main.o libclassfunc.a
	$(CC) $(WALL) -o stringProg main.o libclassfunc.a

libclassfunc.a:stringProg.o
	ar -rcs libclassfunc.a stringProg.o 
stringProg.o:stringProg.c stringProg.o
	$(CC) $(WALL) -c stringProg.c
main.o:main.c stringProg.h
	$(CC) $(WALL) -c main.c
	
clean: 
	rm -f *.o *.a ./stringProg
CC=gcc
WALL= -Wall -g

all:libclassfunc.a	StringsPro
StringsPro:	main.o	libclassfunc.a
		$(CC)	$(WALL)	-o	StringsPro	main.o	libclassfunc.a

libclassfunc.a:Strings_ex3.o
			ar	-rcs	libclassfunc.a	Strings_ex3.o
Strings_ex3.o:	Strings_ex3.c	Strings_ex3.o
	$(CC)	$(WALL)	-c	Strings_ex3.c
main.o:	main.c	Strings_ex3.h
		$(CC)	$(WALL)	-c	main.c

clean:
		rm	-f	*.o	*.a	./StringsPro
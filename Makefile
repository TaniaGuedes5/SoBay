default: all;

all: backEnd.o frontEnd.o users_lib.o

frontEnd.o: frontEnd.c
	gcc frontEnd.c -o frontEnd
	
backEnd.o: backEnd.c
	gcc backEnd.c users_lib.o -o backEnd
clean:
	rm backEnd
	rm frontEnd
	rm promotor_oficial

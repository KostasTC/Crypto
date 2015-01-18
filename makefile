
crypto: main.o crypto.o
	gcc -o crypto main.o crypto.o

main.o: crypto.h help.h
	gcc -c main.c 

crypto.o: crypto.h
	gcc -c crypto.c

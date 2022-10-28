CFLAGS = -Wall -pedantic -Werror

bst: bst.o
	gcc -o bst bst.o

bst.o: bst.c bst.h ../Node/node.h
	gcc -c bst.c

clean: 
	rm *.o
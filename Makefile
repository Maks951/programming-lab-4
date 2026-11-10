lab: grid.o bras.o poly.o flood.o main.o
	gcc -o lab grid.o bras.o poly.o flood.o main.o

grid.o: grid.c grid.h
	gcc -c grid.c -o grid.o

bras.o: bras.c bras.h grid.h
	gcc -c bras.c -o bras.o

poly.o: poly.c poly.h bras.h grid.h
	gcc -c poly.c -o poly.o

flood.o: flood.c flood.h grid.h
	gcc -c flood.c -o flood.o

main.o: main.c grid.h bras.h poly.h flood.h
	gcc -c main.c -o main.o
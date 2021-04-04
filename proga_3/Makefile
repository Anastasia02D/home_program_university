all: clear proga del_o

clear:
	clear

proga: 17.o 17_f.o malloc.o
	gcc -o proga 17.o 17_f.o malloc.o

17.o: 17.c
	gcc -c 17.c

17_f.o: 17_f.c
	gcc -c 17_f.c

malloc.o: malloc.c
	gcc -c malloc.c

del_o:
	rm *.o

Prog: main.o func.o
	gcc -Wall -o Prog main.o func.o

main.o: main.c
	gcc -Wall -c main.c

func.o: func.c
	gcc -Wall -c func.c

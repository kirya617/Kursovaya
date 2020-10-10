Prog: main.o func.o
	gcc -Wall -g -O0 -o Prog main.o func.o

main.o: main.c
	gcc -Wall -g -O0 -c main.c

func.o: func.c
	gcc -Wall -g -O0 -c func.c

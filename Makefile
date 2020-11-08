

Prog: main.o func.o
	gcc -Wall -g -O0 -o Prog main.o func.o

main.o: main.c
	gcc -Wall -g -O0 -c main.c

func.o: func.c
	gcc -Wall -g -O0 -c func.c


#test

test: test test/test.o test/test_func.o
	gcc -Wall test/*.o func.o -o Test

test/main.o: test/test.c
	gcc -Wall -c test/test.c -o test/test.o

test/test_func.o: test/test_func.c
	gcc -Wall -c test/test_func.c -o test/test_func.o


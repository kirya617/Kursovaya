flags = -Wall -Werror

all: src	

test: test

run:
	    ./bin/Hangman

test_run:
	    ./bin/test

#src

src: build/src build/src/main.o build/src/func.o
	    gcc $(flags) build/src/*.o -o bin/Hangman

build/src:
	    mkdir -p build/src

build/src/main.o: src/main.c
	    gcc $(flags) -c src/main.c -o build/src/main.o

build/src/func.o: src/func.c
	    gcc $(flags) -c src/func.c -o build/src/func.o

#test

build/test:
	    mkdir -p build/test	

test: build/test build/test/test.o build/test/test_func.o
	    gcc $(flags) build/test/*.o build/src/func.o -o bin/test

build/test/test.o: test/test.c
	    gcc $(flags) -c test/test.c -o build/test/test.o

build/test/test_func.o: test/test_func.c
	    gcc $(flags) -c test/test_func.c -o build/test/test_func.o

.PHONY: clean all

clean:
	    rm -rf build/src/* bin/* build/test/*

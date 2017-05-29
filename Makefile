all: main

main: build/src/main.o
	gcc build/src/main.o -o bin/main

build/src/main.o: src/main.c
	gcc -Wall -Werror -c src/main.c -o build/src/main.o

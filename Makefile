all: main

main: build/src/main.o build/src/game.o
	gcc build/src/main.o build/src/game.o -o bin/main

build/src/main.o: src/main.c
	gcc -Wall -Werror -c src/main.c -o build/src/main.o

build/src/game.o: src/game.c
	gcc -Wall -Werror -c src/game.c -o build/src/game.o

clean:
	rm -f build/src/*.o
	rm -f bin/main

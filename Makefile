all: main tests

main: build/src/main.o build/src/game.o
	gcc build/src/main.o build/src/game.o -o bin/main

build/src/main.o: src/main.c
	gcc -Wall -Werror -c src/main.c -o build/src/main.o

build/src/game.o: src/game.c
	gcc -Wall -Werror -c src/game.c -o build/src/game.o

tests: build/test/maint.o build/test/tests.o
	gcc build/test/maint.o build/test/tests.o build/src/game.o -o bin/tests

build/test/maint.o: test/maint.c
	gcc -Wall -Werror -c test/maint.c -o build/test/maint.o

build/test/tests.o: test/tests.c
	gcc -Wall -Werror -c test/tests.c -o build/test/tests.o

clean:
	rm -f build/src/*.o
	rm -f bin/main bin/tests

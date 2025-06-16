all : livre.exe

algo.o: src/algo.c src/algo.h
	gcc -c src/algo.c

import.o: src/import.c src/import.h
	gcc -c src/import.c

render.o: src/render.c src/render.h
	gcc -c src/render.c

main.o: src/main.c src/import.h src/algo.h src/render.h
	gcc -c src/main.c

livre.exe: import.o main.o algo.o render.o
	gcc -o livre.exe import.o main.o algo.o render.o -lncurses
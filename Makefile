all : livre.exe

render.o: src/render.c src/render.h
	gcc -c src/render.c

algo.o: src/algo.c src/algo.h
	gcc -c src/algo.c

import.o: src/import.c src/import.h
	gcc -c src/import.c

main.o: src/main.c src/export.h src/import.h
	gcc -c src/main.c

livre.exe: render.o import.o main.o algo.o
	gcc -o livre.exe render.o import.o main.o algo.o

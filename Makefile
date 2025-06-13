all : livre.exe

export.o: src/export.c src/export.h
	gcc -c src/export.c

import.o: src/import.c src/import.h
	gcc -c src/import.c

main.o: src/main.c src/export.h src/import.h
	gcc -c src/main.c

livre.exe: export.o import.o main.o
	gcc -o livre.exe export.o import.o main.o

all : livre

export.o: src/export.c src/export.h src/import.h src/bibliotheque.h
	ggc -c src/export.c

import.o: src/import.c src/import.h src/bibliotheque.h
	gcc -c src/import.c

main.o: main.c src/export.h src/import.h src/bibliotheque.h
	gcc -c src/main.c

livre: export.o import.o main.o
	gcc -o livre export.o import.o main.o


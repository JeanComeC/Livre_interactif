#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include <unistd.h>

#define LINE_SIZE 512

void trouverchap(){
FILE* file = fopen(book.txt, "r");
if (file == NULL) {
  printf("Unable to open file <%s>\n", book.txt);
  exit(EXIT_FAILURE);
}

char line[LINE_SIZE];
while(fgets(line, sizeof(line), file)) {
    if(){
        
    }
}
}
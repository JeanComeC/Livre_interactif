/*fichier pour mettre toute les fonctions pour récupérer les chapitres*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include <unistd.h>

#define LINE_SIZE 512

void trouverchap(){
FILE* file = fopen("src/book.txt", "r");
if (file == NULL) {
  printf("Unable to open file <%s>\n", "src/book.txt");
  exit(EXIT_FAILURE);
}

char line[LINE_SIZE];
while(fgets(line, sizeof(line), file)) {
    if(strstr(line, "<chapter id") != NULL){
        printf("Found chapter: %s", line);
        int id = 0;
        char* titre;
        sscanf(line,"<chapter id=\"%d\">%[^<]s", &id, &titre);
        printf("Found id and title: %d %s", id, titre);
    }
}
}
int main(){
  trouverchap();
}
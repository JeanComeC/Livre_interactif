/*fichier pour mettre toute les fonctions pour récupérer les chapitres*/

#include "import.h"
#include "bibliotheque.h"

void trouverchap(int chapitre){
FILE* file = fopen("src/book.txt", "r");
if (file == NULL) {
  printf("Unable to open file <%s>\n", "src/book.txt");
  exit(EXIT_FAILURE);
}

char line[LINE_SIZE];
while(fgets(line, sizeof(line), file)) {
    if(strstr(line, "<chapter id") != NULL){
        int id = 0;
        char titre[512];
        sscanf(line,"<chapter id=\"%d\">%[^<]s", &id, &titre);
        if(chapitre==id){
          printf("bienvenue au chapitre %d : %s \n",chapitre,titre);
        }
    }
}
}

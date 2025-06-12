/*fichier pour mettre toute les fonctions pour récupérer les chapitres*/

#include "import.h"

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
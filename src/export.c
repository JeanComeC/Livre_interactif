/*fichier pour créer les pages html*/

#include "export.h"

void lirelechapitre(int chapitre){
    FILE* file = fopen("src/book.txt", "r");
    if (file == NULL) {
      printf("Unable to open file <%s>\n", "src/book.txt");
      exit(EXIT_FAILURE);
    }
    
    char line[LINE_SIZE];
    while(fgets(line, sizeof(line), file)) {
        }
    }
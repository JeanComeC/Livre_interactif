/*fichier pour créer les pages html*/

#include "export.h"

void creerchapitre(){
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
          char h1[512];
          sprintf(h1,"src/export/%d.html",id);
          FILE* f = fopen(h1,"w");
          fprintf(f,"<h1>bienvenue au chapitre %d : %s</h1>",id,titre);
          }
      }
  }
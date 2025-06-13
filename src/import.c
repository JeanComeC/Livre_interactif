/*fichier pour mettre toutes les fonctions pour récupérer les éléments des chapitres*/

#include "import.h"

int recuperationID(line){ //fonction pour récupérer un id dans une ligne
  int id;
  sscanf(line,"<chapter id=\"%d\">", &id);
  return id;
}

char* recuperationTitle(line){  //fonction pour récupérer un titre dans une ligne
  char title[LINE_SIZE];
  sscanf(line,"<chapter [^>]%[^<]s",&title);
  return title;
}

char* recuperationContenue(line){ //fonction pour récupérer le contenue dans une ligne
  char contenu[LINE_SIZE];
  sscanf(line,"<p>%[^<]s",&contenu);
  return contenu;
}

int recuperationIDREF(char* line){
  int idref;
  sscanf(line,"<choice idref=\"%d\">", &idref);
  return idref;
}


// void creerchapitre(){
//   FILE* file = fopen("src/book.txt", "r");
//   if (file == NULL) {
//     printf("Unable to open file <%s>\n", "src/book.txt");
//     exit(EXIT_FAILURE);
//   }
  
//   char line[LINE_SIZE];
//   while(fgets(line, sizeof(line), file)) {
//       if(strstr(line, "<chapter id") != NULL){
//           int id = 0;
//           char titre[512];
//           sscanf(line,"<chapter id=\"%d\">%[^<]s", &id, &titre);
//           char h1[512];
//           sprintf(h1,"src/export/%d.html",id);
//           FILE* f = fopen(h1,"w");
//           fprintf(f,"<h1>bienvenue au chapitre %d : %s</h1>",id,titre);
//           fprintf(f,"<h1>bienvenue au chapitre %d : %s</h1>",id,titre);
//           }
//       }
// }
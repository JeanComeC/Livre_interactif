/*fichier pour mettre toutes les fonctions pour récupérer les éléments des chapitres*/

#include "import.h"

void recuperationID_and_Title(char* line,char* title, int* id){ //fonction pour récupérer un id dans une ligne
  sscanf(line,"<chapter id=\"%d\">%[^<]</chapter>", id, title);
}

char* recuperationContenue(char* line,char* contenu){ //fonction pour récupérer le contenue dans une ligne
  sscanf(line,"<p>%[^<]s</p>",contenu);
}
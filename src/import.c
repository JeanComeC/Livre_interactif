/*fichier pour mettre toutes les fonctions pour récupérer les éléments des chapitres*/

#include "import.h"

void recuperationIDandTitle(char* line,int* id,char* title){ //fonction pour récupérer un id et un titre dans une ligne
  sscanf(line,"<chapter id=\"%d\">%[^<]</chapter>",id,title);
}

void recuperationContenue(char* line,char* contenu){ //fonction pour récupérer le contenue dans une ligne
  sscanf(line,"<p>%[^<]s</p>",contenu);
}

void recuperationChoice(char* line,struct Choice* choix){ //fonction pour récupérer le choix dans une ligne
  sscanf(line,"<choice idref=\"%d\">%[^<]<a>",&choix->nextChapter,choix->text);
}

void recuperationOption(char* line, char* option){//fonction pour récupérer l'option dans une ligne
    sscanf(line,"<option>%[^<]s<item>",option);
}

void recuperationFight(char* line, char* weapon, char* action){//fonction pour récupérer les éléments du combat
    sscanf(line,"<if item=\"%[^\"]\">%[^<]s</p>",weapon,action);
}
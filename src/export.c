/*fichier pour mettre toutes les fonctions pour créer les pages html*/

#include "export.h"

void creerHTML(char* nom){
	fopen(nom, "w");
}

void ecrireIdTitre(char* nom,int id, char* titre){
	FILE* f = fopen(nom,"w");
	fprintf(f,"<h1>Chapitre %d : %s</h1>",id,titre);
}

void ecrireParagraphe(char* nom,char* paragraphe){
	FILE* f = fopen(nom,"w");
	fprintf(f,"<p>%s</p>",paragraphe);
}

void ecrireChoix(char* nom,int id, char* line){
	FILE* f = fopen(nom,"w");
	char contenu[LINE_SIZE];
	char texteLien[LINE_SIZE];
	sscanf(line,"<choice idref= [^>]%[^<]s",&contenu);
	sscanf(line,"<a [^>]%[^<]s",texteLien);
	fprintf(f, "<p>%s</p><a href=\"%d.html\">%s</a>",contenu,id,texteLien);
}
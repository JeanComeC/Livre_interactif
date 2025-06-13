/*fichier pour mettre toutes les fonctions pour créer les pages html*/

#include "export.h"

void creerHTML(char* nom,int id){ // fonction pour créer un fichier html
	FILE* f = fopen(nom, "w");
	fclose(f);
}

void ecrireIdTitre(char* nom,int id, char* titre){ // fonction pour écrire le numéro et le titre du chaapitre dans le fichier html
	FILE* f = fopen(nom,"a");
	fprintf(f,"<h1>Chapitre %d : %s</h1>\n",id,titre);
	fclose(f);
}

void ecrireParagraphe(char* nom,char* paragraphe){ // fonction pour écrire les paragraphes dans le fichier html
	FILE* f = fopen(nom,"a");
	fprintf(f,"<p>%s</p>\n",paragraphe);
	fclose(f);
}

void ecrireChoix(char* nom, char* line){ // fonction pour écrire le choix dans le fichier html
	FILE* f = fopen(nom,"a");
	char contenu[LINE_SIZE];
	char texteLien[LINE_SIZE];
	int id = 0;
	sscanf(line,"<choice idref=\"%d\">%[^<] <a>%[^<]s</a>",&id,contenu,texteLien); 
	fprintf(f, "<p>%s<a href=\"%d.html\">%s</a></p>",contenu,id,texteLien);
	fclose(f);
}
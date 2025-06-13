#include "import.h"
#include "export.h"

int main(){
    FILE* file = fopen("src/book.txt", "r");
	if (file == NULL) {
  		perror("Unable to open file book.txt");
  		exit(EXIT_FAILURE);
	}
    char line[LINE_SIZE];
    char nom_fichier[LINE_SIZE];

    while(fgets(line, sizeof(line), file)) { //boucle qui analyse ligne par ligne

    //on s'occupe des lignes commencant par chapter
    if(strstr(line, "<chapter") != NULL){ //on regarde si c'est un nouveau chapitre
      int id;
      char titre[LINE_SIZE];
      recuperationID_and_Title(line, titre, &id);
		  sprintf(nom_fichier,"src/export/%d.html",id);
        //on créé le fichier html :
        creerHTML(nom_fichier, id);
        //On récupère le titre et on l'envoie directement sur la page html avec l'id
        ecrireIdTitre(nom_fichier,id,titre);
    }
    
    //On s'occupe du contenu, donc quand les lignes commencent par <p>
    if(strstr(line,"<p>")){
      char contenu[LINE_SIZE];
      recuperationContenue(line,contenu);
      //printf("%s\n",contenu);
      ecrireParagraphe(nom_fichier,contenu);
    }
    //On s'occupe du choix
    if(strstr(line, "<choice")){
      ecrireChoix(nom_fichier,line);
    }
    
  }
}

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
		sprintf(nom_fichier,"src/export/%d.html",recuperationID(line));
        char* titre=recuperationTitle(line);
        //on créé le fichier html :
        creerHTML(nom_fichier);
        //On récupère le titre et on l'envoie directement sur la page html avec l'id
        ecrireIdTitre(nom_fichier,recuperationID(line),recuperationTitle(line));
    }
    
    //On s'occupe du contenu, donc quand les lignes commencent par <p>
    if(strstr(line,"<p>")){
        ecrireParagraphe(nom_fichier,recuperationContenue(line));
    }
    //On s'occupe du choix
    if(strstr(line, "<choice")){
        ecrireChoix(nom_fichier,recuperationIDREF(line),line);
    }
    
  }
}

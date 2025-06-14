#include "import.h"
#include "render.h"
#include "algo.h"

int main(){
//Initialisation :
    FILE* file = fopen("src/book.txt", "r");
	if (file == NULL) {
  		perror("Unable to open file book.txt");
  		exit(EXIT_FAILURE);
	}
    char line[LINE_SIZE];

//Boucle qui analyse ligne par ligne
    while(fgets(line, sizeof(line), file)) {

    //on s'occupe des lignes commencant par chapter
    if(strstr(line, "<chapter") != NULL){ //on regarde si c'est un nouveau chapitre
        //
    }
    
    //On s'occupe du contenu, donc quand les lignes commencent par <p>
    if(strstr(line,"<p>")){
        //
    }

    //on s'occupe de l'item
    if(strstr(line,"<option>")){
        //
    }

    //On s'occupe du choix
    if(strstr(line, "<choice")){
        //
    }
    
    }
//Libération mémoire
    //
}

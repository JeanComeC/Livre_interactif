#include "import.h"
#include "render.h"
#include "algo.h"
int remplissage_BigTableau(struct BigTableau* BigTableau);

int main(){
//Initialisation :
    //inventaire:
    struct Inventaire tableau_inventaire = init_tab_inventaire();
    //BigTableau
    struct BigTableau BigTableau = init_BigTableau();
    //struct StringArray 

    //Remplissage BigTableau
    if(remplissage_BigTableau(&BigTableau)!=0){
        perror("Erreur remplissage BigTableau");
        exit(1);
    }

//Partie sans nom
    //



//Libération mémoire
    //
}

//Fonctions

int remplissage_BigTableau(struct BigTableau* BigTableau){//fonction pour remplir le BigTableau
    FILE* file = fopen("src/book.txt", "r");
	if (file == NULL) {
  		perror("Unable to open file book.txt");
  		exit(EXIT_FAILURE);
	}
    char line[LINE_SIZE];
    int id=0;
    struct Chapter newchapter = init_chapter();
    struct StringArray contenu = init_stringArray();
    struct ChoicesArray choix = init_choicesArray();
    struct StringArray options = init_stringArray();
    //Boucle qui lit ligne par ligne le fichier texte et le copie dans le big tableau dynamique
    while(fgets(line, sizeof(line), file)) {

        //on s'occupe des lignes commencant par chapter
        if(strstr(line, "<chapter") != NULL){ //on regarde si c'est un nouveau chapitre
            if (id > 0){
                add_BigTableau(BigTableau,newchapter);
            }
            while(fgets(line, sizeof(line), file)){
                recuperationTitle(line,newchapter.title);
                //On s'occupe du contenu, donc quand les lignes commencent par <p>
                if(strstr(line,"<p>")){
                    char* contenuText;
                    recuperationContenue(line,contenuText);
                    add_stringArray(&contenu,contenuText);
                    BigTableau->chapter[id].contenu=contenu;
                }
    
                //on s'occupe de l'item
                if(strstr(line,"<option>")){
                    //
                }
    
                //On s'occupe du choix
                if(strstr(line, "<choice>")){
                    //
                }
            }
            
        }
        
          
    }
    add_BigTableau(BigTableau,struct Chapter chapter);
    //si y'a pas eu d'erreus avant, on retourne 0.
    return 0;
}
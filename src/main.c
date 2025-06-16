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

    //Boucle qui lit ligne par ligne le fichier texte et le copie dans le big tableau dynamique
    while(fgets(line, sizeof(line), file)) {

        //on s'occupe des lignes commencant par chapter
        if(strstr(line, "<chapter") != NULL){ //on regarde si c'est un nouveau chapitre
            if (id > 0){
                add_BigTableau(BigTableau,newchapter);
            }

            recuperationTitle(line,newchapter.title);
            id++;
        }

        //On s'occupe du contenu, donc quand les lignes commencent par <p>
        if(strstr(line,"<p>")){
            char contenuText[LINE_SIZE];
            recuperationContenue(line,contenuText);
            add_stringArray(&newchapter.contenu,contenuText);
        }

        //On s'occupe du choix
        if(strstr(line, "<choice>")){
            struct Choice choix;
            recuperationChoice(line,&choix);
            add_choiceArray(&newchapter.choices,choix);
        }

        //on s'occupe de l'option
        if(strstr(line,"<option>")){
            char option[LINE_SIZE];
            recuperationOption(line,option);
            add_stringArray(&newchapter.options,option);
        }
    }



    add_BigTableau(BigTableau,newchapter);
    //si y'a pas eu d'erreus avant, on retourne 0.
    return 0;
}
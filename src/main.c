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
    printf("ca marche\n");

    //Remplissage BigTableau
    if(remplissage_BigTableau(&BigTableau)!=0){
        perror("Erreur remplissage BigTableau\n");
        exit(1);
    }
    printf("ca marche\n");
    //test :
    // printf("%d\n", BigTableau.size); //=>30
    // for (int i = 0; i < BigTableau.size; i++) {
    //     printf("%s\n",BigTableau.chapter[i].contenu.text[0]);
    // }
    // printf("%s\n",BigTableau.chapter[2].contenu.text[1]);

    
//Affichage :
    int* id_prochain_chapitre = 0;
    struct Chapter* chapitre_actuel = &BigTableau.chapter[0];//je veux envoyer à la fonction affichage_complet que le chapitre qu'elle doit afficher, donc je commence avec le chapitre 1.
    if(affichage_complet(chapitre_actuel,&tableau_inventaire,id_prochain_chapitre)!=0){
        perror("Erreur Affichage : voir Alexandre (c'est de sa faute)\n");
        exit(1);
    }


//Libération mémoire :
    destroy_tab_inventaire(&tableau_inventaire);
}

//Fonctions

int remplissage_BigTableau(struct BigTableau* BigTableau){//fonction pour remplir le BigTableau
    FILE* file = fopen("src/book.txt", "r");
	if (file == NULL) {
  		perror("Unable to open file book.txt\n");
  		exit(EXIT_FAILURE);
	}
    char line[LINE_SIZE];
    int id_00=0;
    struct Chapter newchapter = init_chapter();

    //Boucle qui lit ligne par ligne le fichier texte et le copie dans le big tableau dynamique
    while(fgets(line, sizeof(line), file)) {

        //on s'occupe des lignes commencant par chapter
        if(strstr(line, "<chapter") != NULL){ //on regarde si c'est un nouveau chapitre
            if (id_00 > 0){
                add_BigTableau(BigTableau,newchapter);
                newchapter = init_chapter();
            }

            recuperationIDandTitle(line,&newchapter.id,newchapter.title);
            id_00++;
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
            char* item_line = strstr(line, "<item>");
            char option[LINE_SIZE];
            recuperationOption(item_line,option);
            add_stringArray(&newchapter.options,option);
        }

        //on s'occupe des conditions de combats
        if(strstr(line,"<if item")){
            char weapon[LINE_SIZE];
            char action[LINE_SIZE];
            recuperationFight(line,weapon,action);
            add_stringArray(&newchapter.fight.weapons,weapon);
            add_stringArray(&newchapter.fight.actions,action);
        }
    }
    add_BigTableau(BigTableau,newchapter);
    fclose(file);
    //si y'a pas eu d'erreus avant, on retourne 0.
    return 0;
}
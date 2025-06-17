//Fichier pour mettre les fonctions pour l'affichage, avec ncurses

#include "render.h"

int affichage_complet(struct Chapter* chapter,struct Inventaire* inventaire){
    WINDOW* w = initscr();
    if(keypad(stdscr, true)<0){//vérifier la doc de keypad !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        perror("Erreur keypad\n");
        exit(1);
    }
    //Va falloir faire des printf() pour debug !

    // Création des choix du premier chapitre => ca ne sert à rien
    struct ChoicesArray tabchoix;
    tabchoix.size = 3;
    tabchoix.capacity = 3;
    tabchoix.choice = malloc(3 * sizeof(struct Choice));

    strcpy(chapter->choices.choice->text, "Suivre le chemin au sud, qui mène à la Forêt de Bois-Perdu.");//je crois que ça non plus ça ne sert à rien
    tabchoix.choice[0].nextChapter = 2;
    tabchoix.choice[0].item[0] = '\0'; // Pas d'objet requis

    strcpy(tabchoix.choice[1].text, "Vous dirigez vers l’Est, où un ancien château a été aperçu par les voyageurs.");//ainsi que ça
    tabchoix.choice[1].nextChapter = 3;//et ce qui suis
    tabchoix.choice[1].item[0] = '\0';

    strcpy(tabchoix.choice[2].text, "Explorer l’Ouest, où un vieux puits abandonné intrigue les villageois.");//et ça
    tabchoix.choice[2].nextChapter = 11;
    tabchoix.choice[2].item[0] = '\0';//et ça




    int PV = 100;
    char chapitre[128];
    sprintf(chapitre,"Chapitre %d",chapter->id);
    //char* contenu = "ce message fait 30 caractères de long, il est affiché au milieu de l'écran. Il est important de noter que le contenu peut être long et doit être divisé en plusieurs lignes pour une meilleure lisibilité. Voici un exemple de contenu qui pourrait être affiché dans un jeu d'aventure textuel, où le joueur explore un village mystérieux et rencontre divers personnages et événements intrigants.";
    char* contenu = chapter->contenu.text[0];
    print_infopersonnage(w,PV);
    print_center(w,3,chapitre);
    print_center(w,5,chapter->title);

    char chaine_diviser[91];
    int ligne = 8;

    while (strlen(contenu) > 0) {
        strncpy(chaine_diviser, contenu, 90);
        contenu += MIN(90, strlen(contenu));
        print_center(w,ligne++,chaine_diviser);
    }
    refresh();//recharge la page

    afficherchoices(w,tabchoix);
    int choix = choisir_choix(w, tabchoix, inventaire);
    printw("\n\n                    Vous avez choisi le chapitre %d", choix);


    getch();
    clear();
    endwin();
    return 0;
}

void print_center(WINDOW* w, int line, char* str) { 
    int max_length = getmaxx(w);
    int taille_mot = strlen(str);
    int position = max_length*2/5-taille_mot/2;
    mvprintw(line, position, "%s", str);
}

void print_infopersonnage(WINDOW* w,int PV){
    int max_length = getmaxx(w);
    int position = max_length-20;
    box(w, 0, 0);
    mvprintw(1,position,"___________________");
    mvprintw(2,position,"|");
    mvprintw(3,position,"| PV : %d",PV);
    mvprintw(4,position,"|     ---------");
    mvprintw(5,position,"| INVENTAIRE");
    mvprintw(6,position,"| Nombre d'objets");
    mvprintw(7,position,"| O / 3 objets");
    mvprintw(8,position,"|__________________");
}

void afficherchoices(WINDOW* w,struct ChoicesArray tabchoix){
    print_center(w, 16, "1er choix <- / 2eme choix -> / 3eme choix ^ / 4eme choix v");
    for(int i=0; i < tabchoix.size ;i++){
        print_center(w, 18 + i, tabchoix.choice[i].text);
    }

}

int choisir_choix(WINDOW* w,struct ChoicesArray tabchoix,struct Inventaire* inventaire){ //il retourne le prochain chapitre
    int ch;

    while ((ch = getch()) != '\n'){
        refresh();


        if (ch == KEY_RIGHT) {
            if (strlen(tabchoix.choice[1].item) != 0) {
                if (get_tab_inventaire(inventaire, tabchoix.choice[1].item)) {
                    return tabchoix.choice[1].nextChapter;
                } else {
                    mvprintw(30, 0, "Vous n'avez pas l'objet requis pour ce choix.");
                    refresh();
                    continue;
                }
            }
                return tabchoix.choice[1].nextChapter;
        }


        if (ch == KEY_LEFT) {
            if (strlen(tabchoix.choice[0].item) != 0) {
                if (get_tab_inventaire(inventaire, tabchoix.choice[0].item)) {
                    return tabchoix.choice[0].nextChapter;
                } else {
                    mvprintw(30, 0, "Vous n'avez pas l'objet requis pour ce choix.");
                    refresh();
                    continue;
                }
            }
                return tabchoix.choice[0].nextChapter;
        }


        if (ch == KEY_UP) {
            if (strlen(tabchoix.choice[2].item) != 0) {
                if (get_tab_inventaire(inventaire, tabchoix.choice[2].item)) {
                    return tabchoix.choice[2].nextChapter;
                } else {
                    mvprintw(30, 0, "Vous n'avez pas l'objet requis pour ce choix.");
                    refresh();
                    continue;
                }
            }
                return tabchoix.choice[2].nextChapter;
            }
        if (ch == KEY_DOWN) {
            if (strlen(tabchoix.choice[3].item) != 0) {
                if (get_tab_inventaire(inventaire, tabchoix.choice[3].item)) {
                    return tabchoix.choice[3].nextChapter;
                } else {
                    mvprintw(30, 0, "Vous n'avez pas l'objet requis pour ce choix.");
                    refresh();
                    continue;
                    }
                }
                return tabchoix.choice[3].nextChapter;
            }
    }
}

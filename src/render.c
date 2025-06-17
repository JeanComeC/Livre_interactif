//Fichier pour mettre les fonctions pour l'affichage, avec ncurses

#include "render.h"

int affichage_complet(struct Chapter* chapter,struct Inventaire* inventaire,int *id_prochain_chapitre){
    WINDOW* w = initscr();
    if(keypad(stdscr, true)<0){//vérifier la doc de keypad !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        perror("Erreur keypad\n");
        exit(1);
    }

    int PV = 100;
    char chapitre[128];
    sprintf(chapitre,"Chapitre %d",chapter->id);
    // char* contenu = "ce message fait 30 caractères de long, il est affiché au milieu de l'écran. Il est important de noter que le contenu peut être long et doit être divisé en plusieurs lignes pour une meilleure lisibilité. Voici un exemple de contenu qui pourrait être affiché dans un jeu d'aventure textuel, où le joueur explore un village mystérieux et rencontre divers personnages et événements intrigants.";
    char* contenu = chapter->contenu.text[0];
    print_infopersonnage(w,PV);
    print_center(w,3,chapitre);
    print_center(w,5,chapter->title);

    char chaine_diviser[91];
    int ligne = 8;

    if (chapter->contenu.size == 0 || chapter->contenu.text == NULL || chapter->contenu.text[0] == NULL) {
        print_center(w, 8, "Aucun contenu à afficher.");
        refresh();
        getch();
        endwin();
        return 1;
    }

    
    while (strlen(contenu) > 0) {
        strncpy(chaine_diviser, contenu, 90);
        contenu += MIN(90, strlen(contenu));
        print_center(w,ligne++,chaine_diviser);
    }
    refresh();//recharge la page

    id_prochain_chapitre = choisir_choix(w, chapter->choices, inventaire); //on récupère le prochain chapitre
    
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

void afficherchoices(WINDOW* w,struct ChoicesArray tabchoix, int selected){
    print_center(w, 16, "Choix disponibles :");
    for(int i=0; i < tabchoix.size ;i++){
        if (i == selected) {
            attron(A_REVERSE); // Met en surbrillance le choix sélectionné
            print_center(w, 18 + i, tabchoix.choice[i].text);
            attroff(A_REVERSE); // Retire la surbrillance
        }
        else{
        print_center(w, 18 + i, tabchoix.choice[i].text);
    }
    }

}

int choisir_choix(WINDOW* w,struct ChoicesArray tabchoix,struct Inventaire* inventaire){ //il retourne le prochain chapitre
    int ch;
    int selected = 0; // Indice du choix sélectionné

    while (1) {
        afficherchoices(w,tabchoix, selected);
        refresh();
        ch = getch();

        if( ch == KEY_UP) {
            selected = (selected + 1) % tabchoix.size; //navigation à droite
        } 
        else if (ch == KEY_DOWN) {
            selected = (selected -1 + tabchoix.size) % tabchoix.size; //navigation à gauche
        }
        else if (ch == KEY_ENTER || ch == '\n' || ch == '\r') {
            if (strlen(tabchoix.choice[selected].item) != 0) {
                if (get_tab_inventaire(inventaire, tabchoix.choice[selected].item)) {
                    return tabchoix.choice[selected].nextChapter;
                } else {
                    mvprintw(30, 0, "Vous n'avez pas l'objet requis pour ce choix.");
                    refresh();
                    continue;
                }
            }
            return tabchoix.choice[selected].nextChapter;
        }
        
    }
}
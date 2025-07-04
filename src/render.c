//Fichier pour mettre les fonctions pour l'affichage, avec ncurses

#include "render.h"

int affichage_complet(WINDOW* windows,struct Chapter* chapter,struct Inventaire* inventaire,int* PV,int *id_prochain_chapitre){
    if(keypad(stdscr, true)<0){
        perror("Erreur keypad\n");
        exit(1);
    }
    char chapitre[128];
    sprintf(chapitre,"Chapitre %d",chapter->id);
    char* contenu = chapter->contenu.text[0];
    print_infopersonnage(windows,*PV,inventaire); //print l'inventaire et les PV
    print_center(windows,3,chapitre);// print le chapitre
    print_center(windows,5,chapter->title);// print le titre du chapitre

    if (chapter->contenu.size == 0 || chapter->contenu.text == NULL || chapter->contenu.text[0] == NULL) { // Vérification si le contenu est vide
        print_center(windows, 8, "Aucun contenu à afficher.");
        refresh();
        getch();
        endwin();
        return 1;
    }

    char chaine_diviser[81];
    int ligne = 8;
    
    while (strlen(contenu) > 0) { // Affichage du contenu par tranche de 80 caractères
        strncpy(chaine_diviser, contenu, 80);
        contenu += MIN(80, strlen(contenu)); // Avance le pointeur de contenu
        print_center(windows,ligne++,chaine_diviser);
    }
    refresh();//recharge la page

    if (chapter->choices.size == 0 || chapter->choices.choice == NULL) { // Vérification si les choix sont vides
        print_center(windows, 16, "Aucun choix disponible.");
        refresh();
        getch();
        endwin();
        return 1;
    }

    if(condition_item(windows,inventaire,chapter)==false ){ //si on n'a pas d'item
        if(chapter->fight.actions.size > 0 && strcmp(chapter->fight.actions.text[chapter->fight.actions.size - 1],"Vous survivez, blesse (perdez 3 PV).") == 0){
            perdre_degats(PV);
            char* message = "Vous perdez 3 PV";
            print_center(windows,28,message);
        }    
    }

    *id_prochain_chapitre = choisir_choix(windows, chapter, inventaire); //on récupère le prochain chapitre
    if(*PV <= 0){
        *id_prochain_chapitre = 27;
    }

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

void print_infopersonnage(WINDOW* w,int PV,struct Inventaire* inventaire){
    int max_length = getmaxx(w);
    int position = max_length-24;
    box(w, 0, 0);
    mvprintw(1,position,"_______________________");
    mvprintw(2,position,"|");
    mvprintw(3,position,"| PV : %d",PV);
    mvprintw(4,position,"|     ---------");
    mvprintw(5,position,"| INVENTAIRE");
    mvprintw(6,position,"| Nombre d'objets");
    mvprintw(7,position,"| %d / 3 objets", inventaire->size);
    mvprintw(8,position,"|______________________");
    mvprintw(9,position,"|");
    mvprintw(10,position,"|");
    mvprintw(11,position,"|");
    mvprintw(12,position,"|______________________");

    for (int i = 0; i < inventaire->size; i++) {
        mvprintw(9 + i, position, "| %s", inventaire->item[i].name);
        refresh();
    }
}

void afficherchoices(WINDOW* w,struct Chapter* tabchoix, int selected){
    print_center(w, 16, "Choix disponibles :");
    mvprintw(14, getmaxx(w)-30, "Options disponibles");
    for(int i=0; i < tabchoix->choices.size ;i++){
        if (i == selected) {
            attron(A_REVERSE); // Met en surbrillance le choix sélectionné
            print_center(w, 18 + i, tabchoix->choices.choice[i].text);
            attroff(A_REVERSE); // Retire la surbrillance
        }
        else{
        print_center(w, 18 + i, tabchoix->choices.choice[i].text); // Affiche le texte du choix
        }
    }
    for (int i = 0; i < tabchoix->options.size; i++)
    {
        mvprintw(16 + i,getmaxx(w)-30 ,tabchoix->options.text[i]); // Affiche les options disponibles
    }
    refresh();
}

void afficheroptions(WINDOW* w,struct Chapter* tabchoix, int selected){
    mvprintw(14, getmaxx(w)-30, "Options disponibles");
    for(int i=0; i < tabchoix->options.size ;i++){
        if (i == selected) {
            attron(A_REVERSE); // Met en surbrillance le choix sélectionné
            mvprintw(16 + i, getmaxx(w)-30, tabchoix->options.text[i]);
            attroff(A_REVERSE); // Retire la surbrillance
        }
        else{
        mvprintw(16 + i, getmaxx(w)-30, tabchoix->options.text[i]);
        }
    }
    for (int i = 0; i < tabchoix->choices.size; i++)
    {
        print_center(w, 18 + i, tabchoix->choices.choice[i].text);
    }
    refresh();
}

int choisir_choix(WINDOW* w,struct Chapter* tabchoix,struct Inventaire* inventaire){ //il retourne le prochain chapitre
    int ch;
    int selected = 0; // Indice du choix sélectionné
    afficherchoices(w,tabchoix, selected);
    
    while (1) {
        refresh();
        ch = getch();

        if( ch == KEY_DOWN) {
            selected = (selected + 1) % tabchoix->choices.size; //navigation à droite
            afficherchoices(w,tabchoix, selected);
            refresh();
        } 
        else if (ch == KEY_UP) {
            selected = (selected -1 + tabchoix->choices.size) % tabchoix->choices.size; //navigation à gauche
            afficherchoices(w,tabchoix, selected);
            refresh();
        }


                if( ch == KEY_RIGHT){
                    selected = 0; // Réinitialiser la sélection à 0 pour les options
                    afficheroptions(w, tabchoix, selected);
                    refresh();
                    while (1) { // Remplacer 'condition' par la condition d'arrêt appropriée
                        ch = getch();
                        if (ch == KEY_DOWN) {
                            selected = (selected + 1) % tabchoix->options.size; // Navigation à droite
                            afficheroptions(w, tabchoix, selected);
                            refresh();
                        } 
                        else if (ch == KEY_UP) {
                            selected = (selected - 1 + tabchoix->options.size) % tabchoix->options.size; // Navigation à gauche
                            afficheroptions(w, tabchoix, selected);
                            refresh();
                        }
                        else if (ch == KEY_ENTER || ch == '\n' || ch == '\r') {
                            struct Item new_item;
                            strcpy(new_item.name, tabchoix->options.text[selected]);

                            if (inventaire->size >= inventaire->capacity) {
                                mvprintw(30, 0, "|          Vous n'avez plus de place dans votre inventaire.");
                                refresh();
                                continue; // Continuer la boucle pour éviter de sortir
                            }
                            add_tab_inventaire(inventaire, new_item); // Ajouter l'option sélectionnée à l'inventaire
                            print_infopersonnage(w, 10, inventaire);
                            refresh();
                            mvprintw(30, 0, "|          Vous avez ajouté %s à votre inventaire.", tabchoix->options.text[selected]);
                            refresh();
                        }
                        else if (ch == KEY_LEFT) {
                            selected = 0;
                            afficherchoices(w, tabchoix, selected);
                            refresh();
                            break; // Sortir de la boucle pour revenir aux choix
                    }
                }
            }


        if( ch == KEY_LEFT){
            afficherchoices(w,tabchoix, selected);
            refresh();
        }
        else if (ch == KEY_ENTER || ch == '\n' || ch == '\r' ) {
            if(tabchoix->choices.choice->item != NULL){
                remove_item_tab_inventaire(inventaire, tabchoix->choices.choice[selected].item); // On retire l'item de l'inventaire
            }
            int tmp = tabchoix->choices.choice[selected].nextChapter;
            return tmp;
        }
        
    }
}

bool condition_item(WINDOW* windows,struct Inventaire* inventaire,struct Chapter* chapter){
    bool verif = chapter->fight.weapons.size == 0;
    for(int i=0;i<chapter->fight.weapons.size;i++){
        struct Item item;
        strcpy(item.name,chapter->fight.weapons.text[i]);
        if(get_tab_inventaire(inventaire,item.name)){
            add_choiceArray(&chapter->choices, chapter->fight.choice); // On ajoute le choix du combat aux choix du chapitre
            verif = true;
        }
    }
    return verif;
}

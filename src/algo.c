//fichier pour mettre les fonctions pour toute l'algorythmique du jeu

#include "algo.h"


struct Inventaire init_tab_inventaire(){
    struct Inventaire inventaire;
    struct Item* init = malloc(3*sizeof(struct Item));
    if(init == NULL){
        fprintf(stderr,"Memory error");
        exit(1);
    }
    inventaire.item = init;
    inventaire.size = 0;
    inventaire.capacity = 3;
    return inventaire;
}

void add_tab_inventaire(struct Inventaire* tab, struct Item new_item){
    if(tab->size >= tab->capacity){
        return;
    }
    tab -> item[tab->size++] = new_item;
}

void remove_item_tab_inventaire(struct Inventaire* tab, char* rem_item){
    for(int i=0; i<tab->size;i++){
        if(strcmp(tab->item[i].name,rem_item) == 0){
            tab->item[i] = tab->item[tab->size];
            tab->size --;
        }
    }
}

void destroy_tab_inventaire(struct Inventaire* inventaire){
    free(inventaire->item);
    inventaire->item = NULL;
    inventaire->capacity=0;
    inventaire->size=0;
}

bool get_tab_inventaire(struct Inventaire* tab, char* item){
    for(int i=0;i<tab->size;i++){
        if(strcmp(tab[i].item->name,item) == 0){
            return true;
        }
    }
    return false;
}

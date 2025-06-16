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
        printf("t'as plus de place batard");
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

struct StringArray init_stringArray(){
    struct StringArray array;
    char** init = malloc(2*sizeof(char*));
    if(init==NULL){
        fprintf(stderr,"Memory error");
        exit(1);
    }
    array.text = init;
    array.capacity=2;
    array.size=0;
    return array;
}

void add_stringArray(struct StringArray* array, char* paragraphe){
    if(array->size >= array->capacity){
        array->capacity *= 2;
        char** new_value = malloc(array->capacity*sizeof(char*));
        if(new_value == NULL){
            fprintf(stderr,"memory error");
            exit(1);
        }
        for(int i=0; i<array->size;i++){
            new_value[i] = array->text[i];
        }
        free(array->text);
        array->text = new_value;
    }
    char* entry = malloc(strlen(paragraphe)*sizeof(char));
    array->text[array->size] = entry;
    strcpy(array->text[array->size++],paragraphe);
}

struct ChoicesArray init_choicesArray(){
    struct ChoicesArray choiceArray;
    struct Choice* init = malloc(2*sizeof(struct Choice));
    if(init==NULL){
        fprintf(stderr,"Memory error");
        exit(1);
    }
    choiceArray.choice = init;
    choiceArray.capacity=2;
    choiceArray.size=0;
    return choiceArray;
}

void add_choiceArray(struct ChoicesArray* choiceArray, struct Choice choice){
    if(choiceArray->size >= choiceArray->capacity){
        choiceArray->capacity *= 2;
        struct Choice* newvalue = malloc(choiceArray->capacity*sizeof(struct Choice));
        if(newvalue == NULL){
            fprintf(stderr,"Memory error");
            exit(1);
        }
        for(int i=0; i<choiceArray->size;i++){
            newvalue[i] = choiceArray->choice[i];
        }
        free(choiceArray->choice);
        choiceArray->choice = newvalue;
    }
    choiceArray->choice[choiceArray->size++] = choice;
}

struct Chapter init_chapter(){
    struct Chapter chapter;
    chapter.id=0;
    chapter.title;
    chapter.fight ==================================================> je pense que l'erreur est là car on initialise pas tous les tableaux dynamiques de fights.
    chapter.contenu = init_stringArray();
    chapter.choices = init_choicesArray();
    chapter.options = init_stringArray();
    return chapter;
}

struct BigTableau init_BigTableau(){
    struct BigTableau tableau;
    struct Chapter* init = malloc(2*sizeof(struct Chapter));
    if(init==NULL){
        fprintf(stderr,"Memory error");
        exit(1);
    }
    tableau.chapter = init;
    tableau.size=0;
    tableau.capacity=2;
    return tableau;
}

void add_BigTableau(struct BigTableau* tableau,struct Chapter chapter){
    if(tableau->size >= tableau->capacity){
        tableau -> capacity *= 2;
        struct Chapter* newValue = malloc(tableau->capacity*sizeof(struct Chapter));
        if(newValue == NULL){
            fprintf(stderr,"Memory error");
            exit(1);
        }
        for(int i=0; i<tableau->size;i++){
            newValue[i] = tableau->chapter[i];
        }
        free(tableau->chapter);
        tableau->chapter = newValue;
    }
    tableau->chapter[tableau->size++] = chapter;
}
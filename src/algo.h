#ifndef ALGO_H
#define ALGO_H

//Structures
struct Item{
    char name[50];
    int pv;
    int degat;
};

struct Inventaire{
    int size;
    int capacity;
    struct Item* item;
};

struct StringArray{
    char** text;
    int size;
    int capacity;
};

struct Choice{
    char text[512];
    int nextChapter;
    char item[256];//condition pour après
};

struct ChoicesArray{
    struct Choice* choice;
    int size;
    int capacity;
};

struct Fight{
    struct StringArray weapons;
    struct StringArray actions;
    struct Choice choice;
    int degats;
};
struct Chapter{
    int id; //j'ai rajouté l'id c'est plus simple.
    char* title;
    struct StringArray contenu;
    struct ChoicesArray choices;
    struct StringArray options; //c'est que le nom des items.
    struct Fight fight;
};

struct BigTableau{
    struct Chapter* chapter;
    int size;
    int capacity;
};
//MACRO

//BIBLIOTHEQUE

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//PROTOTYPES

struct Inventaire init_tab_inventaire();
void add_tab_inventaire(struct Inventaire* tab, struct Item new_item); 
void remove_item_tab_inventaire(struct Inventaire* tab, char* rem_item);
void destroy_tab_inventaire(struct Inventaire* inventaire);
bool get_tab_inventaire(struct Inventaire* tab, char* item);
void perdre_degats(int* PV);
struct StringArray init_stringArray();
struct BigTableau init_BigTableau();
struct ChoicesArray init_choicesArray();
struct Chapter init_chapter();
struct Fight init_fight();
void add_stringArray(struct StringArray* array, char* paragraphe);
void add_choiceArray(struct ChoicesArray* choiceArray, struct Choice choice);
void add_BigTableau(struct BigTableau* tableau,struct Chapter chapter);
void destroy_stringArray(struct StringArray* array);
void destroy_choiceArray(struct ChoicesArray* choiceArray);
void destroy_fight(struct Fight* fight);
void destroy_chapter(struct Chapter* chapter);
void destroy_bigTableau(struct BigTableau* tableau);

//rajouter les fonctions destroy  =>  autant de free() que de malloc()

#endif
#ifndef ALGO_H
#define ALGO_H

//Structures
struct Item{
    char* name;
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
    char item[256];
};

struct ChoicesArray{
    struct Choice* choice;
    int size;
    int capacity;
};

struct Chapter{
    char title[50];
    struct StringArray contenu;
    struct ChoicesArray choices;
    struct StringArray options;
    struct Fight fight;
};

struct BigTableau{
    struct Chapter* chapter;
    int size;
    int capacity;
};

struct Fight{
    struct StringArray weapons;
    struct StringArray actions;
    int degats;
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
struct StringArray init_stringArray();
struct BigTableau init_BigTableau();
struct ChoicesArray init_choicesArray();
struct Chapter init_chapter();
void add_stringArray(struct StringArray* array, char* paragraphe);
void add_choiceArray(struct ChoicesArray* choiceArray, struct Choice choice);
void add_BigTableau(struct BigTableau* tableau,struct Chapter chapter);

#endif
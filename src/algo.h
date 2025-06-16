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
    struct Choice choice;
};

struct Chapter{
    char title[50];
    struct StringArray paragraphe;
    struct ChoicesArray choices;
    struct Item item;
    struct StringArray options;
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

#endif
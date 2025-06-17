#ifndef RENDER_H
#define RENDER_H

//MACRO

//BIBLIOTHEQUE
#include "algo.h"
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>
#include <sys/param.h>
//PROTOTYPES
void print_center(WINDOW* w, int line, char* str);
void print_infopersonnage(WINDOW* w,int PV);
void afficherchoices(WINDOW* w,struct ChoicesArray tabchoix,int selected);
int choisir_choix(WINDOW* w,struct ChoicesArray tabchoix,struct Inventaire* inventaire);
int affichage_complet(struct Chapter* chapter,struct Inventaire* inventaire, int* id_prochain_chapitre);

#endif
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

#endif
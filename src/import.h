#ifndef IMPORT_H
#define IMPORT_H

//MACRO
#define LINE_SIZE 1024
//BIBLIOTHEQUE
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include <unistd.h>
#include "algo.h"

//PROTOTYPES
void recuperationIDandTitle(char* line,int* id,char* title);//J'ai re-changé le prototype de la fonction, en fait Alexandre avait raison.
void recuperationContenue(char* line, char* contenu);
void recuperationChoice(char* line,struct Choice* choix);
void recuperationOption(char* line, char* option);
void recuperationFight(char* line, char* weapon, char* action,struct Choice* choix);

#endif
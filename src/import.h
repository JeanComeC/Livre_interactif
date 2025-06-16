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
void recuperationTitle(char* line,char* title);
void recuperationContenue(char* line, char* contenu);
void recuperationChoice(char* line,struct Choice* choix);
void recuperationOption(char* line, char* option);
void recuperationFight(char* line, char* weapon, char* action);

#endif
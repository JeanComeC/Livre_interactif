#ifndef IMPORT_H
#define IMPORT_H

//MACRO
#define LINE_SIZE 512
//BIBLIOTHEQUE
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include <unistd.h>

//PROTOTYPES
void creerchapitre();//je crois que cette fonction ne sert à rien => il faut demander à Alexandre
int recuperationID(char* line);
char* recuperationTitle(char* line);
char* recuperationContenue(char* line);
int recuperationIDREF(char* line);

#endif
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

//PROTOTYPES
void recuperationID_and_Title(char* line,char* title, int* id);
char* recuperationContenue(char* line, char* contenu);

#endif
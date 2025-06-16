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
void recuperationTitle(char* line,char* title);
void recuperationContenue(char* line, char* contenu);

#endif
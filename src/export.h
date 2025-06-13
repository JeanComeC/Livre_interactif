#ifndef EXPORT_H
#define EXPORT_H

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
void creerHTML(char* nom,int id);
void ecrireIdTitre(char* nom,int id, char* titre);
void ecrireParagraphe(char* nom,char* paragraphe);
void ecrireChoix(char* nom, char* line);

#endif
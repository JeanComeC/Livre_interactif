/*fichier pour créer les pages html*/

#include "export.h"

void creerHTML(file){
	char line[LINE_SIZE];
	while(fgets(line, sizeof(line), file)) {
		if(strstr(line, "<chapter id") != NULL){
			char h1[512];
			sprintf(h1,"src/export/%d.html",recuperationID(line));
		}
	}
}
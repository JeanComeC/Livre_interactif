#include "import.h"
#include "export.h"

int main(){
  FILE* file = fopen("src/book.txt", "r");
	if (file == NULL) {
  		printf("Unable to open file <%s>\n", "src/book.txt");
  		exit(EXIT_FAILURE);
	}
  char line[LINE_SIZE]; 
  while(fgets(line, sizeof(line), file)) { //ligne par ligne
    if(strstr(line, "<chapter") != NULL){ //on regarde si c'est un nouveau chapitre
			char h1[LINE_SIZE];
			sprintf(h1,"src/export/%d.html",recuperationID(line));

    }
    if(strstr(line, "<p>")){
      
    }

    if(strstr(line, "<choice>")){

    }
    
    }
  }


  			//FILE* f = fopen(h1,"w");   a mettre dans export
			//fprintf(f,"<h1>bienvenue au chapitre %d : %s</h1>",recuperationID(line),titre);
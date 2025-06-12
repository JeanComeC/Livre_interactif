#include "import.h"
#include "export.h"

int main(){
  FILE* file = fopen("src/book.txt", "r");
	if (file == NULL) {
  		printf("Unable to open file <%s>\n", "src/book.txt");
  		exit(EXIT_FAILURE);
	}
  creerHTML(file);
  }

#include "globals.h"

FILE *source  = NULL;

int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("Uso: %s <source_file>\n", argv[0]);
		return 0;
	}

	source = fopen(argv[1], "r");
	if (source == NULL) {
		perror("fopen");
		return -1;
	}
	yyin = source;
	
    yyparse();
    fclose(source);
	return 0;
}
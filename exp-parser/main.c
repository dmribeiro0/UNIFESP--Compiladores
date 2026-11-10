#include "globals.h"

/* Variaveis globais */
Token tok;
int tok_count = 0;


int main(int argc, char *argv[]) {
	FILE *source;
	if (argc == 2) {
		if (source = fopen(argv[1], "r")) yyin = source;
		else {
			perror(argv[1]);
			return 0;
		}
	}

	avance();
	
	while(tok != END) {
		erro = 0;
		expr();
		if (tok != NEWLINE && tok != END) ERRO();
		while (tok != NEWLINE && tok != END) avance();
		if (tok == NEWLINE) avance();
		
	}
	
	return 0;
}
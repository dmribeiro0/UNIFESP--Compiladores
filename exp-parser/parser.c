#include "globals.h"
int erro = 0;

void ERRO() {
	erro = 1;
	printf("Erro no token %d: '%s'\n", tok_count, yytext);
}

void consuma(Token t) {
	if (t == tok) avance();
	else ERRO();
}

void avance() {
	tok = getToken();
	tok_count++;
}

void expr() {
	termo();
	while (tok == SUM || tok == SUB) {
		soma();
		termo();
	}
}

void soma() {
	switch (tok) {
		case SUM: consuma(SUM); break;
		case SUB: consuma(SUB); break;
		default: ERRO();
	}
}

void termo() {
	fator();
	while (tok == MUL || tok == DIV) {
		mult();
		fator();
	}
}

void mult() {
	switch (tok) {
		case MUL: consuma(MUL); break;
		case DIV: consuma(DIV); break;
		default: ERRO();
	}
}

void fator() {
	switch (tok) {
		case LPAREN: 
			consuma(LPAREN);
			expr();
			consuma(RPAREN);
			break;
		case NUM:
			consuma(NUM);
			break;
		default: ERRO();
	}
}
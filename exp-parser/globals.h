#include <stdio.h>

/* Tokens */
typedef enum Token {
	/* parenteses */
	LPAREN, RPAREN, 
	/* operadores */
	SUM, SUB, MUL, DIV,
	/* numero */
	NUM,
	/* newline */
	NEWLINE,
	/* erro */
	ERR,
	/* eof */
	END
} Token;

/* Funcao getToken para o Parser */
Token getToken();

/* Variavel global para o token atual */
extern Token tok;

/* Variaveis globais de contagem */
extern int tok_count;

/* Simbolos nao terminais da GLC e suas
 * respectivas funcoes recursivas */
void expr();
void soma();
void termo();
void mult();
void fator();

/* Funcoes auxiliares para o Parser */
void consuma(Token tok);
void avance();

/* Funcao de Erro */
void ERRO();

/* Variavel global para indicar erro no parser */
extern int erro;

/* variaveis criadas pelo flex */
extern char *yytext;
extern FILE *yyin;
#ifndef GLOBALS_H
#define GLOBALS_H

#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

/* variavel global de contagem de linha */
extern int linecount;

/* arquivo de entrada */
extern FILE *source;

/* funcoes do flex/bison */
int yylex(void);
int yyparse(void);
void yyerror(const char *s);

/* variaveis do flex */
extern char *yytext;
extern FILE *yyin;

#ifdef __cplusplus
}
#endif

#endif

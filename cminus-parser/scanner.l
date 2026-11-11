%{
	#include "globals.h"
	#include "parser.tab.h"
%}

LETRA	[a-zA-Z]
DIGITO	[0-9]

%%
else				{return ELSE;}
if					{return IF;}
int					{return INT;}
return				{return RETURN;}
void				{return VOID;}
while				{return WHILE;}
{LETRA}{LETRA}*		{return ID;}
{DIGITO}{DIGITO}*	{return NUM;}
"+"					{return SOM;}
"-"					{return SUB;}
"*"					{return MUL;}
"/"					{return DIV;}
"<="				{return MEIG;}
">="				{return MAIG;}
"=="				{return EQ;}
"!="				{return DIF;}
"<"					{return MEQ;}
">"					{return MAQ;}
"="					{return ASSIGN;}
";"					{return SEMI;}
","					{return VIR;}
"("					{return APAR;}
")"					{return FPAR;}
"["					{return ACOL;}
"]"					{return FCOL;}
"{"					{return ACHA;}
"}"					{return FCHA;}
"/*"    			{
			            int c;
			           	for ( ; ; ) {
			           		while ( (c = input()) != '*' && c != 0 ) {	// Consome o comentario
			           			if (c == '\n') linecount++;
			           		}
			           		if (c == '*') {
			           			while((c = input()) == '*');			// Consome multiplos '*'
			           			if (c == '\n') linecount++;
			           			if (c == '/') break;					// Fim do comentario
			           		}
			           		if (c == 0) {
			           			printf("Erro Lexico: EOF encontrado na linha %d dentro do comentario\n", linecount);								
			           			break;
			           		}

			           	}
			        }
[ ]					{ }
\t					{ }
\r 					{ }
\n 					{ linecount++; }
<<EOF>>				{ return 0; }
.   				{printf("Erro Lexico: '%s' %d\n", yytext, linecount);}

%%
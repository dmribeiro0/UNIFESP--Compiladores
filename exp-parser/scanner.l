%{
	#include "globals.h"
%}

DIGIT [0-9]
NUM {DIGIT}+
WHITESPACE [ \t\r]
NEWLINE [\n]
ERR [^"("")""+""-""*""/"0-9]

%%

"("				{return LPAREN;}
")"				{return RPAREN;}
"+"				{return SUM;}
"-"				{return SUB;}
"*"				{return MUL;}
"/"				{return DIV;}
{NUM}			{return NUM;}
{WHITESPACE}	{/* ignora espacos em branco */}
{NEWLINE}		{return NEWLINE;}
<<EOF>>			{return END;}
{ERR}			{
					printf("Erro lexico: '%s' nao faz parte da linguagem\n", yytext);
					return ERR;
				}

%%

Token getToken() {
	return yylex();
}
%{
	#define ELSE	300
	#define IF 		301
	#define INT		302
	#define RETURN	303
	#define VOID	304
	#define WHILE	305
	#define NUM		306
	#define ID		307
	#define SUM		308
	#define SUB		309
	#define MUL		310
	#define DIV		311
	#define LT 		312
	#define LTE 	313
	#define GT		314
	#define GTE		315
	#define EQL 	316
	#define DIFF	317
	#define ASSIGN	318
	#define COMA	319
	#define SEMI 	320
	#define LPAREN 	321
	#define RPAREN 	322
	#define LBRACK	323
	#define RBRACK	324
	#define LBRACE	325
	#define RBRACE	326
	#define LCOMM	327
	#define RCOMM	328
	#define NEWLINE	329
	#define END 	330
	#define ERR 	331
%}

LETRA	[a-zA-Z]
DIGITO	[0-9]
OUTRO	[^a-zA-Z0-9+\-*/<>=!;,(){}\[\]\r\n\t]

%%

else				{return ELSE;}
if					{return IF;}
int					{return INT;}
return				{return RETURN;}
void				{return VOID;}
while				{return WHILE;}
{LETRA}{LETRA}*		{return ID;}
{DIGITO}{DIGITO}*	{return NUM;}
"+"					{return SUM;}
"-"					{return SUB;}
"*"					{return MUL;}
"/"					{return DIV;}
"<="				{return LTE;}
">="				{return GTE;}
"=="				{return EQL;}
"!="				{return DIFF;}
"<"					{return LT;}
">"					{return GT;}
"="					{return ASSIGN;}
";"					{return SEMI;}
","					{return COMA;}
"("					{return LPAREN;}
")"					{return RPAREN;}
"["					{return LBRACK;}
"]"					{return RBRACK;}
"{"					{return LBRACE;}
"}"					{return RBRACE;}
"/*"				{return LCOMM;}
"*/"				{return RCOMM;}
[ ]					{ }
\t					{ }
\n 					{return NEWLINE;}
<<EOF>>				{printf("END"); return END;}
{OUTRO}				{return ERR;}

%%

int main(int argc, char **argv) {
	FILE *input_fptr;
	int line_count = 1, token;

	// Carregar arquivo de entrada
	if (argc == 2) {
		if (input_fptr = fopen(argv[1], "r")) yyin = input_fptr;
		else perror(argv[0]);
	}

	// Analisar arquivo

	while ((token = yylex()) != END) {
		switch (token)  {
			case NEWLINE:
				line_count++;
				break;
			case ERR:
				printf("Error on line %d: '%s'\n", line_count, yytext);
				break;
		}
	}

	return 0;
}
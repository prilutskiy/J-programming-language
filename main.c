#include "JLang.tab.c"
#include "lex.yy.c"

int main (int argc, char** argv)
{
	++argv, --argc;
	if (argc > 0)
		yyin = fopen( argv[0], "r" );
	else
		yyin = stdin;
		
	yyout = fopen("output.txt", "w");	
	
	yyparse();	
	return 0;
}

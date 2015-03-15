/* 
 * J programming language lexic analyzer 
 * Simple procedure programming leanguage with for and functions
 * flex JLang.lex
 * gcc lex.yy.c -o flexout -ll || -lfl
 * flexout sample.jl
 */

%x comment
%x line_comment

%%


[0-9]+ {printf("NUMBER");}
\& {printf("REF");}
\* {printf("POINTER");}
func {printf("FUNCTION");}
return {printf("RETURN");}
print  {printf("PRINT");}
scan  {printf("SCAN");}
void {printf("VOID");}
int  {printf("INT");}
char {printf("CHAR");}
for {printf("FOR");}
[a-z_][a-z0-9_]* {printf("IDENT");}
\( {printf("LEFT_BRACKET");}
\) {printf("RIGHT_BRACKET");}
\{ {printf("LEFT_FIGURE");}
\} {printf("RIGHT_FIGURE");}
= {printf("ASSIGNMENT");}
\,  {printf("COMMA");}
\;  {printf("SEMICOLON");}

\/\*	{ printf("MULTILINE_COMMENT_BEGIN"); BEGIN(comment); }
<comment>[^*\n]* {printf("MULTILINE_COMMENT");}
<comment>"*"+[^*/\n]* {printf("MULTILINE_COMMENT");}
<comment>\*\/ 	{ printf("MULTILINE_COMMENT_END"); BEGIN(INITIAL); }	

\/\/   {BEGIN (line_comment); }
<line_comment>.* {printf("SINGLELINE_COMMENT_BEGIN");} 
<line_comment>\n {printf("SINGLELINE_COMMENT_END");BEGIN (INITIAL);}
\&{2}|\|{2}|={2}|!=|>|>=|<|<= {printf("LOGIC");}
\+{1,2}|\-{1,2}|\*|\\ {printf("MATH");}

%%

main( argc, argv )
int argc;
char **argv;
{
	++argv, --argc;
	if ( argc > 0 )
		yyin = fopen( argv[0], "r" );
		else
			yyin = stdin;
	yylex();
	printf("\n");
}

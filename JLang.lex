/* 
 * J programming language lexic analyzer 
 * Simple procedure programming leanguage with for and functions
 * flex JLang.lex
 * gcc lex.yy.c -o flexout -ll || -lfl
 * flexout sample.jl
 */
%{
#define YYSTYPE double
#include "JLang.tab.h"
int lineNumber = 1;
%}

%x comment
%x line_comment

%%

main {return MAIN;}
return {return RETURN;}
void {return VOID;}
int  {return INT;}
char {return CHAR ;}
\* {return POINTER;}
\& {return REF;}
func {return FUNCTION;}
out  {return OUT;}
in  {return IN;}
for   {return FOR;}
[a-z_][a-z0-9_]* {return IDENT;}
\,  {return COMMA;}
\;  {return SEMICOLON;}
\( {return LEFT_BRACKET;}
\) {return RIGHT_BRACKET;}
\{ {return LEFT_FIGURE;}
\} {return RIGHT_FIGURE;}
= {return ASSIGNMENT;}
[0-9]+ {return NUMBER;}
\n	{lineNumber++;}
"!"	{return  NOT;}
"*"	{return  MULT;}
"/"	{return  DIV;}
"-"	{return  MINUS;}
"+"	{return  PLUS;}
"=="	{return  EQUAL;}
"!="	{return  NOT_EQUAL;}
"*="	{return  MULT_AND_ASSIGN;}
"/="	{return  DIV_AND_ASSIGN;}
"-="	{return  MINUS_AND_ASSIGN;}
"+="	{return  PLUS_AND_ASSIGN;}
"++"	{return  INC;}
"--"	{return  DEC;}
">="	{return  MORE_EQUAL;}
"<="	{return  LESS_EQUAL;}
">"	{return  MORE;}
"<"	{return  LESS;}
"&&"	{return  AND;}
"||"	{return  OR;}
\"([^"]|\\\")*\" {return STRING;}



\/\*	{ printf("MULTILINE_COMMENT_BEGIN"); BEGIN(comment); }
<comment>[^*\n]* {printf("MULTILINE_COMMENT");}
<comment>"*"+[^*/\n]* {printf("MULTILINE_COMMENT");}
<comment>\*\/ 	{ printf("MULTILINE_COMMENT_END"); BEGIN(INITIAL); }	

\/\/   {BEGIN (line_comment); }
<line_comment>.* {printf("SINGLELINE_COMMENT_BEGIN");} 
<line_comment>\n {printf("SINGLELINE_COMMENT_END");BEGIN (INITIAL);}

%%

int yywrap(){}

int yyerror(const char *str)
{
   	printf("\nline %d: %s\n", lineNumber, str);
}

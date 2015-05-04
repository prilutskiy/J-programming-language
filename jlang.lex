%{
#include <stdlib.h>
#include <string.h>
#define YYSTYPE double
int lineNumber = 1;
%}
%x comment
%x mono_comment

%%

main {return MAIN;}
void	{yylval.num = 2; return VOID;}
int	{yylval.num = 0; return INT;}
char	{yylval.num = 1; return CHAR;}
\* {return POINTER;}
\& {return LINK;}
procedure {return PROCEDURE;}
outp  {return OUTP;}
inp  {return INP;}
wh   {return WHILE;}
[a-z_][a-z0-9_]* {yylval.str.ptr = (char*)malloc(yyleng+1); strcpy(yylval.str.ptr, yytext); yylval.str.lineNumber = lineNumber; return IDENT;}
\,  {return COMMA;}
\;  {return SEMICOLON;}
\( {return LEFT_BRACKET;}
\) {return RIGHT_BRACKET;}
\{ {return LEFT_FIGURE;}
\} {return RIGHT_FIGURE;}
"["	{return left_sqBracket;}
"]"	{return right_sqBracket;}
= {return ASSIGNMENT;}
[0-9]+ {yylval.num = atoi(yytext); return NUMBER;}
\n	{lineNumber++;}
"!"	{return  not;}
"/"	{return  division;}
"-"	{return  minus;}
"+"	{return  plus;}
"=="	{return  compare;}
"!="	{return  not_equal;}
"*="	{return  mul_equal;}
"/="	{return  div_equal;}
"-="	{return  minus_equal;}
"+="	{return  plus_equal;}
"++"	{return  inc;}
"--"	{return  dec;}
">="	{return  more_equal;}
"<="	{return  less_equal;}
">"	{return  more;}
"<"	{return  less;}
"&&"	{return  and;}
"||"	{return  or;}
"?"	{return  quest;}
\"([^"]|\\\")*\" {yylval.str.ptr = (char*)malloc(yyleng+1); strcpy(yylval.str.ptr, yytext); yylval.str.lineNumber = lineNumber; return STRING;}



\/\*	{ BEGIN(comment); }
<comment>\n	{ ++lineNumber;}
<comment>[^*\n]*
<comment>"*"+[^*/\n]*
<comment>\*\/ 	{ BEGIN(INITIAL); }	

\/\/   {BEGIN (mono_comment); }
<mono_comment>. 
<mono_comment>\n {++lineNumber; BEGIN (INITIAL);}


%%

int yywrap(){}

int yyerror(const char *str)
{
   	printf("\nline %d: %s\n", lineNumber, str);
}
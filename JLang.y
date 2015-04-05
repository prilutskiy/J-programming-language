%{
	#include <stdlib.h>
	#include <stdio.h>
	extern int yylineno;
	extern int yylex();
%}

%defines

%token MAIN VOID INT CHAR POINTER REF FUNCTION OUT IN FOR IDENT STRING NUMBER
%token SEMICOLON LEFT_BRACKET RIGHT_BRACKET LEFT_FIGURE RIGHT_FIGURE
%token ASSIGNMENT COMMA RETURN
%token NOT MULT DIV MINUS PLUS EQUAL NOT_EQUAL MULT_AND_ASSIGN DIV_AND_ASSIGN
%token MINUS_AND_ASSIGN PLUS_AND_ASSIGN INC DEC MORE_EQUAL LESS_EQUAL MORE LESS AND OR

%start axiom
%left PLUS MINUS PLUS_AND_ASSIGN MINUS_AND_ASSIGN
%left DIV MULT DIV_AND_ASSIGN MULT_AND_ASSIGN
%left LEFT_BRACKET RIGHT_BRACKET
%left INC DEC
%left OR AND NOT
%left UMINUS
%error-verbose

%%
axiom: 	
		functions main_func
		| main_func
		;
		
main_func:
		VOID MAIN LEFT_BRACKET declaration_args RIGHT_BRACKET LEFT_FIGURE declarations operators RIGHT_FIGURE {printf("\nMAIN\n");}
		;
	
functions: 	
		function 
		| functions function
		;

functionDeclaration: 	
			IDENT LEFT_BRACKET declaration_args RIGHT_BRACKET
			;
			
function_call:
		IDENT LEFT_BRACKET RIGHT_BRACKET 
		| IDENT LEFT_BRACKET args RIGHT_BRACKET 
		;
function: 
		type functionDeclaration LEFT_FIGURE declarations operators RIGHT_FIGURE {printf("\nfunction\n");}
		;

declaration_args: 
			| type IDENT
			| declaration_args COMMA type IDENT
			;
args: /*Ïóñòîòà*/	
	 | arg
	 | args COMMA arg
	;
operators:  /*Ïóñòîòà*/
			| operator operators
	;

Code_block: LEFT_FIGURE operators RIGHT_FIGURE
		    | operator
		    | LEFT_FIGURE declarations RIGHT_FIGURE 
		    | LEFT_FIGURE declarations operators RIGHT_FIGURE 
			;
	
	
			
FOR_cycle: FOR LEFT_BRACKET statement SEMICOLON statement SEMICOLON statement RIGHT_BRACKET Code_block
		    ;
		   
		 
OUT_func: 
			OUT IDENT {printf("\nPrint Function");}
			| OUT STRING {printf("\nPrint Function");}
			;
			
IN_func:
			IN  IDENT {printf("\nScan Function");}
			;
		  
declaration: 	
			type IDENT SEMICOLON 
			| type statement SEMICOLON {printf("\ndeclaration & assignment");}
			| type IDENT LEFT_FIGURE NUMBER RIGHT_FIGURE SEMICOLON 
			| type IDENT LEFT_FIGURE RIGHT_FIGURE ASSIGNMENT STRING SEMICOLON 
			| error
			; 
			
declarations:
			/*empty*/
			| declaration declarations {printf("\nDeclarations");}
		//	| error
			;

operator: 
	statement SEMICOLON 	{printf("\nStatement");}
	| RETURN statement SEMICOLON 	{printf("\nReturn statement");}
	| error
	| FOR_cycle        	{printf("\nFOR Cycle");}
	| OUT_func SEMICOLON       		
	| IN_func SEMICOLON
	;
	
array_access:
		IDENT LEFT_FIGURE NUMBER RIGHT_FIGURE
		;

statement: 
		logical_expr	 {printf("\nlogical_expr");}
		| IDENT ASSIGNMENT statement {printf("\nlogical_expr");}
		| IDENT ASSIGNMENT function_call {printf("\nfunction call");}
		| array_access ASSIGNMENT statement
		;
		
		
logical_expr: 
			logical_or_expr	
			| logical_expr NOT_EQUAL logical_or_expr	
			| logical_expr LESS logical_or_expr
			| logical_expr MORE logical_or_expr
			| logical_expr LESS_EQUAL  logical_or_expr
			| logical_expr MORE_EQUAL logical_or_expr 
			;
			
logical_or_expr: 
			logical_and_expr	
			| logical_or_expr OR logical_and_expr
			;
			
logical_and_expr: 
			plus_expr	
			| logical_and_expr AND plus_expr
			;
			
			
plus_expr: 
			mul_expr	
			| plus_expr PLUS mul_expr
			| plus_expr MINUS mul_expr
			| plus_expr PLUS error
			| plus_expr MINUS error
			| IDENT PLUS_AND_ASSIGN mul_expr
			| IDENT MINUS_AND_ASSIGN mul_expr
			;
			
			
mul_expr: 
		unary_expr
		| mul_expr DIV unary_expr
		| mul_expr DIV error
		| mul_expr MULT unary_expr
		| mul_expr MULT error
		| IDENT DIV_AND_ASSIGN unary_expr
		| IDENT MULT_AND_ASSIGN unary_expr
		;
		
		
unary_expr:
		post_unary_expr	
		| MINUS unary_expr %prec UMINUS
		| INC unary_expr
		| DEC unary_expr
		| NOT unary_expr
		;
		
		
post_unary_expr: 
			primary	
			| primary INC {printf("\n INC");}
			| primary DEC {printf("\n DEC");}
			;

primary: 
		NUMBER 	
		| IDENT 
		| LEFT_BRACKET statement RIGHT_BRACKET
		| IDENT LEFT_BRACKET args RIGHT_BRACKET
		| array_access		
		;
		
arg: 
	statement		
	| STRING
	;
	
type: 
	INT 
	| CHAR 
	| VOID
	;
%%

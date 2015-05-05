%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "jlib.h"

#define YYDEBUG 1	
extern int lineNumber;


struct procedureInfo* MAIN_INFO;

struct treeNode* treeRoot = NULL;       // Êîðåíü äåðåâà
struct funcTableNode* FuncTable = NULL; // Ñïèñîê ôóíêöèé
struct variableListNode* curVarList = NULL; // Ñïèñîê îáúÿâëåííûõ ïåðåìåííûõ òåêóùåé ôóíêöèè
struct paramsListNode* curParamList = NULL;

int errors = 0;

// Äîáàâëåíèå óçëà â äåðåâî
struct treeNode* GetTreeNode(char nType, struct treeNode* Left, struct treeNode* Right);

// Äîáàâèòü ôóíêöèþ â ñïèñîê
struct procedureInfo* Addprocedure(char fType, char *fName, struct paramsListNode* Params);

// Ïðîâåðèòü íàëè÷èå ôóíêöèè â ñïèñêå
struct procedureInfo* Checkprocedure(char *fName);

// Äîáàâèòü ïàðàìåòð â ñïèñîê
struct paramsListNode* AddToParamsList(struct treeNode* node, struct variableInfo *pVar);

// Âåðíóòü ñòðóêòóðó ïåðåìåííîé
struct variableInfo* GetVar(char vType, char *vName, int isParam);

// Äîáàâèòü ïåðåìåííóþ â òåêóùèé ñïèñîê
struct variableListNode* AddToVariableList(struct variableInfo *Var);

// Ïðîâåðèòü, îáúÿâëåíà ëè ïåðåìåííàÿ
struct variableInfo* CheckVariable(char *vName);

struct paramsListNode* AddToArgsList(struct treeNode* node, struct paramsListNode *Next);

void ShowproceduresSemantic();

void ShowMainSemantic();


void printParameters(struct paramsListNode *params);
void printVariableDeclarations(struct variableListNode* varDeclaratons);
void printOperators(struct treeNode *operations, int depth);
void printType(int type);

%}

%union 
{
    struct treeNode* node;
	struct 
	{
		char* ptr;
		int lineNumber;
	} str;
	
	long num;
}
%defines

%token VOID INT CHAR POINTER LINK PROCEDURE OUTP INP MAIN WHILE
%token IDENT COMMA SEMICOLON STRING ASSIGNMENT NUMBER left_sqBracket right_sqBracket
%token LEFT_BRACKET RIGHT_BRACKET RIGHT_FIGURE LEFT_FIGURE comment mono_comment
%token not division minus plus compare not_equal mul_equal div_equal
%token minus_equal plus_equal inc dec more_equal less_equal more less and or quest

%start axiom
%left plus minus plus_equal minus_equal
%left division div_equal mul_equal
%left LEFT_BRACKET RIGHT_BRACKET
%left inc dec
%left uminus
%left or and not
%error-verbose

%%
axiom: 	
		procedures main_func
		| main_func
		;
		
main_func:
		type MAIN LEFT_BRACKET declaration_args RIGHT_BRACKET LEFT_FIGURE declarations operators RIGHT_FIGURE 
		{
			MAIN_INFO = (struct procedureInfo*)malloc(sizeof(struct procedureInfo));
			
			MAIN_INFO->name = "MAIN";
			MAIN_INFO->type = $<num>1;
			MAIN_INFO->params = NULL;
			MAIN_INFO->operations = $<node>8;
			MAIN_INFO->varDeclaratons = curVarList;		
			if(/*errors == 0*/  1)
			{
				// Ïå÷àòàåì èíôîðìàöèþ î ôóíêöèÿõ
				ShowproceduresSemantic();
				
				// Ïå÷àòàåì èíôîðìàöèþ î MAIN
				printf("\n\n/MAIN/: ");
				
				printf("\n/Parameters/: ");
				printParameters(curParamList);
				
				printf("\n/Variable declarations/: ");
				printVariableDeclarations(curVarList);
				
				printf("\n/Operators/: ");
				printOperators($<node>8, 0);
			}
			
		}
		;
	
procedures: 	
		procedure 
		| procedures procedure

		;
		
///*/****************************************/////////////////////////////////		

procedureDeclaration: 	
			type IDENT LEFT_BRACKET declaration_args RIGHT_BRACKET
			{
				// Äîáàâëÿåì ôóíêöèþ â ñïèñîê è âîçâðàùàåì åž ñòðóêòóðó
				struct procedureInfo* func = Addprocedure($<num>1, $<str>2.ptr, curParamList);
				curParamList = NULL;
				if(func == NULL)
				{
					printf("\nline %d: procedure %s redeclared\n", $<str>2.lineNumber, $<str>2.ptr);
					errors++;
				}
				
				$<node>$ = GetTreeNode(-1, NULL, NULL);
				$<node>$->value.func = func;
			}
			;
		
procedure: 
		procedureDeclaration LEFT_FIGURE declarations operators RIGHT_FIGURE 
		{
			if ($<node>1->value.func != NULL)
			{
				$<node>$ = $<node>1;
				
				struct procedureInfo* func = $<node>1->value.func;			
				func->operations = $<node>4;  		// Îïåðàöèè âíóòðè ôóíêöèè
				func->varDeclaratons = curVarList;	// Ñïèñîê îáúÿâëåííûõ ïåðåìåííûõ
			}			
			curVarList = NULL;  // Íà÷àëî íîâîãî ñïèñêà ïåðåìåííûõ äëÿ ñëåäóþùåé ôóíêöèè
		}
		;
		
declaration_arg:
		type IDENT
		{
			struct variableInfo* var = GetVar($<num>1, $<str>2.ptr, 1);			
			struct variableListNode* varList = AddToVariableList(var);
			
			if(varList == NULL)
			{
				printf("\nline %d: variable %s redeclared\n", $<str>2.lineNumber, $<str>2.ptr);
				errors++;
			}
			else AddToParamsList(NULL, var);

		}
		| type IDENT left_sqBracket right_sqBracket
		{
			struct variableInfo* var; 
			if($<num>1 == 0) 
				var = GetVar(3, $<str>2.ptr, 1);
			else if($<num>1 == 1) 
				var = GetVar(5, $<str>2.ptr, 1);
			
			
			struct variableListNode* varList = AddToVariableList(var);			
			if(varList == NULL)
			{
				printf("\nline %d: variable %s redeclared\n", $<str>2.lineNumber, $<str>2.ptr);
				errors++;
			}
			else AddToParamsList(NULL, var);
		}


declaration_args: 
		//Ïóñòî
		| declaration_arg	
		| declaration_arg COMMA declaration_args
		;
		
declaration: 	
			type IDENT SEMICOLON
			{
				struct variableInfo* var = GetVar($<num>1, $<str>2.ptr, 0);
				struct variableListNode* varList = AddToVariableList(var);
				if(varList == NULL)	
				{				
					printf("\nline %d: variable %s redeclared\n", $<str>2.lineNumber, $<str>2.ptr);
					errors++;
				}
			}
			| type IDENT left_sqBracket NUMBER right_sqBracket SEMICOLON
			{					
				struct variableInfo* var = GetVar(3, $<str>2.ptr, 0); // Òèï ïåðåìåííîé - ìàññèâ
				struct variableListNode* varList = AddToVariableList(var);
				if(varList == NULL)	
				{				
					printf("\nline %d: variable %s redeclared\n", $<str>2.lineNumber, $<str>2.ptr);
					errors++;
				}
				else
				{
					struct arrayInfo* array = (struct arrayInfo*)malloc(sizeof(struct arrayInfo));
					array->length = $<num>4;
					if($<num>1 == 0)				
						array->sizeOfElement = 1;	// CHAR				
					else if($<num>1 == 1)				
						array->sizeOfElement = 2;	// INT	
						
					var->value.arrayValue = array;
				}
			}
			| type IDENT left_sqBracket right_sqBracket ASSIGNMENT STRING SEMICOLON
			{
				struct variableInfo* var = GetVar(4, $<str>2.ptr, 0); // Òèï ïåðåìåííîé - ìàññèâ
				struct variableListNode* varList = AddToVariableList(var);
				if(varList == NULL)		
				{
					printf("\nline %d: variable %s redeclared\n", $<str>2.lineNumber, $<str>2.ptr);
					errors++;
				}
				else
				{
					struct arrayInfo* array = (struct arrayInfo*)malloc(sizeof(struct arrayInfo));
					array->sizeOfElement = 1;
					array->length = strlen($<str>6.ptr) + 1;
					array->ptr = $<str>6.ptr;
						
					var->value.arrayValue = array;
				}
			}
			; 
			
declarations:
			/*Ïóñòî*/
			| declaration declarations
			| error declarations
			{
				errors++;
			}
			;
		
///*/****************************************/////////////////////////////////	


args:
	/*ïóñòî*/
	{
		$<node>$ = GetTreeNode(4, NULL, NULL);
		$<node>$->value.params = NULL;
	}	
	| arg
	{			
		$<node>$ = GetTreeNode(4, NULL, NULL);
        $<node>$->value.params = AddToArgsList($<node>1, NULL);
	}
	| args COMMA arg
	{
		$<node>$ = GetTreeNode(4, NULL, NULL);
        $<node>$->value.params = AddToArgsList($<node>3, $<node>1->value.params);
	}
	;
		
arg: 
	IDENT
	{
		struct variableInfo* var = CheckVariable($<str>1.ptr);
		if(var == NULL)
		{
			printf("\nline %d: variable %s undeclared\n", $<str>1.lineNumber, $<str>1.ptr);
			$<node>$ = NULL;
			errors++;
		}
		else
		{
			$<node>$ = GetTreeNode(0, NULL, NULL);
			$<node>$->value.var = var;
		}
				
	}
	| NUMBER
	{
		struct constantInfo* constant = (struct constantInfo*)malloc(sizeof(struct constantInfo));
		constant->type = 0; // Òèï êîíñòàíòû - NUMBER
        constant->value.intValue = $<num>1;
		
		$<node>$ = GetTreeNode(1, NULL, NULL);
		$<node>$->value.constant = constant;
	}	
	| STRING
	{	
		struct arrayInfo* array = (struct arrayInfo*)malloc(sizeof(struct arrayInfo));
		array->sizeOfElement = 1;
        array->length = strlen($<str>1.ptr) + 1;
        array->ptr = $<str>1.ptr;
		
		struct constantInfo* constant = (struct constantInfo*)malloc(sizeof(struct constantInfo));
		constant->type = 1; // Òèï êîíñòàíòû - ñòðîêà
        constant->value.arrValue = array;
        
		$<node>$ = GetTreeNode(1, NULL, NULL);
		$<node>$->value.constant = constant;		
	}
	| array_access
	;
	
	
operators:  /*ïóñòîòà*/
			{
				$<node>$ = NULL;
			}

			| operator operators
			{				
				$<node>$ = GetTreeNode(3, $<node>2, $<node>1);
			}
			| error operators
			{
				errors++;
			}
			;

Code_block: LEFT_FIGURE operators RIGHT_FIGURE 
			{
				$<node>$ = $<node>2;
			}
		    | operator
			{
				$<node>$ = GetTreeNode(3, NULL, $<node>1);
			}
			;
	
	

WHILE_cycle: WHILE LEFT_BRACKET statement RIGHT_BRACKET Code_block
			{
				$<node>$ = GetTreeNode(11, $<node>3, $<node>5);	
			}
		    ;
		   
		 
OUTP_func: 
			OUTP LEFT_BRACKET arg RIGHT_BRACKET
			{				
				$<node>$ = GetTreeNode(12, NULL, $<node>3); // Òèï 12 - PRINT
				// Ïðàâàÿ âåòâü - àðãóìåíò print'à
			}
			;
			
INP_func:
			INP LEFT_BRACKET IDENT RIGHT_BRACKET
			{
				struct variableInfo* var = CheckVariable($<str>3.ptr);
				if(var == NULL)
				{
					printf("\nline %d: variable %s undeclared\n", $<str>3.lineNumber, $<str>3.ptr);
					$<node>$ = NULL;
					errors++;
				}
				else
				{
					$<node>$ = GetTreeNode(13, NULL, NULL); 
					$<node>$->value.var = var;
				}				
			}
			;		  

operator: 
	statement SEMICOLON 
	{
		$<node>$ = $<node>1;
	}
//	| error
	| WHILE_cycle        
	{
		$<node>$ = $<node>1;
	}
	| OUTP_func SEMICOLON   
	{
		$<node>$ = $<node>1;
	}
	| INP_func SEMICOLON    
	{
		$<node>$ = $<node>1;
	}
	;
	
array_access:
		IDENT left_sqBracket logical_expr right_sqBracket
		{
			struct variableInfo* var = CheckVariable($<str>1.ptr);
			if(var == NULL)
			{
				printf("\nline %d: variable %s undeclared\n", $<str>1.lineNumber, $<str>1.ptr);
				$<node>$ = NULL;
				errors++;
			}
			else
			{
				$<node>$ = GetTreeNode(44, NULL, $<node>3);
				$<node>$->value.var = var;
			}		
		}
		;

statement: 
		logical_expr	
		{
			$<node>$ = $<node>1;
		}
		| IDENT ASSIGNMENT logical_expr          // Ïðèñâàèâàíèå çíà÷åíèÿ ïåðåìåííîé
		{
			struct variableInfo* var = CheckVariable($<str>1.ptr);
			if(var == NULL)
			{
				printf("\nline %d: variable %s undeclared\n", $<str>1.lineNumber, $<str>1.ptr);
				$<node>$ = NULL;
				errors++;
			}
			else
			{
				$<node>$ = GetTreeNode(7, NULL, $<node>3);
				$<node>$->value.var = var;
			}
		}
		| array_access ASSIGNMENT logical_expr       // Ïðèñâàèâàíèå çíà÷åíèÿ ýëåìåíòó ìàññèâà
		{
			$<node>$ = GetTreeNode(8, $<node>1, $<node>3);
		}
//		| IDENT plus_equal logical_expr
//		| IDENT minus_equal logical_expr
//		| IDENT div_equal unary_expr
//		| IDENT mul_equal unary_expr
		;
		
		
logical_expr: 
			logical_or_expr	
			{
				$<node>$ = $<node>1;
			}
			| logical_expr not_equal logical_or_expr	
			{
				$<node>$ = GetTreeNode(40, $<node>1, $<node>3);
			}
			| logical_expr less logical_or_expr
			{
				$<node>$ = GetTreeNode(35, $<node>1, $<node>3);
			}
			| logical_expr more logical_or_expr
			{
				$<node>$ = GetTreeNode(36, $<node>1, $<node>3);
			}
			| logical_expr compare logical_or_expr
			{
				$<node>$ = GetTreeNode(39, $<node>1, $<node>3);
			}
			| logical_expr less_equal  logical_or_expr
			{
				$<node>$ = GetTreeNode(37, $<node>1, $<node>3);
			}
			| logical_expr more_equal logical_or_expr 
			{
				$<node>$ = GetTreeNode(38, $<node>1, $<node>3);
			}
			;
			
logical_or_expr: 
			logical_and_expr	
			{
				$<node>$ = $<node>1;
			}
			| logical_or_expr or logical_and_expr
			{
				$<node>$ = GetTreeNode(42, $<node>1, $<node>3);
			}
			;
			
logical_and_expr: 
			plus_expr	
			{
				$<node>$ = $<node>1;
			}
			| logical_and_expr and plus_expr
			{
				$<node>$ = GetTreeNode(43, $<node>1, $<node>3);
			}
			;
			
			
plus_expr: 
			mul_expr	
			{
				$<node>$ = $<node>1;
			}
			| plus_expr plus mul_expr
			{
				$<node>$ = GetTreeNode(30, $<node>1, $<node>3);
			}
			| plus_expr minus mul_expr
			{
				$<node>$ = GetTreeNode(31, $<node>1, $<node>3);
			}
			| plus_expr plus error
			{
				errors++;
			}
			| plus_expr minus error
			{
				errors++;
			}
			;
			
			
mul_expr: 
		unary_expr
		{
			$<node>$ = $<node>1;
		}
		| mul_expr division unary_expr
		{
			$<node>$ = GetTreeNode(33, $<node>1, $<node>3);
		}
		| mul_expr division error
		{
			errors++;
		}
		;
		
		
unary_expr:
//		post_unary_expr	
		primary
		{
			$<node>$ = $<node>1;
		}
		| minus unary_expr %prec uminus
		{
			$<node>$ = GetTreeNode(45, NULL, $<node>2);
		}
		| unary_expr inc
		{
			$<node>$ = GetTreeNode(46, NULL, $<node>1);
		}
		| unary_expr dec
		{
			$<node>$ = GetTreeNode(47, NULL, $<node>1);
		}
		| not unary_expr
		{
			$<node>$ = GetTreeNode(41, NULL, $<node>2);
		}
		;
		
/*		
post_unary_expr: 
			primary	
			| primary inc
			| primary dec
			;
*/

primary: 
		NUMBER 	
		{
			struct constantInfo* constant = (struct constantInfo*)malloc(sizeof(struct constantInfo));
			constant->type = 0; // Òèï êîíñòàíòû - NUMBER
			constant->value.intValue = $<num>1;
			
			$<node>$ = GetTreeNode(1, NULL, NULL);
			$<node>$->value.constant = constant;
		}
		| IDENT
		{
			struct variableInfo* var = CheckVariable($<str>1.ptr);
			if(var == NULL)
			{
				printf("\nline %d: variable %s undeclared\n", $<str>1.lineNumber, $<str>1.ptr);
				$<node>$ = NULL;
				errors++;
			}
			else
			{
				$<node>$ = GetTreeNode(0, NULL, NULL);
				$<node>$->value.var = var;
			}
		}
		| LEFT_BRACKET statement RIGHT_BRACKET
		{
			$<node>$ = $<node>2;
		}
		| IDENT LEFT_BRACKET args RIGHT_BRACKET // Âûçîâ ôóíêöèè
		{
			struct procedureInfo* func = Checkprocedure($<str>1.ptr);
			if(func == NULL)	
			{			
				printf("\nline %d: procedure %s undeclared!\n", $<str>1.lineNumber, $<str>1.ptr);
				errors++;
			}
			else
			{
				$<node>$ = GetTreeNode(14, NULL, $<node>3);
				$<node>$->value.func = func;
			}
		}
		| array_access	
		{
			$<node>$ = $<node>1;
		}
		;
		

	
type:  	INT    { $<num>$ = 0;}
		| CHAR { $<num>$ = 1;}
		| VOID { $<num>$ = 2;}
		| INT POINTER { $<num>$ = 3; }
		| CHAR POINTER { $<num>$ = 4; }
		| VOID POINTER { $<num>$ = 5; }
		| INT LINK { $<num>$ = 6; }
		| CHAR LINK { $<num>$ = 7; }
		| VOID LINK { $<num>$ = 8; }
	;
%%

struct treeNode* GetTreeNode(char nType, struct treeNode* Left, struct treeNode* Right)
{
	struct treeNode* node = (struct treeNode*)malloc(sizeof(struct treeNode));
    node->nodeType = nType;
    node->left = Left;
    node->right = Right;
    return node;
}

struct procedureInfo* Addprocedure(char fType, char *fName, struct paramsListNode* Params)
{
	// Ïðîâåðêà ïîâòîðíîãî îáúÿâëåíèÿ
	struct funcTableNode* workNode = FuncTable;
    while(workNode)
    {
        if(strcmp(fName, workNode->func->name) == 0)
			return NULL;		
        workNode = workNode->next;
    }

	struct procedureInfo* funcInfo = (struct procedureInfo*)malloc(sizeof(struct procedureInfo));	
    funcInfo->name = (char*)malloc(strlen(fName)+1);
	strcpy(funcInfo->name, fName);	
    funcInfo->type = fType;    
    funcInfo->params = Params;
	
	
	// Äîáàâëåíèå â ñïèñîê ôóíêöèé
    struct funcTableNode* funcNode = (struct funcTableNode*)malloc(sizeof(struct funcTableNode));
    funcNode->func = funcInfo;
    funcNode->next = NULL;

    workNode = FuncTable;
    if(workNode)
    {
        while(workNode->next)
            workNode = workNode->next;
			
        workNode->next = funcNode;
    }
    else
    {
        FuncTable = funcNode;
    }

    return funcInfo;
}

struct procedureInfo* Checkprocedure(char *fName)
{
	struct funcTableNode* workNode = FuncTable;
	while(workNode)
	{
		if(strcmp(workNode->func->name, fName) == 0)
			return workNode->func;
			
		workNode = workNode->next;
	}
	return NULL;
}

struct paramsListNode* AddToParamsList(struct treeNode* node, struct variableInfo *pVar)
{
    struct parameterInfo *parameter = (struct parameterInfo*)malloc(sizeof(struct parameterInfo));
    parameter->var = pVar;
	parameter->node = node;
	
    struct  paramsListNode* listNode = (struct paramsListNode*)malloc(sizeof(struct paramsListNode));
    listNode->next = NULL;
    listNode->param = parameter;	
	
	struct  paramsListNode* workNode = curParamList;
    if(workNode)
    {
        while(workNode->next)
            workNode = workNode->next;
			
        workNode->next = listNode;
    }
    else
    {
        curParamList = listNode;
    }
	return listNode;
}

// Âåðíóòü ñòðóêòóðó ïåðåìåííîé
struct variableInfo* GetVar(char vType, char *vName, int isParam)
{
    struct variableInfo* var = (struct variableInfo*)malloc(sizeof(struct variableInfo));
    var->type = vType;
	var->isParam = isParam;
	
	var->value.intValue = 0;
	var->value.charValue = 0;

    var->name = (char*)malloc(strlen(vName)+1);
    strcpy(var->name, vName);
    return var;
}

struct variableInfo* CheckVariable(char *vName)
{
	struct variableListNode* workNode = curVarList;
	while(workNode)
	{
		if(strcmp(workNode->var->name, vName) == 0)
			return workNode->var;
			
		workNode = workNode->next;
	}
	return NULL;
}

struct variableListNode* AddToVariableList(struct variableInfo *Var)
{	
	// Ïðîâåðêà íà ïîâòîð îáúÿâëåíèÿ
	struct variableListNode* workNode = curVarList;
	while(workNode)
	{
		if(strcmp(workNode->var->name, Var->name) == 0)
			return NULL;			
		workNode = workNode->next;
	}

	// Äîáàâëåíèå â ñïèñîê
    struct  variableListNode* listNode = (struct variableListNode*)malloc(sizeof(struct variableListNode));
    listNode->next = NULL;
    listNode->var = Var;
			
	workNode = curVarList;
    if(workNode)
    {
        while(workNode->next)
            workNode = workNode->next;
			
        workNode->next = listNode;
    }
    else
    {
        curVarList = listNode;
    }
	return listNode;
}

void printType(int type)
{
	if(type == 0) printf("int"); 
	else if (type == 1) printf("char"); 
	else if (type == 2) printf("void");
}

void printParameters(struct paramsListNode *params)
{
	struct  paramsListNode* workNode = params;
	while(workNode)
	{
		struct parameterInfo* parameter = workNode->param;
		
		printType(parameter->var->type);
		if(workNode->next == NULL)	printf(" %s", parameter->var->name);
		else printf(" %s, ", parameter->var->name);	
		
		workNode = workNode->next;
	}
}

void printVariableDeclarations(struct variableListNode* varDeclaratons)
{
	struct  variableListNode* workNode = varDeclaratons;
	while(workNode)
	{
		struct variableInfo* var = workNode->var;
		if(var->isParam == 0)
		{
			printType(var->type);
			if(workNode->next == NULL)	printf(" %s", var->name);
			else printf(" %s, ", var->name);
		}	
		workNode = workNode->next;
	}
}

void printSpaces(int num)
{
	int i;
	printf("\n");
	for(i = 0; i < num; i++)
		printf("   ");
}

void printLogicTree(struct treeNode *root)
{
	if(!root) return;
	if((root->nodeType < 0) || (root->nodeType > 1 && root->nodeType < 14) || (root->nodeType > 14 && root->nodeType < 30)
		|| (root->nodeType > 47)) return;	
	  
	printLogicTree(root->left);
	
	switch(root->nodeType)
	{
		case 30:
			printf("+");
			break;
		case 31:
			printf("-");
			break;
		case 32:
			printf("*");
			break;
		case 33:
			printf("/");
			break;
		case 34:
			printf("=");
			break;
		case 35:
			printf("<");
			break;
		case 36:
			printf(">");
			break;
		case 37:
			printf("<=");
			break;
		case 38:
			printf(">=");
			break;
		case 39:
			printf("==");
			break;
		case 40:
			printf("!=");
			break;
		case 41:
			printf("!");
			break;
		case 42:
			printf("||");
			break;
		case 43:
			printf("&&");
			break;
			
		case 44:  // ìàññèâ
			printf(root->value.var->name);
			printf("["); 
			printLogicTree(root->right); 
			printf("]");
			return;
		
		case 45:
			printf("-");
			printLogicTree(root->right); 
			return;
			
		case 46:			
			printLogicTree(root->right); 
			printf("++");
			return;
			
		case 47:
			printLogicTree(root->right); 
			printf("--");
			return;
			
		case 14:  // Âûçîâ ôóíêöèè
			printf("%s(..)", root->value.func->name);
			return;
			
		case 0: // Ïåðåìåííàÿ
			printf(root->value.var->name);
			break;
			
		case 1: // Êîíñòàíòà
			printf("%d", root->value.constant->value.intValue);
			break;
	}
		
	printLogicTree(root->right);
}


void printOperators(struct treeNode *operations, int depth)
{
	struct treeNode* rightNode;
	struct treeNode* workNode = operations;
	
	while(workNode)
	{
		printSpaces(depth);
		
		rightNode = workNode->right;
		if(rightNode) //printf(" %d", workNode->right->nodeType);
		{
			switch(rightNode->nodeType)
			{
				case 7:
					printf("assignment: %s = ", rightNode->value.var->name);
					printLogicTree(rightNode->right);
					break;
				
				case 8:
					printf("assignment: %s[", rightNode->left->value.var->name);
					printLogicTree(rightNode->left->right);
					printf("] = ");
					printLogicTree(rightNode->right);
					break;
					
				case 9:  // for
					printf("FOR: ");
					printLogicTree(rightNode->left); printf("; ");
					printLogicTree(rightNode->right->left); printf("; ");
					printLogicTree(rightNode->right->right);
					
					printOperators(rightNode->value.node, depth+1);						
					break;
					
				case 10: // if
					printf("IF: ");
					printLogicTree(rightNode->value.node);
					printOperators(rightNode->left, depth+1);	
					
					if(rightNode->right)
					{
						printSpaces(depth);
						printf("ELSE:");
						printOperators(rightNode->right, depth+1);
					}
					break;
					
				case 11: // while
					printf("WHILE: ");
					printLogicTree(rightNode->left);
					printOperators(rightNode->right, depth+1);
					break;
					
				case 12: // print
					printf("PRINT: ");
					if(rightNode->right->nodeType == 0)
						printf(rightNode->right->value.var->name);
					else if(rightNode->right->nodeType == 1)
					{
						if(rightNode->right->value.constant->type == 0)
							printf("%d", rightNode->right->value.constant->value.intValue);
						else if(rightNode->right->value.constant->type == 1)
							printf(rightNode->right->value.constant->value.arrValue->ptr);
					}					
					break;
				
				case 13: // scan	
					printf("SCAN: ");
					printf(rightNode->value.var->name);					
					break;
					
				case 14: // procedure call
					printf("%s(..)", rightNode->value.func->name);					
					break;
					
				case 15: // return
					printf("RETURN ");
					printLogicTree(rightNode->right);
					break;
					
				default:
					printLogicTree(rightNode);
			}
		}
	
		
		
		//----------------------------------------------------
		workNode = workNode->left;
	}
}

void ShowproceduresSemantic()
{
	struct funcTableNode* workNode = FuncTable;
	while(workNode)
	{
		struct procedureInfo* func = workNode->func;
		//--------------------------------------
		printf("\n\n/procedure/: ");
		printType(func->type);
		printf(" %s", func->name);
		
		printf("\n/Parameters/: ");
		printParameters(func->params);
		
		printf("\n/Variable declarations/: ");
		printVariableDeclarations(func->varDeclaratons);
		
		printf("\n/Operators/: ");
		printOperators(func->operations, 0);
		
		//--------------------------------------	
		workNode = workNode->next;
		printf("\n---------------------------------------");
	}
}


struct paramsListNode* AddToArgsList(struct treeNode* node, struct paramsListNode *Next)
{
    struct parameterInfo *parameter = (struct parameterInfo*)malloc(sizeof(struct parameterInfo));
    parameter->var = NULL;
	parameter->node = node;
	
    struct  paramsListNode* listNode = (struct paramsListNode*)malloc(sizeof(struct paramsListNode));
    listNode->next = Next;
    listNode->param = parameter;
    return listNode;
}


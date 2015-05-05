#include "jlang.tab.c"
#include "lex.yy.c"
#include "stdbool.h"
#include "jlib.h"

void executeCode();

int main (int argc, char** argv)
{
	++argv, --argc;
	if (argc > 0)
		yyin = fopen( argv[0], "r" );
	else
		yyin = stdin;
		
	yyout = fopen("output.txt", "w");	
	
	yyparse();	

	executeCode();

	return 0;
}

void printConstant(struct constantInfo *constant)
{
	char* str;
	int i;
	switch(constant->type)
	{
		case 0: 
			printf("%d \n\n", constant->value.intValue);
			break;
		case 1:
			str = constant->value.arrValue->ptr;
			for(i = 1; i < (constant->value.arrValue->length)-2; i++)
				printf("%c", str[i]);
			printf("\n\n");
			break;
	}

}

void printVar(struct variableInfo* var)
{
	char* str;
	int i;
	switch(var->type)
	{
		case 0: 
			printf("%d \n\n", var->value.intValue);
			break;
		case 1:
			printf("%c \n\n", var->value.charValue);
			break;
		case 4:
			str = var->value.arrayValue->ptr;
			for(i = 0; i < (var->value.arrayValue->length)-1; i++)
				printf("%c", str[i]);
			printf("\n\n");
			break;
		default: break;
	}

}

void print(struct treeNode* node)
{
	switch(node->nodeType)
	{ 
		case 0:
			printVar(node->value.var);
			break;
		case 1:
			printConstant(node->value.constant);
			break;
		//printArray(node->)
		default: break;
	}

}

void scan(struct treeNode* node)
{
	struct arrayInfo* array = node->value.var->value.arrayValue;
	array->sizeOfElement = 1;
	array->ptr = (char*)malloc(100);
	scanf("%s", array->ptr );
	array->length = strlen(array->ptr ) + 1;
}

void sendParams(struct procedureInfo* func, struct paramsListNode *params)
{
	struct paramsListNode* sendedPar = params;
	struct paramsListNode* funcPar = func->params;
	while(funcPar && sendedPar)
	{
		switch(funcPar->param->var->type)
		{
			case 0:
				funcPar->param->var->value.intValue = sendedPar->param->node->value.constant->value.intValue;
				break;
			case 1:
				funcPar->param->var->value.charValue = sendedPar->param->node->value.constant->value.charValue;
				break;
			case 4:
				funcPar->param->var->value.arrayValue = sendedPar->param->node->value.constant->value.arrValue;
				break;
			default: break;
		}
		funcPar = funcPar->next;
		sendedPar = sendedPar->next;
	}
}

int logicalOper(struct treeNode *node)
{
	int first = 0; 
	int second = 0;
	switch(node->left->nodeType)
	{
		case 0:
			first = node->left->value.var->value.intValue;
			break;
		case 1:
			first = node->left->value.constant->value.intValue;
			break;
	}

	switch(node->right->nodeType)
	{
		case 0:
			second = node->right->value.var->value.intValue;
			break;
		case 1:
			second = node->right->value.constant->value.intValue;
			break;
	}
	switch(node->nodeType)
	{
		case 30:
			return first+second;
		case 31:
			return first-second;
		case 46:
			return first++;
		case 47:
			return first--;
	}

}

void assign(struct treeNode *node)
{
	switch(node->right->nodeType)
	{
		case 0:
			node->value.var->value.intValue = node->right->value.var->value.intValue;
			break;
		case 1:
			node->value.var->value.intValue = node->right->value.constant->value.intValue;
			break;
		default:
			node->value.var->value.intValue = logicalOper(node->right);
			break;
	}
}


bool checkLogic(struct treeNode *node)
{
	int first = 0; 
	int second = 0;
	switch(node->left->nodeType)
	{
		case 0:
			first = node->left->value.var->value.intValue;
			break;
		case 1:
			first = node->left->value.constant->value.intValue;
			break;
	}

	switch(node->right->nodeType)
	{
		case 0:
			second = node->right->value.var->value.intValue;
			break;
		case 1:
			second = node->right->value.constant->value.intValue;
			break;
	}
	switch(node->nodeType)
	{
		case 35:
			return first<second;
		case 36:
			return first>second;
		case 37:
			return first<=second;
		case 38:
			return first>=second;
		case 39:
			return first==second;
		case 40:
			return first!=second;
	}
}


void doOperations(struct treeNode *workNode)
{
	struct treeNode *right = workNode->right;
	if(right)
	{
		fflush(stdin);
		switch(right->nodeType)
		{
			case 7:
				assign(right);
				break;
			case 11:
				while(checkLogic(right->left))
				{
					printf("ENTERING TO WHILE CYCLE\n");
					doOperations(right->right);
					printf("RETURNING FROM WHILE CYCLE\n");
				}
				break;
			case 12: 
				print(right->right);
				break;
			case 13:
				scan(right);
				break;
			case 14:
				printf("ENTERING TO PROC: %s\n", right->value.func->name );
				if(right->right->value.params)
					sendParams(right->value.func, right->right->value.params);
				doOperations(right->value.func->operations);
				printf("RETURN FROM PROC: %s\n", right->value.func->name );
				break;
			default: break;
		}
	} 

	if(workNode->left)
		doOperations(workNode->left);
}

void executeCode()
{
	struct funcTableNode* funcNode = FuncTable;
	struct procedureInfo* workNode = MAIN_INFO;
	while (workNode)
	{
		printf("%s\n", workNode->name);
		printf("Type: %d\n", workNode->type);
		printf("Operations: %d\n", workNode->operations);
		printf("Declarations: %d \n", workNode->varDeclaratons);
		break;
	}

	doOperations(workNode->operations);

	return;

}

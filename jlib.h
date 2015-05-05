#ifndef __LAB4_LIB_H
#define __LAB4_LIB_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct treeNode
{
	int nodeType;          // Òèï óçëà äåðåâà / ñåìàíòè÷åñêîãî çíà÷åíèÿ
	union
	{
		struct treeNode *node;
		struct variableInfo* var;
		struct constantInfo *constant;
		struct procedureInfo* func;    			
		struct paramsListNode* params;
	} value;
	struct treeNode *left;
	struct treeNode *right;
};


//--------------------------------------------------
struct procedureInfo
{
    char *name;
    char type;
    struct paramsListNode *params;
    struct treeNode *operations;
	struct variableListNode* varDeclaratons;
};

struct funcTableNode
{
    struct procedureInfo *func;
    struct funcTableNode *next;
};
//----------------------------------------------------

struct parameterInfo
{
    char* name;
    char type;
    struct variableInfo* var;
	struct treeNode* node;
};

struct paramsListNode
{
    struct parameterInfo* param;
    struct paramsListNode* next;
};
//---------------------------------------------------

struct arrayInfo
{
    int sizeOfElement;
    int length;
    char *ptr;
};

struct constantInfo
{
    char type;
    union
    {
        int intValue;
        char charValue;
        struct arrayInfo* arrValue;
    } value;
};

//-------------------------------------------------
struct variableInfo
{
    int isParam;
    char* name;
    char type;
    union
    {
        int intValue;
        char charValue;
        struct arrayInfo* arrayValue;
    } value;
};

struct variableListNode
{
    struct variableInfo *var;
    struct variableListNode *next;
};

extern struct treeNode* treeRoot;       // Êîðåíü äåðåâà
extern struct funcTableNode* FuncTable; // Ñïèñîê ôóíêöèé
extern struct variableListNode* curVarList; // Ñïèñîê îáúÿâëåííûõ ïåðåìåííûõ òåêóùåé ôóíêöèè
extern struct paramsListNode* curParamList;
extern struct procedureInfo* MAIN_INFO;

extern int errors;


#endif

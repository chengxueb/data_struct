#include <stdio.h>
#include <stdlib.h>

#ifndef MAX_LENGTH
#define MAX_LENGTH 5 
#endif

typedef struct SqList SqList;
typedef int INT;

struct SqList
{
	INT *val;
	int max_len;
	int size;
};

SqList * initSqList()
{
	SqList *list = (SqList *) malloc(sizeof(SqList));
	list->val = (INT *) malloc(MAX_LENGTH * sizeof(INT));
	list->max_len = MAX_LENGTH;
	list->size = 0;
	return list;
}

SqList * insertSqList(SqList *list, INT i)
{
	if (list->size == list->max_len)
	{
		INT *newbase = (INT *)	realloc(list->val, 2 * list->max_len * sizeof(INT));
		list->val = newbase;
	}

	list->val[list->size] = i;
	list->size = list->size + 1;	
	list->max_len = 2 * list->max_len;

	return list;	
}

void printSqList(SqList *list)
{
	int i = 0;
	for (; i < list->size; i++)
	{
		printf("i = %d, val = %d\n", i, list->val[i]);
	}
}

int main()
{
	SqList *list = initSqList();
	list = insertSqList(list, 100);
	list = insertSqList(list, 101);
	list = insertSqList(list, 99);
	list = insertSqList(list, 98);
	list = insertSqList(list, 97);
	list = insertSqList(list, 1000);
	printSqList(list);
	free(list->val);
	free(list);
}

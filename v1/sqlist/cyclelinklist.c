/**
 *	循环链表相关实现
 */

#include <stdio.h>
#include <stdlib.h>

#define TRUE 0
#define FALSE -1

typedef short int Bool;
typedef struct CycleLinkListNode CycleLinkListNode;
typedef struct HeadList HeadList;
typedef struct Data Data;

struct Data
{
	void *val;
};

struct CycleLinkListNode
{
	const Data *data;
	CycleLinkListNode *next;
};

struct HeadList
{
	CycleLinkListNode *head;
	int len;
};

HeadList * init_cycle_link_list()
{
	HeadList *list = (HeadList *) malloc(sizeof(HeadList));
	list->head = NULL;
	list->len = 0;

	return list;
}

Bool insert_cycle_link_list(HeadList *headList, Data const *data, int index)
{
	if (headList == NULL)
	{
		return FALSE;
	}

	if (data == NULL)
	{
		return FALSE;
	}

	CycleLinkListNode *node = (CycleLinkListNode *) malloc(sizeof(CycleLinkListNode));
	node->data  = data;
	
	if (headList->len == 0)
	{
		headList->head = node;
		node->next = headList->head;

		headList->len++;
		return TRUE;
	}

	if (headList->len == 1)
	{
		if (index == 0)
		{
			node->next = headList->head->next;
			headList->head->next = node;
			headList->head = node;
		}
		else
		{
			headList->head->next->next = node;
			node->next = headList->head;	
		}

		headList->len++;
		return TRUE;
	}

	CycleLinkListNode *p = headList->head;
	//插入循环链表尾部
	if (index >= headList->len)
	{
		while (p->next != headList->head)		
		{
			p = p->next;
		}
		p->next = node;
		node->next = headList->head;

		headList->len++;
		return TRUE;
	}

	//插入循环链表头部
	if (index == 0)
	{
		node->next = headList->head;		

		while (p->next != headList->head)		
		{
			p = p->next;
		}
		p->next = node;
		headList->head = node;

		headList->len++;
		return TRUE;
	}

	//插入循环链表中部
	int i = 0;
	while (p->next != headList->head && i < index - 1)
	{
		p = p->next;
		i++;
	}

	node->next = p->next;
	p->next = node;
	return TRUE;
}

void print_cycle_link_list(HeadList *headList)
{
	if (headList == NULL || headList->len == 0)
	{
		return;
	}

	if (headList->len == 1)
	{
		printf("%s\n", headList->head->data->val);
		return;
	}

	CycleLinkListNode *p = headList->head;
	while (p->next != headList->head)
	{
		printf("%s\n", p->data->val);
		p = p->next;
	}
	printf("%s\n", p->data->val);
}

int main()
{
	Data *d1 = (Data *) malloc(sizeof(Data));
	Data *d2 = (Data *) malloc(sizeof(Data));
	Data *d3 = (Data *) malloc(sizeof(Data));
	Data *d4 = (Data *) malloc(sizeof(Data));
	d1->val = "java程序开发";
	d2->val = "php30天精通";
	d3->val = "hadoop开发实战";
	d4->val = "Maven权威指南";

	HeadList *headList = init_cycle_link_list();
	Bool res;

	res = insert_cycle_link_list(headList, d1, 1);
	if (res == TRUE)
	{
		printf("写入循环链表成功\n");
	}

	res = insert_cycle_link_list(headList, d2, 2);
	if (res == TRUE)
	{
		printf("写入循环链表成功\n");
	}

	res = insert_cycle_link_list(headList, d3, 0);
	if (res == TRUE)
	{
		printf("写入循环链表成功\n");
	}

	res = insert_cycle_link_list(headList, d4, 0);
	if (res == TRUE)
	{
		printf("写入循环链表成功\n");
	}

	printf("len = %d\n", headList->len);
	print_cycle_link_list(headList);
}

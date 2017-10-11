#include <stdio.h>
#include <stdlib.h>

#define FALSE -1
#define TRUE 0
typedef short int Bool;

typedef struct LinkList LinkList;
typedef struct ListNode ListNode;
typedef struct Data Data;

struct Data
{
	void *val;
};

struct ListNode 
{
	Data *data;
	ListNode *next;
};

struct LinkList 
{
	ListNode *head;
	int len;
};

LinkList * init_link_list()
{
	LinkList *list = (LinkList *) malloc(sizeof(LinkList));
	list->len = 0;
	return list;
}

Bool insert_link_list(LinkList *list, Data *data, int index)
{
	if (list == NULL)
	{
		return FALSE;
	}

	if (index > list->len + 1)
	{
		return FALSE;
	}

	//头部为空, 直接放节点放在头部
	if (list->head == NULL)
	{
		ListNode *node = (ListNode *) malloc(sizeof(ListNode));
		node->data = data;
		list->head = node;
		list->len++;
		return TRUE;
	}

	ListNode *p = list->head;
	int i = 0;
	while (p->next != NULL && i < index - 1)
	{
		p = p->next;
		i++;
	}

	ListNode *node = (ListNode *) malloc(sizeof(ListNode));
	node->data = data;

	if (p->next != NULL)
	{
		node->next = p->next;
		p->next = node;
	}
	else
	{
		p->next = node;
	}

	list->len++;

	return TRUE;
}

void print_link_list(LinkList *list)
{
	if (list->len == 0)
	{
		printf("链表为空");
		return;
	}

	ListNode *p = list->head;
   	int i = 0;
	while (p != NULL && i < list->len)
	{
		printf("index = %d, val = %s\n", i + 1, p->data->val);
		i++;
		p = p->next;
	}
}

int main()
{
	Data *data1 = (Data *) malloc(sizeof(Data));
	data1->val = "hello, world1";

	LinkList *list = init_link_list();
	Bool res = insert_link_list(list, data1, 1);
	if (res == TRUE)
	{
		printf("写入链表成功\n");
	}

	Data *data2 = (Data *) malloc(sizeof(Data));
	data2->val = "hello, world2";
	res = insert_link_list(list, data2, 2);
	if (res == TRUE)
	{
		printf("写入链表成功\n");
	}

	Data *data3 = (Data *) malloc(sizeof(Data));
	data3->val = "hello, world3";
	res = insert_link_list(list, data3, 3);
	if (res == TRUE)
	{
		printf("写入链表成功\n");
	}

	Data *data4 = (Data *) malloc(sizeof(Data));
	data4->val = "hello, world4";
	res = insert_link_list(list, data4, 2);
	if (res == TRUE)
	{
		printf("写入链表成功\n");
	}

	print_link_list(list);
	printf("%d\n", list->len);

	free(list);
	free(data1);
	free(data2);
	free(data3);
}

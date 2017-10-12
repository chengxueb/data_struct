#include <stdio.h>
#include <stdlib.h>

#define TYPE_INT 0
#define TYPE_STRING 1

#define FALSE -1
#define TRUE 0

typedef short int Bool;
typedef struct QueneNode QueneNode;
typedef struct Quene Quene;
typedef struct Data Data;

struct QueneNode
{
	Data *data;
	QueneNode *next;
};

struct Quene
{
	QueneNode *head;
	QueneNode *tail;
};

struct Data
{
	void *val;
	int type;
};

Bool is_empty(Quene *q)
{
	return q->head == NULL ? TRUE : FALSE;
}

Quene * init_quene()
{
	Quene *q = (Quene *) malloc(sizeof(Quene));
	q->head = NULL;
	q->tail = NULL;

	return q;
}

Bool in_quene(Quene *q, Data *d)
{
	QueneNode *new_node = (QueneNode *) malloc(sizeof(QueneNode));

	if (new_node == NULL)
	{
		return FALSE;
	}

	new_node->data = d;

	if (q->head == NULL)
	{
		q->head = new_node;
		q->tail = new_node;
	}
	else
	{
		q->tail->next = new_node;
		q->tail = new_node;
	}

	return TRUE;
}

Data * out_quene(Quene *q)
{
	Data *d = (Data *) malloc(sizeof(Data));
	QueneNode *node;

	node = q->head;
	d->val = q->head->data->val;	
	d->type = q->head->data->type;

	q->head = q->head->next;
	if (q->head == NULL)
	{
		q->tail = NULL;
	}

	free(node);
	return d;
}

void destory_quene(Quene *q)
{
	while (is_empty(q) != TRUE)
	{
		out_quene(q);
	}

	q = NULL;
	free(q);
}

int main()
{
	Data *d1 = (Data *) malloc(sizeof(Data));
	d1->type = TYPE_STRING;
	d1->val = "hello100";
	Data *d2 = (Data *) malloc(sizeof(Data));
	d2->type = TYPE_STRING;
	d2->val = "hello200";
	Data *d3 = (Data *) malloc(sizeof(Data));
	d3->type = TYPE_STRING;
	d3->val = "hello300";
	Data *d4 = (Data *) malloc(sizeof(Data));
	d4->type = TYPE_STRING;
	d4->val = "hello400";
	Data *d5 = (Data *) malloc(sizeof(Data));
	d5->type = TYPE_STRING;
	d5->val = "hello500";

	Quene *q = init_quene();
	if (in_quene(q, d1) == TRUE)
	{
		printf("入队成功\n");
	}

	if (in_quene(q, d2) == TRUE)
	{
		printf("入队成功\n");
	}

	if (in_quene(q, d3) == TRUE)
	{
		printf("入队成功\n");
	}

	if (in_quene(q, d4) == TRUE)
	{
		printf("入队成功\n");
	}

	if (in_quene(q, d5) == TRUE)
	{
		printf("入队成功\n");
	}

	Data *d;
	while (is_empty(q) != TRUE)
	{
		d = out_quene(q);
		if (d != NULL && d->type == TYPE_STRING)
		{
			printf("%s\n", d->val);
		}
	}

	destory_quene(q);
	free(d);
	free(d1);
	free(d2);
	free(d3);
	free(d4);
	free(d5);
}

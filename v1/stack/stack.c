#include <stdio.h>
#include <stdlib.h>

#define TRUE 0
#define FALSE 1

#define TYPE_INT 0
#define TYPE_STRING 1

#define INIT_SIZE 3

typedef short int Bool;
typedef struct Data Data;
typedef struct Stack Stack;

struct Data
{
	void *val;
	int type;
};

struct Stack
{
	Data *base;
	Data *top;
	int size;	
};

Stack * init_stack()
{
	Stack *s = (Stack *) malloc(sizeof(Stack));
	s->base = (Data *) malloc(INIT_SIZE * sizeof(Data));
	s->top = s->base;
	s->size = INIT_SIZE;

	return s;
}

Bool push(Stack *s, Data *data)
{	
	if (s->top - s->base >= s->size)	
	{
		s->base = (Data *) realloc(s->base, 2 * s->size * sizeof(Data));
		s->size = 2 * s->size;
	}

    s->top->type = data->type;
    s->top->val = data->val;
	s->top++;
	return TRUE;
}

Bool pop(Stack *s, Data *data)
{
	if (s->top == s->base)
	{
		return FALSE;
	}

	s->top--;
	data->val = s->top->val;
	data->type = s->top->type;
	return TRUE;
}

int main()
{
	Data *d1 = (Data *) malloc(sizeof(Data));
	d1->val = "HELLO, WORLD1";
	d1->type = TYPE_STRING;

	Data *d2 = (Data *) malloc(sizeof(Data));
	d2->val = "HELLO, WORLD2";
	d2->type = TYPE_STRING;

	Data *d3 = (Data *) malloc(sizeof(Data));
	int i = 3;
	int *p = &i;
	d3->val = p;
	d3->type = TYPE_INT;
	
	Data *d4 = (Data *) malloc(sizeof(Data));
	d4->val = "我是d4";
	d4->type = TYPE_STRING;

	Data *d5 = (Data *) malloc(sizeof(Data));
	d5->val = "我是d5";
	d5->type = TYPE_STRING;
	
	Stack *stack = init_stack();
			
	if (push(stack, d1) == TRUE)
	{
		printf("压栈成功\n");
	}

	if (push(stack, d2) == TRUE)
	{
		printf("压栈成功\n");
	}

	if (push(stack, d3) == TRUE)
	{
		printf("压栈成功\n");
	}

	push(stack, d4);
	push(stack, d5);

	/*
	int k;
	for (k = 0; k < 5; k++)
	{
		printf("%d\n", (stack->base++)->type);
	}
	return;
	*/

	Data *topData = (Data *) malloc(sizeof(Data));
	int j = 0;
	for (; j < 5; j++)
	{
			Bool res = pop(stack, topData);
			if (res == TRUE)
			{
				printf("出栈成功\n");
				switch (topData->type)
				{
					case TYPE_STRING:
						printf("字符串: %s\n", topData->val);
						break;
					case TYPE_INT:
						printf("整数: %d\n", * (int *) topData->val);
						break;
				}
			}
	}
}

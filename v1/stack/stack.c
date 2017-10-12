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

Bool is_empty(Stack *s)
{
	if (s->top == s->base)
	{
		return TRUE;
	}

	return FALSE;
}

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
	if (data == NULL)
	{
		return FALSE;
	}

	if (s->top - s->base >= s->size)	
	{
		s->base = (Data *) realloc(s->base, 2 * s->size * sizeof(Data));
		s->top = s->base + s->size;
		s->size = 2 * s->size;
	}

    s->top->type = data->type;
    s->top->val = data->val;
	s->top++;
	return TRUE;
}

Bool pop(Stack *s, Data *data)
{
	if (data == NULL)
	{
		return FALSE;
	}

	if (is_empty(s) == TRUE)
	{
		return FALSE;
	}

	s->top--;
	if (s->top == NULL)
	{
		return FALSE;	
	}

	data->val = s->top->val;
	data->type = s->top->type;
	return TRUE;
}

int main()
{
	int N = 1348;
	Stack *s = init_stack();
	int v_val[10];
	int index = 0;

	while (N != 0)
	{
		v_val[index] = N % 8;
		N = N / 8;
		index++;
	}

	for (index = 0; index < 4; index++)
	{
		int *p = &v_val[index];

		Data *v = (Data *) malloc(sizeof(Data));
		v->type = TYPE_INT;
		v->val = p;
		push(s, v);
	}

	Data *d = (Data *) malloc(sizeof(Data));
	while (is_empty(s) != TRUE)
	//int i;
	//for (i = 0; i < 4; i++)
	{
		if (pop(s, d) == FALSE)	
		{
			printf("失败\n");
			return;	
		}

		if (d->val != NULL)
		{
			int *k = (int *)d->val;
			printf("%d", *k);
		}
	}

	printf("\n栈空\n");
}

/*
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

	int k;
	for (k = 0; k < 5; k++)
	{
		printf("%d\n", (stack->base++)->type);
	}
	return;

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
*/

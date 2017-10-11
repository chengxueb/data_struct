#include <stdio.h>
#include <stdlib.h>

typedef struct Data
{
	int val;
} Data;

int main()
{
	Data *p = (Data *) malloc(10 * sizeof(Data));
	Data *i;
	i = p;

	int j =  0;
	for (; j < 10; j++)
	{
		i->val = j;
		i++;
	}

	for (j = 0; j < 10; j++)
	{
		printf("%d\n", p->val);
		p++;
	}
}

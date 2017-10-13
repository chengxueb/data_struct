#include <stdio.h>
#include <stdlib.h>

#define FALSE -1 
#define TRUE 0

typedef struct BiTree BiTree;
typedef short int Bool;

struct BiTree
{
	int data;
	int node_num;
	BiTree *left;
	BiTree *right;
};

Bool is_exist_bitree_node(BiTree *b, int val)
{
	if (b == NULL)
	{
		return FALSE;
	}

	while (b != NULL)
	{
		if (val > b->data)
		{
			b = b->right;
		}
		else if (val < b->data)
		{
			b = b->left;
		}
		else
		{
			return TRUE;
		}
	}

	return FALSE;
}

void insert_node(BiTree **b, int val)
{
	BiTree *node = NULL;
	if (*b == NULL)
	{
		node = (BiTree *) malloc(sizeof(BiTree));
		node->data = val;
		node->left = NULL;
		node->right = NULL;
		*b = node;
		return;
	}

	if (val > (*b)->data)
	{
		insert_node(&(*b)->right, val);
	}
	else if (val < (*b)->data)
	{
		insert_node(&(*b)->left, val);
	}
}

void insert(BiTree **b, int val)
{
	if (is_exist_bitree_node(*b, val) == TRUE)	
	{
		return;
	}

	insert_node(b, val);
	(*b)->node_num++;
}

void destory_bitree(BiTree *b)
{
	if (b != NULL)
	{
		destory_bitree(b->left);	
		destory_bitree(b->right);	
		b->node_num--;
		free(b);
	}
}

void print_bitree(BiTree *b)
{
	if (b != NULL)
	{
		//printf("遍历结点数: %d\n", b->node_num);
		printf("%d\n", b->data);
		print_bitree(b->left);
		//printf("%d\n", b->data);
		print_bitree(b->right);
		//printf("%d\n", b->data);
	}
}

int main()
{
	BiTree *b = NULL;
	insert(&b, 100);
	insert(&b, 200);
	insert(&b, 300);
	insert(&b, 400);
	insert(&b, 500);
	insert(&b, 250);
	insert(&b, 250);

	printf("结点数: %d\n", b->node_num);
	print_bitree(b);
	destory_bitree(b);
}

#include "SortedLinkedList.h"
#include "Tree.h"
#include <stdio.h>
#include <stdlib.h>

void add2List(NODE **pphead, struct elem * root)
{
	while (*pphead)
	{
		if (root->value < (*pphead)->root->value)
			break;
		else
			pphead = &((*pphead)->next);
	}
	NODE * pnew = (NODE*)malloc(sizeof(NODE));
	pnew->next = *pphead;
	pnew->root = root;
	*pphead = pnew;
}

void print(NODE *phead)
{
	while (phead)
	{
		in(phead->root);
		printf("\n");
		phead = phead->next;
	}
}

NODE * deleteElem(NODE *phead)
{
	NODE * new_head = phead->next;
	free(phead);
	return new_head;
}

void deleteList(NODE *phead)
{
	if (phead)
	{
		deleteList(phead->next);
		if (phead)
			free(phead);
	}
}


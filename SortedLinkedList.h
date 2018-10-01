#pragma once

typedef struct node
{
	struct elem * root;
	struct node * next;

}NODE;

void add2List(NODE **pph, struct elem * root);
void print(NODE *phead);
NODE * deleteElem(NODE *phead);
void deleteList(NODE *phead);




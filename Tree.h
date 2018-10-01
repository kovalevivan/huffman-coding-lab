#pragma once

typedef struct elem
{
	int value;
	char letter;
	struct elem* left;
	struct elem* right;

}ELEM;

ELEM * add2tree(ELEM * root, int a, char let);
ELEM * add(ELEM * left, ELEM * right);
void in(ELEM * root);
void defineCode2(ELEM *root, char * number, struct table ** table);
void deleteTree(ELEM * root);

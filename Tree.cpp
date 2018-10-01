#define _CRT_SECURE_NO_WARNINGS
#include "Tree.h"
#include "Table.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ELEM * add2tree(ELEM * root, int a, char let)
{
	if (!root)
	{
		ELEM * pnew = (ELEM*)malloc(sizeof(ELEM));
		pnew->value = a;
		pnew->letter = let;
		pnew->right = 0;
		pnew->left = 0;
		root = pnew;
	}
	else if (root->value < a)
		root->right = add2tree(root->right, a, let);
	else
		root->left = add2tree(root->left, a, let);
	return root;
}

ELEM * add(ELEM * left, ELEM * right)
{
	ELEM * pnew = (ELEM*)malloc(sizeof(ELEM));
	pnew->value = right->value + left->value;
	pnew->letter = '\0';
	pnew->right = right;
	pnew->left = left;
	return pnew;
}

//

void in(ELEM * root)
{
	if (root)
	{
		in(root->left);
		printf("%d%c ", root->value, root->letter);
		in(root->right);
	}
}


void defineCode2(ELEM *root, char * number, struct table ** table)
{
	char tmp[50] = { '0' };
	strcpy(tmp, number);

	if (root->left)
	{	
		char null[2] = { '0', '\0' };
		strcat(tmp, null);
		defineCode2(root->left, tmp, table);
	}

	if (root->right)
	{	
		tmp[strlen(tmp) - 1] = '\0';
		char one[2] = { '1', '\0' };
		strcat(tmp, one);
		defineCode2(root->right, tmp, table);
	}
	
	if (root->letter)
	{
		add2table(table, root->letter, tmp, root->value);
	}
}

void deleteTree(ELEM * root)
{

		if (root == NULL) return;

		deleteTree(root->left);
		deleteTree(root->right);

		free(root);

}
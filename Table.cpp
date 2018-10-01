#define _CRT_SECURE_NO_WARNINGS
#include "Table.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


void add2table(TABLE **pph, char letter, char * code, int frequency)
{
	while (*pph)
	{
		if ( frequency > (*pph)->frequency)
			break;
		else
			pph = &((*pph)->next);
	}
	TABLE * pnew = (TABLE*)malloc(sizeof(TABLE));
	char * string1 = (char*)malloc((strlen(code)+1) * sizeof(char));
	strcpy(string1, code);
	pnew->next = *pph;
	pnew->letter = letter;
	pnew->code = string1;
	pnew->frequency = frequency;
	*pph = pnew;
}

void prinTable(TABLE *phead)
{
	while (phead)
	{
		printf("let = %c freq = %d code = %s\n", phead->letter, phead->frequency, phead->code);
		phead = phead->next;
	}
}

TABLE * isExist(TABLE * phead, char letter)
{
	while (phead)
	{
		if (phead->letter == letter)
			return phead;
		phead = phead->next;
	}

	return 0;
}

void deleteTable(TABLE * phead)
{
	if (phead)
	{
		deleteTable(phead->next);
		if (phead)
			free(phead);
	}
}
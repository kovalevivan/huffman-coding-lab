#pragma once

typedef struct table
{
	char letter;
	char * code;
	int frequency;
	struct table * next;

}TABLE;

void add2table(TABLE **pph, char letter, char * code, int frequency);
void prinTable(TABLE *phead);
TABLE * isExist(TABLE * table, char letter);
void deleteTable(TABLE * table);



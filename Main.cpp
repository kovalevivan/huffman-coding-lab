#define _CRT_SECURE_NO_WARNINGS
#include "Table.h"
#include "SortedLinkedList.h"
#include "Tree.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>


int main()
{
	//parsing the input file and determining the amount of use of each character

	FILE * read = fopen("text.txt", "r");
	TABLE * table = 0;
	add2table(&table, '\0', "0", 0);

		while (!feof(read))
		{
			TABLE * ptable = table;
			char letter;
			fscanf(read, "%c", &letter);
			if (ptable = isExist(table, letter))
			{
				ptable->frequency++;
			}
			else
			{
				add2table(&table, letter, "0", 1);
			}
		}

	//preparing for algorithm starting point
	//adding each character from the previous table to sorted linked list wich consist of single roots

	struct table * ptable = table;
	NODE * list = 0;
	while (ptable->next)
	{
		ELEM * root = 0;
		root = add2tree(root, ptable->frequency, ptable->letter);
		add2List(&list, root);
		ptable = ptable->next;
	}

	deleteTable(table);

	// making tree from the previous list using Hoffman's algorithm

	while (list->next != 0)
	{
		ELEM * left = list->root;
		list = deleteElem(list);
		ELEM * right = list->root;
		list = deleteElem(list);
		ELEM * new_root = add(left, right);
		add2List(&list, new_root);
	}

	//define code for each simbol

	TABLE * tab = 0;
	char tmp_string[100] = { '\0' };
	defineCode2(list->root, tmp_string, &tab);
	prinTable(tab);

	deleteTree(list->root);
	deleteList(list);

	//define input file's lenght

	fseek(read, 0, 2);
	unsigned long int size = ftell(read);
	fseek(read, 0, SEEK_SET);

	//read input file and load it to massive of char

	unsigned char * buffer = (char*)malloc(sizeof(char)*size);
	fread(buffer, 1, size, read);

	//convert this massive to binar format
	//each character is replaced by a previously defined code

	char * binar = (char*)malloc(sizeof(char)*size * 15);
	binar[0] = '\0';
	for (int i = 0; i < size; i++)
	{
		TABLE * ptable = tab;
		while (ptable)
		{
			if (ptable->letter == buffer[i])
				break;
			ptable = ptable->next;
		}
		if (ptable)
		{
			strcat(binar, ptable->code);
		}
	}



	free(buffer);

	// adding exta '0' symbols to made total number of characters divisible by 8 and adding 8 zeros to the end of the file

	while (strlen(binar) % 8 != 0)
	{
		char null[] = "0";
		strcat(binar, null);
	}
	char null[] = "00000000";
	strcat(binar, null);

	printf("\nsize of binar = %d and %d\n", strlen(binar)/8, strlen(binar)%8);

	//write the resulting array in an output file
	FILE * write = fopen("compressed_text.txt", "w+");
	char * ptrbinar = binar;
	for(int i = 0; i < (strlen(binar)/8); i++)
	{
		char number[] = { ptrbinar[0], ptrbinar[1], ptrbinar[2], ptrbinar[3], ptrbinar[4], ptrbinar[5], ptrbinar[6], ptrbinar[7] };
		unsigned char simbol = (char)atoi(number);
		char str[] = { simbol, '\0' };
		fputc(simbol, write);
		ptrbinar += 8;
	}

	free(binar);
	fclose(write);
	fclose(read);
	deleteTable(tab);

}
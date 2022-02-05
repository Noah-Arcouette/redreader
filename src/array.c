/*
	      _____           ___
	     /  _  \         /  /
	    /  / \  \       /  /
	   /  /___\  \     /  /
	  /  ______\  \   /  /
	 /  /       \  \_/  /
	/__/         \_____/


	This file was made by `makeColorDefs.py` script
	By: Noah Arcouette

*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "array.h"

struct Array* initArray ()
{
	struct Array* a = malloc(sizeof(struct Array));
	a->size = 0;
	a->data = (char**)malloc(0);

	return a;
}

void killArray (struct Array* a)
{
	for (; a->size>0; a->size--)
	{
		free(a->data[a->size-1]);
	}
	free(a->data);

	free(a);
}

void pArray (struct Array* a)
{
	for (size_t i = 0; i<a->size; i++)
	{
		printf(";%s;\n", a->data[i]);
	}
}

void appendArray (struct Array* a, char* item)
{
	a->size++;
	a->data = realloc(a->data, a->size * sizeof(char*));

	a->data[a->size-1] = malloc((strlen(item)+1) * sizeof(char));
	strcpy(a->data[a->size-1], item);
}


int cins (char* s, char c)
{
	for (int i = 0; s[i]!='\0'; i++)
	{
		if (s[i] == c)
		{
			return 1;
		}
	}
	return 0;
}

int sina (struct Array* a, char* s)
{
	for (size_t i = 0; i<a->size; i++)
	{
		if (!strcmp(a->data[i], s))
		{
			return 1;
		}
	}
	return 0;
}

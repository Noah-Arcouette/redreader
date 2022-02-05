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
#ifndef __ARRAY_H__
#define __ARRAY_H__

struct Array
{
	size_t size;
	char** data;
};
typedef struct Array* strarr;

struct Array* 	initArray 	();
void 		killArray 	(struct Array*);
void 		pArray 		(struct Array*);
void 		appendArray 	(struct Array*, char*);

int cins (char*, char);
int sina (strarr, char*);

#endif

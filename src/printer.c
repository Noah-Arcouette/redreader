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
#include "main.h"

#define ITEM tokens->data[i]

void printer (strarr tokens)
{
	strarr keywords = initArray();
	strarr types = initArray();


	appendArray(types, "void");
	appendArray(types, "char");
	appendArray(types, "int");
	appendArray(types, "float");
	appendArray(types, "double");
	appendArray(types, "short");
	appendArray(types, "long");
	appendArray(types, "const");
	appendArray(types, "register");
	appendArray(types, "uint");
	appendArray(types, "uint8_t");
	appendArray(types, "uint16_t");
	appendArray(types, "uint32_t");
	appendArray(types, "uint64_t");
	appendArray(types, "size_t");
	appendArray(types, "ssize_t");
	appendArray(types, "struct");

	appendArray(keywords, "return");
	appendArray(keywords, "for");
	appendArray(keywords, "while");
	appendArray(keywords, "if");
	appendArray(keywords, "else");
	appendArray(keywords, "switch");
	appendArray(keywords, "case");
	appendArray(keywords, "goto");
	appendArray(keywords, "default");
	appendArray(keywords, "break");
	appendArray(keywords, "continue");
	appendArray(keywords, "typedef");

	// C++
	appendArray(types, "class");
	appendArray(types, "vector");
	appendArray(types, "Vector");
	appendArray(types, "true");
	appendArray(types, "false");
	appendArray(types, "this");

	appendArray(keywords, "public");
	appendArray(keywords, "private");
	appendArray(keywords, "protected");
	appendArray(keywords, "catch");
	appendArray(keywords, "try");

	// python
	appendArray(types, "def");
	appendArray(types, "True");
	appendArray(types, "False");
	appendArray(types, "not");
	appendArray(types, "and");
	appendArray(types, "or");
	appendArray(types, "self");

	appendArray(keywords, "in");
	appendArray(keywords, "elif");
	appendArray(keywords, "except");
	appendArray(keywords, "import");
	appendArray(keywords, "global");
	appendArray(keywords, "assert");
	appendArray(keywords, "len");


	for (size_t i = 0; i<tokens->size; i++)
	{
		if (cins("`'\"", ITEM[0]))
		{
			printf("%s", C_STRING);
		}
		else if (cins(SINGLES, ITEM[0]))
		{
			printf("%s", C_SINGLE);
		}
		else if (cins(OPS, ITEM[0]))
		{
			printf("%s", C_OP);
		}
		else if (cins("0123456789", ITEM[0]))
		{
			printf("%s", C_NUMS);
		}
		else if (sina(keywords, ITEM))
		{
			printf("%s", C_KEYWORD);
		}
		else if (sina(types, ITEM))
		{
			printf("%s", C_TYPE);
		}
		else
		{
			printf("%s", C_DEF);
		}

		printf("%s%s%s",
			CBOLD, 
			ITEM,
			CRES
		);
	}

	// pArray(tokens);

	killArray(keywords);
	killArray(types);
}
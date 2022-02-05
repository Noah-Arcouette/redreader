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
#include "token.h"
#include "printer.h"
#include "settings.h"
#include "reader.h"
#include "main.h"


int main (const int argc, const char** argv)
{
	#ifdef _WIN32
		system("color");
	#endif

	Settings* s = gset(argc, argv);

	if (!s->error)
	{
		char* data = reader(s);

		if (!s->error)
		{
			strarr tokens = tokenizer(data);

			// pArray(tokens);
			printer(tokens);

			killArray(tokens);
		}

		free(data);
	}

	free(s->input);
	free(s);

	printf("%s", CRES);

	return 0;
}

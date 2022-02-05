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
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "array.h"

#define SPLITS ".,<>()[]{}!~$%^&*=+-/|:?;\n\t "

strarr tokenizer (char* data)
{
	strarr tokens = initArray();

	size_t csz = 1;
	char* current = malloc(csz * sizeof(char));
	current[0] = 0;

	register uint8_t str = 0;

	register char opener;

	char hold[2] = { 0, '\0' };

	for (size_t i = 0; data[i]!='\0'; i++)
	{
		if (cins("\"'`", data[i]) && !str && data[i-1] != '\\')
		{
			if (current[0] != '\0')
				appendArray(tokens, current);

			csz = 1;
			current = realloc(current, 1 * sizeof(char));
			current[0] = 0;

			opener = data[i];
			str = !str;
		}
		else if (str && data[i] == opener && data[i-1] != '\\')
		{
			str = !str;
		}

		if (cins(SPLITS, data[i]) && !str)
		{
			if (current[0] != '\0')
				appendArray(tokens, current);

			hold[0] = data[i];
			appendArray(tokens, (char*)&hold);

			csz = 1;
			current = realloc(current, 1 * sizeof(char));
			current[0] = 0;

			continue;
		}

		csz++;
		current = realloc(current, csz * sizeof(char));
		strncat(current, &data[i], 1);

		// printf("%s\n", current);
	}

	appendArray(tokens, current);

	free(current);

	return tokens;
}
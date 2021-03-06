/*
	      _____           ___
	     /  _  \         /  /
	    /  / \  \       /  /
	   /  /___\  \     /  /
	  /  ______\  \   /  /
	 /  /       \  \_/  /
	/__/         \_____/


	This file was made for a Noah Arcouette product.
	https://github.com/Noah-Arcouette

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "settings.h"
#include "reader.h"
#include "main.h"

char* reader (Settings* s)
{
	size_t datasz = 1;
	char* data = malloc(datasz * sizeof(char));
	data[0] = 0;

	char* line = NULL;
	size_t len;

	FILE* fp = fopen(s->input, "r");

	if (fp == NULL)
	{
		s->error = 1;

		printf("%s%sError: %sFile `%s' cannot be opened.\n",
			CBOLD,
			C_ERROR,
			C_DEF,
			s->input
		);

		free(line);
		free(data);

		return NULL;
	}

	while ((getline(&line, &len, fp)) != -1)
	{
		datasz += len;

		data = realloc(data, datasz * sizeof(char));
		strcat(data, line);
	}

	free(line);

	fclose(fp);

	return data;
}

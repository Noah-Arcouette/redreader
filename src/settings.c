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
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#include "settings.h"
#include "main.h"

Settings* gset (const int argc, const char** argv)
{
	Settings* s = malloc(sizeof(Settings));
	s->error = 0;

	#ifndef _WIN32
		s->input = malloc(11 * sizeof(char));
		strcpy(s->input, "/dev/stdin");
	#else
		s->input = malloc(1 * sizeof(char));
		s->input[0] = 0;
	#endif

	register uint8_t kill = 0;

	for (int i = 1; (i<argc && !kill); i++)
	{
		if (argv[i][0] == '-')
		{
			switch (argv[i][1])
			{
				// case 'h':
				// 	s->input = realloc(s->input, (strlen(HELP)+1) * sizeof(char));
				// 	strcpy(s->input, HELP);

				// 	kill = 1;

				// 	break;

				default:
					s->error = 1;

					kill = 1;

					printf("%s%sError: %sUnknown option `%s'.\n",
						CBOLD,
						C_ERROR,
						C_DEF,
						argv[i]
					);

					break;
			}
		}
		else
		{
			s->input = realloc(s->input, strlen(argv[i])+1);
			strcpy(s->input, argv[i]);
		}
	}

	return s;
}

/*
 * checklist.c
 *
 *  Created on: 06-Mar-2017
 *      Author: rahul
 */
#include<stdio.h>
#include<string.h>

int bsearch(char **, char *, int, int);
extern int checklist();

int checklist(char **list, char *)
{
	int pos;
	if ((pos = bsearch(list, word, 0, 10)) < 0)
		return 0;
	else
	{	if (strcmp(list[pos], word) == 0)
			return 1;
		else
			return 0;
	}
}


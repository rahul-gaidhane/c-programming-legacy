/*
 * diff.c
 *
 *  Created on: 28-Mar-2017
 *      Author: rahul
 */
#include<stdio.h>
#include<string.h>
#define MAXSIZE 10

//extern void diff();

void diff(FILE *ptr1, FILE *ptr2)
{
	char line1[MAXSIZE];
	int value;
	char line2[MAXSIZE];

	while((fgets(line1, MAXSIZE, ptr1) != NULL) && (fgets(line2, MAXSIZE, ptr2) != NULL))
	{
		if((value = strcmp(line1, line2)) < 0 || value > 0)
		{
			fputs(line1, stdout);
			fputs(line2, stdout);
		}
	}
}


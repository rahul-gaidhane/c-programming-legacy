/*
 * main.c
 *
 *  Created on: 22-Mar-2017
 *      Author: rahul
 */
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int main(int argc, char **argv)
{
	char *p,c ;
	p =(char *)malloc(strlen(argv[0]+1));
	strcpy(p, argv[0]); 
	while(!isalpha(*p))
		p++;
	printf("%s", p);
	if(strcmp(p, "tolower") == 0)
		while((c = getchar()) != EOF)
			putchar(tolower(c));
	else if (strcmp(p, "toupper") == 0)
		while((c = getchar()) != EOF)
			putchar(toupper(c));
	else
		printf("\nERROR");
	return 0;
}

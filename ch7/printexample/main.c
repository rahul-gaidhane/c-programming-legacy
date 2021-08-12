/*
 * main.c
 *
 *  Created on: 24-Mar-2017
 *      Author: rahul
 */
/* CAT */
#include<stdio.h>

int main(int argc, char **argv)
{
	FILE *fp;
	void filecopy(FILE *, FILE *);

	if(argc == 1)
		filecopy(stdin, stdout);
	else
	{
		while(argc > 1)
		{
			fp = fopen(*++argv, "r");
			filecopy(fp, stdout);
		}
		fclose(fp);
	}
	return 0;
}

void filecopy(FILE *ifp, FILE *ofp)
{
	char c;
	while((c = getc(ifp)) != EOF)
		putc(c, ofp);
}

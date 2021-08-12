/* getline */
extern int mygetline(char [], int);
#include<stdio.h>
int mygetline(char line[], int maxlength)
{
	int i;
	char c;
        for (i = 0; i < (maxlength-1) && (c = getchar()) != EOF && c != '\n';)
		line[i++] = c;
	if (c == '\n')
		line[i] = '\n';
	return i;
}	  	




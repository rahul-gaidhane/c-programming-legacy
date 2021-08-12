/* getline */
extern int mygetline(char [], int);
#include<stdio.h>
int mygetline(char line[], int maxlength)
{
	int i;
	char c;
        for (i = 0; i < (maxlength-1) && (c = getchar()) != EOF && c != '\n';)
		line[i++] = c;
	line[i] = '\0';
//	printf("in getline : %s\n", line);
	return i;
}	  	




#include<stdio.h>
extern int mygetline();
int mygetline(char line[], int maxlength)
{
        char c;
        int i;

        for(i = 0; i < maxlength-1 && (c = getchar()) != EOF && c != '\n'; i++)
                line[i] = c;
        if (c == '\n')
                line[i++] = c;
        line[i] = '\0';
	return i;
}


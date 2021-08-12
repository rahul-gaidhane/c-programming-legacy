#include<string.h>
#include<stdio.h>
#define MAXLINE 100
#define BUFSIZE 2000

int mygetline(char [], int);
int myreadline(char *lineptr[], int maxline)
{
	int len, nline;
	char *p, line[MAXLINE], *allocp, alloc[BUFSIZE];
	
	nline = 0;
	allocp = alloc;

	while ((len = mygetline(line, MAXLINE)) > 0)
	{
		if (nline >= maxline-1 || (alloc + BUFSIZE - allocp) <= len)
			return -1;
		else
		{	line[len-1] = '\0';
			p = allocp;
			strcpy(p, line);
			lineptr[nline++] = p;
			allocp = allocp + len;
		}
	}
	return nline;
}	

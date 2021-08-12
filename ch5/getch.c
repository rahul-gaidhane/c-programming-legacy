#include<stdio.h>
#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = -1;

char getch(void)
{
	return (bufp > -1) ? buf[bufp--] : getchar();
}

void ungetch(char c)
{
	if (bufp > BUFSIZE)
		printf("stack is full");
	else
		buf[++bufp] = c;
}

#include<stdio.h>
#include"calc.h"
#define BUFSIZE 100

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; 	/* next free position in buf */

int getch(void) /* get a character */
{
	printf("getch used\n");
	return (bufp > 0)? buf[--bufp]: getchar();
}

void ungetch(int c) /* push character back on input */
{
	printf("ungetch used *%c*\n",c);	
	if (bufp >= BUFSIZE)
		printf("ungetch: too many charcters \n");
	else
		buf[bufp++] = c;
}

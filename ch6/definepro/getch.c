/*
 * getch.c
 *
 *  Created on: 09-Mar-2017
 *      Author: rahul
 */
#include<stdio.h>
#define SIZE 100

char buffer[SIZE];	//stores char returned by ungetch()
int buffptr = 0;	//points to next free space

extern char getch(void);
extern void ungetch(char);

char getch(void)
{
	return (buffptr > 0)?buffer[--buffptr]:getchar();
}

void ungetch(char c)
{
	buffer[buffptr++] = c;
}

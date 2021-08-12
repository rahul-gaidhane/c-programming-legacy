/*
 * getword.c
 *
 *  Created on: 06-Mar-2017
 *      Author: rahul
 */
#include<stdio.h>
extern int getword();
char getch(void);	//gets a char
void ungetch(char);	// ungets a char
int getword(char *word, int max)
{
	char c;
	while(isspace(c = getch()))
		;
	if (c != EOF)
		*word++ = c;
	if(!isalpha(c))
		*word = '\0';
		return c;
	for (; --max > 0; word++)
	{
		*word = getch();
		if (!isalnum(*word))
		{
			ungetch(*word);
			break;
		}
	}
	*word = '\0';
	return word[0];
}


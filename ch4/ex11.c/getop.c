#include<stdio.h>
#include<ctype.h>
#include"calc.h"
int getop(char s[])
{
	int i;
	static int c;
	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '.' && c != '-')
		return c;
	i = 0; 
	if (c == '-')
	{
		if (isdigit(s[++i] = c = getch())) 
			;
		else 
		{
			/*if (c != EOF)
				ungetch(c);*/
			return s[0];
		}
	}	
		
	
	if (isdigit(c)) /* collect integer part */
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.') 	/* collect fraction part */
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	/*if (c != EOF)
		ungetch(c);*/
	return NUMBER;
}


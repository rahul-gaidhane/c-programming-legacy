extern int getword();
#include<stdio.h>
#include<ctype.h>

int getword(char *word; int max)
{
	char c, *w;
	*w = word;

	while(isspace(c = getchar()))
		;	
	if (!isalpha(c))
	{
	//	*w++ = c;
	//	*w = '\0';
		return c;
	}
	for(; --max > 0; w++)
	{	*w = c; 
		if(!isalnum(c = getchar()))
	//		ungetch(c);
			break;
	}
	*w = '\0';
	return c;
}

	


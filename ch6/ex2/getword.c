extern int getword();
#include<stdio.h>
#include<ctype.h>

int getword(char *word; int max)
{
	char c, *w;
	*w = word;

	while(isspace(c = getchar()))
		;
	if (c != EOF)
		*w++ = c;	
	if (!isalpha(c))
	{	
		*w = '\0';
		return c;
	}
	for(; --max > 0; w++)
	{ 
		if(!isalnum(c = getchar()))
			break;
		*w = c;
	}
	*w = '\0';
	return c;
}

	


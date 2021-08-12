/* Program to remove comments from program */

#include<stdio.h>
#define MAXSIZE 2000	/* maximum size of program */ 

int main()
{
	char array1[MAXSIZE];
	char c;
	int pattern, i, k, j, a, b;

	for (i = 0; (c = getchar()) != EOF; i++) array1[i] = c;

	array1[i] = '\0';

	for(i = 0; array1[i] != '\0'; i++)
	{ 
		pattern = 0;
		
		if (array1[i] == '/')
		{	
			if (array1[i + 1] == '/') pattern = 11;		/* there is one line comment */
			
 			if (array1[i + 1] == '*') pattern = 10;		/* there is multi line comment */
		}
		
		if (pattern == 11)	/* instead of comment an '\n' is printed passing control to next line */
		{
			for (j = (i + 2); array1[j] != '\n'; j++)
				;
			for (k = i; k < j; k++) array1[k] = ' ';
			
			array1[i] = '\n';
			continue;
		}
		
		else if (pattern == 10)	
		{
			for (j = (i + 2); array1[j] != '*'; j++)
				;
			if (array1[j] == '*')
			{	
				if (array1[j+1] == '/')
				{
					for (k = i; k <= (j+1); k++) array1[k] = ' ';
				}
			}
			for (a = i, b = (j +1 ); array1[b] != '\n'; a++,b++) 
			{
				array1[a] = array1[b];
				array1[b] = ' '; 
			}
			if (array1[b] == '\n') array1[b] = '\n';
			 
			continue;
		}
		printf("%c",array1[i]);
	}
}
				
				

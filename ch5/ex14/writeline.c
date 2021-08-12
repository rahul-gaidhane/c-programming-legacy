#include<stdio.h>

extern void mywriteline();
void mywriteline(char *lineptr[], int nline)
{
	while (nline-- > 0)
	{
		printf("%s\n",*lineptr++);
	} 
}
	
	
	

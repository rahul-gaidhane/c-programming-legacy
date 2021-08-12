#include<stdio.h>
#include<string.h>
#define MAXSIZE 1000
extern void inputlines();

int mygetline(char [], int);
char *alloc(int);

void inputlines(char *array[], int maxlines)
{
	int len, no_of_lines;
	char line[MAXSIZE], *p;
	
	no_of_lines = 0;
	
	while(no_of_lines < maxlines-1 && (len = mygetline(line, MAXSIZE)) > 0)
	{
		if((p = alloc(len)) == NULL)
		{
			array[no_of_lines] = p;
			return;
		}
		else
		{
			strcpy(p, line);
			array[no_of_lines++] = p;
		}
	}
	array[no_of_lines] = NULL;
}
		
		
			
		

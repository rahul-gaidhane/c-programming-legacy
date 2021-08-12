#include<stdio.h>
extern void printlines();

void printlines(char *array[] , int lines)
{
	int i = 0;
	while(*array != NULL)
		++array;
	while (i < lines)
	{
		--array;
		i++;
	}
	while(*array != NULL)
	{
		printf("%s\n", *array);
		array++;
	}
}	
	

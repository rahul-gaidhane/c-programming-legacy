#include<stdio.h>
#define SIZE 10000
char array[SIZE];
char *parray;
parray = array;
extern char *alloc(int);

char *alloc(int len)
{
	if ((array + SIZE - parray) >= len)
	{
		parray += len;
		return (parray - len);
	}
	else
	{
		printf("array not available");
	}
} 	

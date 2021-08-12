#include<stdio.h>
#define ALLOCSIZE 10000
extern char *alloc();

char *alloc(int len)
{
	char ar_alloc[ALLOCSIZE];
	char *ptr_alloc;
	
	ptr_alloc = ar_alloc;
	if ((ar_alloc + ALLOCSIZE - ptr_alloc) > len)
	{
		ptr_alloc += len;
		return ptr_alloc-len; 
	}
	else
		return NULL;
}	

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
extern void quicksort();
extern int numcmp();
void quicksort(void *lineptr[], int left, int right, int (*comp)(void *, void *))
{
	int i, last;	
	void swap(void *[], int, int);
	
	if (left >= right)
		return;
	swap(lineptr, left, (right + left)/2);
	last = left;
	for (i = left+1; i <= right; i++)
		if ((*comp)(lineptr[i], lineptr[left]) < 0)
			swap(lineptr, ++last, i);
	swap(lineptr, left, last);
	quicksort(lineptr, left, last-1, comp);
	quicksort(lineptr, last+1, right, comp);
}

void swap(void *lineptr[], int i, int j)
{
	void *temp;
	temp = lineptr[i];
	lineptr[i] = lineptr[j];
	lineptr[j] = temp;
}

int numcmp(char *s, char *t)
{
	double num1, num2;
	num1 = atof(s);
	num2 = atof(t);
	if(num1 < num2)
		return -1;
	else if (num1 > num2)
		return 1;
	else
		return 0;
}		

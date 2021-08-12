/* pointer array */
#include<time.h>
#include<stdio.h>
#include<string.h>
#define MAXLINE 5000

int ureadlines(char *[], int maxlines);
void quicksort(char *[], int, int);
void uwritelines(char *[], int nlines);
void main()
{	clock_t start,end;
	start = clock();
	int nlines;
	char *lineptr[MAXLINE];
	
	if((nlines = ureadlines(lineptr, MAXLINE)) > 0)
	{
		quicksort(lineptr, 0, nlines-1);
		uwritelines(lineptr, nlines);
	}
	else
		printf("error occured");
	end = clock();
	printf("\ntime : %f",(double)(end - start));
}

#define MAXLEN 50
#define BUFSIZE 2000
int mygetline(char [], int);
int ureadlines(char *lineptr[], int maxline)
{
	int len, nline;
	char *p, line[MAXLEN];
	char *allocp;// pointer to next free location
	char alloc[BUFSIZE];// entire array
	nline = 0;
	allocp = alloc;

	while ((len = mygetline(line, MAXLEN)) > 0)
	{
		if (nline >= MAXLINE || (alloc + BUFSIZE - allocp) <= len)
			return -1;
		else
		{
			p = allocp;
			//printf("p=%p",p); 
			strcpy(p, line);
			//printf(" line=%s\n",line);
			lineptr[nline++] = p;
			allocp = allocp + len;
		}
	}
	return nline;
}

/* quicksort : sort strings in alphabetical order */
void quicksort(char *lineptr[], int left, int right)
{
	int i, last;	
	void swap(char *[], int, int);
	
	if (left >= right)
		return;
	swap(lineptr, left, (right + left)/2);
	last = left;
	for (i = left+1; i <= right; i++)
		if (strcmp(lineptr[i], lineptr[left]) < 0)
			swap(lineptr, ++last, i);
	swap(lineptr, left, last);
	quicksort(lineptr, left, last-1);
	quicksort(lineptr, last+1, right);
}

/* swap: interchange lineptr[i] and lineptr[j] */
void swap(char *lineptr[], int i, int j)
{
	char *temp;
	temp = lineptr[i];
	lineptr[i] = lineptr[j];
	lineptr[j] = temp;
}
	
/* writeline : print all the lines */
void uwritelines(char *lineptr[], int nline)
{
	int i;
	for (i = 0; i < nline; i++)
	{
		printf("%s\n", lineptr[i]);
	}
//	printf("%s\n",lineptr[0]);
}
	
	
	

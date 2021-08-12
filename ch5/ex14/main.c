#include<stdio.h>
#include<string.h>
#define MAXLINE 5000
int myreadline(char *[], int maxlines);
void quicksort(void *[], int, int, int (*)(void *, void *));
void mywriteline(char *[], int nlines);
int numcmp(char *, char *);
void main(int argc, char *argv[])
{
	int nlines, numeric = 0;
	char *lineptr[MAXLINE];
	
	if (argc > 1 && argv[1] == "-n")
		numeric = 1;
	if((nlines = myreadline(lineptr, MAXLINE)) > 0)
	{
		quicksort((void **)lineptr, 0, nlines-1,(int (*)(void*, void*))(numeric ? numcmp : strcmp));
		mywriteline(lineptr, nlines);
	}
	else
		printf("error occured");
}

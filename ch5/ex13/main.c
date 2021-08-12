/* tail */
/* 10.02.2017 5:39 pm to */

#include<stdio.h>
#include<stdlib.h>
#define MAXLINES 1000
void inputlines(char *[], int);
void printlines(char *[], int);

void main(int argc, char *argv[])
{
	char *array[MAXLINES];
	int lines;

	if ( (*++argv)[0] == '-')
		lines = -(atoi(*argv));
	else
		lines = 10;
		
	inputlines(array,MAXLINES);
	printlines(array, lines);
}	

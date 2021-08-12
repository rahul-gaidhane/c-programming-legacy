/* */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXWORD 100

char *noise[] = {"a","all","and","by","for","in","into","it","its","of","on","that","the"}; 
int getword(char *, int);
int mybsearch(char *[], char *, int left, int right); //returns pos
char *alloc(int);//len of word is passed,pointer to empty array is returned

struct node
{
	char *word;
	int *linenos;
	struct node *left;
	struct node *right;
};

void main()
{
	char word[MAXWORD];
	char *p;
  	int len;	
	while((len = getword(word, MAXWORD)) > 0)
	{
		p = alloc(len + 1)
		strcpy(p, word);
		printf("word is %s ",p);
		printf("bsearch result %d\n",mybsearch(noise,p,0,12));
	}
}

int getword(char *word, int max)
{
	char c;
	int i = 0;
	while((c = getchar()) != EOF && c != '\n')
	{
		*word++ = c;
		i++;
	} 
	return i;
}

int mybsearch(char *list[], char *word, int left, int right)
{
	int low, mid, high, value;

	low = left;
	high = right;
	
	while(low <= high)
	{
		mid = (low + high)/2;
		if ((value = strcmp(word, list[mid])) > 0)
			low = mid + 1;
		else if(value < 0)
			high = mid - 1;
		else
	}
	return -1;
}			
	

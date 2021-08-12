/* */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXWORD 100

char *noise[] = {"a","all","and","by","for","in","into","it","its","of","on","that","the"}; 
int getword(char *, int);
int mybsearch(char *[], char *, int left, int right); //returns pos
struct node *tree(struct node *, char *); 

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
	
	while(getword(word, MAXWORD) > 0)
	{
		printf("word is %s ", word);
		printf("bsearch result %d\n",mybsearch(noise,word,0,12));
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
			return mid;
	}
	return -1;
}

struct node *tree(struct node *p, char *w)
{
	int value;

	if (p == NULL)
	{
		p = (struct node *) malloc(sizeof(struct node));
		p->word = strcpy(p->word, w);
		p->left = p->right = NULL;
	}
	else if((value = strcmp(w, p->word)) < 0)
		p->left = tree(p->left, w);
	else if ((value > 0)
		p->right = tree(p->right, w);
	return p;
}		 
			
	

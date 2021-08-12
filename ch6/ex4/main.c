/* find occurence of words and print in descending order */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define MAXWORD 100

struct node 
{
	char *word;
	int count;
	struct node *left;
	struct node *right;
};

struct node *addtree(struct node *, char *);
char getword(char *, int);
void ptree(struct node *);
char *strcopy(char *);

void main()
{
	char word[MAXWORD];
	struct node *root;
	
	root = NULL;
	
	while(getword(word, MAXWORD) != EOF)
	{//	printf("%s\n", word);
		if(isalpha(word[0]))
			root = addtree(root, word);
	}
	ptree(root);
}

struct node *addtree(struct node *p, char *w)
{
	int value;
	
	if(p == NULL)
	{	
	 	p = (struct node *)malloc(sizeof(struct node));
		p->word = strcopy(w);
		p->count = 1;
		p->left = p->right = NULL;
	}
	else if ((value = strcmp(w, p->word)) == 0)
		p->count++;
	else if (value < 0)
		p->left = addtree(p->left, w);
	else 
 		p->right = addtree(p->right, w);
}

char getword(char *word, int max)
{
	char c, *w;
	w = word;

	while(isspace(c = getchar()))
		;
	if (c != EOF)
		*w++ = c;
	if (!isalpha(c))
		*w = '\0';
		return c;
	for(;--max > 0; )
	{
		if(!isalnum(*w++ = getchar()))
			break;
	}
	*w = '\0';
	return word[0];
/*	char c, *w;
	w = word;
	
	while((c != getchar()) != EOF || c != '\n')
		*w++ = c;
	*w = '\0';	*/
}

void ptree(struct node *p)
{
	if (p != NULL)
	{
		ptree(p->right);
		printf("%d %s\n", p->count, p->word);
		ptree(p->left); 
	}
}

char *strcopy(char *w)
{
	char *p;
	p = (char *)malloc(strlen(w) + 1);
	if (p != NULL)
		strcpy(p,w);
	return p;
}

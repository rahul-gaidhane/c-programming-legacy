/* TO FIND OCCURENCES OF WORDS IN INPUT */
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAXWORD 100

struct tnode 
{	char *w;
	int count;
	struct tnode *left;
	struct tnode *right;
}

struct tnode *addnode(struct tnode *, char *);
int getword(char *, int);
void pnodes(struct tnode *);
	
void main()
{
	char word[MAXWORD];
	struct tnode *root;

	while (getword(word, MAXWORD) != EOF)
		if (isalpha(word[0])) 
			root = addnode(root, word);
	pnodes(root);
}

struct tnode *talloc(void);
void strcopy(struct tnode *, char *);

struct tnode *addnode(struct tnode *p , char *word)
{
	if (p == NULL)
	{ 	
		strcopy(p->w,word);
		p->count = 1;
		p->left = p->right = NULL;
	}
	

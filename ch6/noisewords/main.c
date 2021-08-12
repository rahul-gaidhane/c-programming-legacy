/*
 * main.c
 *
 *  Created on: 06-Mar-2017
 *      Author: rahul
 */
#include<stdio.h>
#define MAXWORD 100
#define MAXLINE 10

char *noise[] = {"a","all","char","define","friend","guest","hello","red","yellow","zing"}; //noise words
struct node
{
		char *word;		// pointer to word
		struct node *left;	//pointer to left child
		struct node *right;	//pointer to right child
	//  int lineno[MAXLINE];	//array storing line_no
	//	int lineptr = 0;		//pointer to line_no array
};

int getword(char *, int);	//string and maxlength is passed
int bsearch(char **, char *, int, int);
struct node *addtree(struct node *, char *);
void print_tree(struct node *);
int checklist(char **, char *, );

void main()
{
	char word[MAXWORD];
	struct node *root;

	while(getword(word, MAXWORD) != EOF)
	{
		if (word[0] == '\n')
			lineno++;
		if (isalpha(word[0]))
		{
			if(checklist(noise, word))	//if word is not in list of noise word
			{
				root = addtree(root, word);
			}

		}
	}
	print_tree(root);
}

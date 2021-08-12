/*
 * addtree.c
 *
 *  Created on: 06-Mar-2017
 *      Author: rahul
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node
{
		char *word;		// pointer to word
		struct node *left;	//pointer to left child
		struct node *right;	//pointer to right child
	//	int lineno[MAXLINE];	//array storing line_no
	//	int lineptr = 0;		//pointer to line_no array
};
extern struct node *addtree();

struct node *addtree(struct node *ptr, char *word/*, int lineno*/)
{
	if (ptr == NULL)
	{
		ptr = (struct node *)malloc(sizeof(struct node));
		strcpy(ptr->word, word);
		ptr->left = ptr->right = NULL;
	}
	else if (strcmp(word, ptr->word) < 0)
			ptr->left = addtree(ptr->left, word);
	else if(strcmp(word, ptr->word) > 0)
			ptr->right = addtree(ptr->right, word);
	return ptr;
}


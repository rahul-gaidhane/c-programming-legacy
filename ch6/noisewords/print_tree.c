/*
 * print_tree.c
 *
 *  Created on: 06-Mar-2017
 *      Author: rahul
 */
#include<stdio.h>
struct node
{
		char *word;		// pointer to word
		struct node *left;	//pointer to left child
		struct node *right;	//pointer to right child
	int lineno[MAXLINE];	//array storing line_no
		int lineptr = 0;		//pointer to line_no array
};
void print_tree(struct node *ptr)
{
	if (ptr != NULL)
	{
			print_tree(ptr->left);
			printf("word is %s\n", ptr->word);
			print_tree(ptr->right);
	}
}

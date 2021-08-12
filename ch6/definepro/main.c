/*
 * main.c
 *
 *  Created on: 09-Mar-2017
 *      Author: rahul
 */
/***/
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include"myheader.h"
#define MAXWORD 100

char getword(char *, int);
void multicomment(void);
void singlecomment(void);
void string(void);
void preprocessor(hashptr);
void mygettext(char *, int);

int main()
{
	char c, word[MAXWORD];
	hashptr ptr = NULL;

	while((c = getword(word, MAXWORD)) != EOF)
	{
	 if (isalpha(c))
	 {
		 if ((ptr = lookup(word)) == NULL)
			 printf("%s",word);
		 else
			 printf("%s",ptr->text);	//each function takes care of spaces
	 }
	 else
	 {
		switch(c)
		{
			case '#': printf("%c",c);
			  	      preprocessor(ptr);
			  	      break;
			case '/': printf("%c",c);
					  if ((c = getch()) == '*')
					  {
						  printf("%c",c);
		 	  	  	      multicomment();
					  }
					  else if (c == '/')
			  		  {
						  printf("%c",c);
						  singlecomment();
			  		  }
					  else
						  printf("/");
					  break;
			case '"': printf("%c",c);
			  	  	  string();
			  	  	  break;
			default	: printf("%c",c);
		}
	}
   }
}

char getword(char *word, int max)
{
	char c;
	int i = 0;
	while(isspace(c = getch()))
		printf("%c",c);
	if (c != EOF)
		word[i++] = c;
	if (!isalpha(c))
	{	if ( c == EOF)
			return EOF;
		word[i] = '\0';
		return word[0];
	}
	for (;--max; i++)
	{
		c = getch();
		word[i] = c;
		if(!isalnum(c) && c != '_')
		{	ungetch(c);
			word[i] = '\0';
		}
	}
	return word[0];
}

void preprocessor(hashptr ptr)
{
	char c;
	char word[MAXWORD], name[MAXWORD], text[MAXWORD];
	getword(word, MAXWORD);
	printf("%s", word);
	if (strcmp(word, "define") == 0)
	{
		getword(name, MAXWORD);
		printf("|%s|", name);
		mygettext(text, MAXWORD);
		printf("|%s|", text);
		ptr = addlink(name, text);
	}
	else
	{
		while((c = getword(word, MAXWORD)) != '>')
			printf("%s", word);	//use getword instead
		if (c == '>')
			printf(">");
	}

}

void singlecomment(void)
{
	char c;
	while((c = getch()) != '\n')
		printf("%c", c);
	if (c == '\n')
		printf("%c",c);
	return;
}


void multicomment(void)
{
	char c;
	while ((c = getch()))
	{
		printf("%c",c);
		if (c == '*')
		{	if ((c = getch()) == '/')
			{	printf("/");
				return;
			}
			else
				ungetch(c);
		}
	}

}

void string(void)
{
	char c;
	while((c = getch()) != '"')
	{
		printf("%c",c);
		if (c == '\\')
		{
			c = getch();
			if (c == '"')
				printf("%c",c);
			else
				ungetch(c);
		}
	}
	printf("%c",c);
}

void mygettext(char *word, int max)
{
	char c;
	int i = 0;

	while(isspace(c = getch()))
		;
	word[i++] = c;
	while((c = getch()) != '\n')
		word[i++] = c;
	if ( c == '\n')
	{	ungetch(c);
		word[i] = '\0';
	}
}
